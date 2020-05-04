# Team Project - CS 240

Andrei Georgescu

Xavier Chen

Eun Hyeok Jang

## Aim

The aims of this application are as follows:

- To create a self-contained banking application.
- To allow for account management on the top level
- To allow for money management on the user level

## Requirements

- Bank

  - Container class that stores ***Account*** records
  - Expected to scale well with a large amount of accounts
    - Should hold as many accounts as possible
  - *Procedures*
    - **Add Account** is in O(n) in the worst case
      - Should take a reasonable amount of time
      - Minimum of $100 deposit.
    - **Delete Account** is in O(n^2) in the worst case
      - Can take a long time; not critical
    - **Find Account** is in O(n) in the worst case
      - Should take a reasonable amount of time
    - **Transfer Money** is in O(n) in the worst case
      - Should take a reasonable amount of time
    - ***Get Balance** is in O(1) in the worst case
      - Should be immediate
    - **Deposit Money** is in O(1) in the worst case
      - Should be immediate
    - **Withdraw Money** is in O(1) in the worst case
      - Should be immediate

- Account

  - Record object

  - Not expected to scale well with a large amount of money

    - Customers are willing to wait longer for large transactions since they tend to require bank intervention anyway.
    - Number doesn't need to be too large (2^{32} bits should be fine)

  - Contains unique ID number

  - *Procedures*

    - **Get Balance** is in O(1) in the worst case
      - Should be immediate
    - **Get Account Number** is in O(1) in the worst case
      - Should be immediate
    - **Deposit Money** is in O(1) in the worst case
      - Should be immediate
    - **Withdraw Money** is in O(1) in the worst case
      - Should be immediate

## Results

***performance numbers as either tables or graphs.***
### Size
- *Account* (size_t (8 bytes) + int (4 bytes) + padding (4 bytes) = *16 bytes*)
- *Account Node* (Account (16 bytes) + Pointer (8 bytes) = *24 bytes*)
- *Bank Overhead (Linked List) (3 Pointers (8 bytes * 4 = 24 bytes) + int (4 bytes) + padding (4 bytes) + 2 Helper Nodes (2 * 24 bytes) = *80 bytes*
