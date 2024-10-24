#include <string.h>

#define CHAR_SET_SIZE 256

int firstUniqChar(char* s) {
    int count[CHAR_SET_SIZE] = {0};
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        count[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < length; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return i;
        }
    }

    return -1;
}
