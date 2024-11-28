#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void create(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_left(struct Node** head, int target_data, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == target_data) {
            new_node->next = temp;
            new_node->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = new_node;
            } else {
                *head = new_node;
            }
            temp->prev = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found.\n", target_data);
}

void delete_node(struct Node** head, int value) {
    struct Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == value) {

            if (temp == *head) {
                *head = temp->next;
            }

            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found.\n", value);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target_data, new_data;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create a node\n");
        printf("2. Insert node to the left of a specific node\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the node to create: ");
                scanf("%d", &data);
                create(&head, data);
                break;

            case 2:
                printf("Enter the target node data before which to insert: ");
                scanf("%d", &target_data);
                printf("Enter the data for the new node to insert: ");
                scanf("%d", &new_data);
                insert_left(&head, target_data, new_data);
                break;

            case 3:
                printf("Enter the data of the node to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;

            case 4:
                printf("The current list is: ");
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
