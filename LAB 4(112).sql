SELECT branch_name, assets_in_lakhs AS total_assets
FROM branch;

SELECT customer_name
FROM bank_customer
WHERE customer_city = 'Bangalore';

SELECT d.customer_name, d.accno
FROM depositer d
JOIN bank_account b ON d.accno = b.accno;

Select distinct d.customer_name
from depositer d,bank_account ba,branch b
where d.accno=ba.accno and b.branch_name=ba.branch_name and b.branch_city="delhi"
group by d.customer_name having count(b.branch_name)>1;

SELECT d.customer_name
FROM depositer d
JOIN bank_account b ON d.accno = b.accno
WHERE b.balance > 100000;

SELECT branch_name,
       (SELECT COUNT(*)
        FROM bank_account
        WHERE branch_name = b.branch_name) AS account_count
FROM branch b;

SELECT branch_name
FROM branch
WHERE branch_name NOT IN (SELECT branch_name FROM loan);

SELECT branch_name
FROM loan
GROUP BY branch_name
HAVING SUM(amount) = (
    SELECT MIN(total_amount)
    FROM (
        SELECT SUM(amount) AS total_amount
        FROM loan
        GROUP BY branch_name
    ) AS totals
);