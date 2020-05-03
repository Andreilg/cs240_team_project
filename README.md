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

- Account Database

  - Container class that stores ***Account*** records
  - Expected to scale well with a large amount of accounts
    - Should hold as many accounts as possible
  - *Procedures*
    - **Get Account Number** is in $O(1)$ in the worst case
      - Should be immediate
    - **Add Account** is in $O(n)$ in the worst case
      - Should take a reasonable amount of time
      - Minimum of $100 deposit.
    - **Delete Account** is in $O(n^2)$ in the worst case
      - Can take a long time; not critical
    - **Transfer Money** is in $O(n)$ in the worst case
      - Should take a reasonable amount of time

- Account

  - Record object

  - Not expected to scale well with a large amount of money

    - Customers are willing to wait longer for large transactions since they tend to require bank intervention anyway.
    - Number doesn't need to be too large ($2^{32}$ bits should be fine)

  - Contains unique ID number

  - *Procedures*

    - **Get Balance** is in $O(1)$ in the worst case
      - Should be immediate
    - **Get Account Number** is in $O(1)$ in the worst case
      - Should be immediate
    - **Deposit Money** is in $O(1)$ in the worst case
      - Should be immediate
    - **Withdraw Money** is in $O(1)$ in the worst case
      - Should be immediate

## Results

***performance numbers as either tables or graphs.***
