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
    - **Get Balance** is in O(1) in the worst case
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
### Time
| Elements (1000)            | Add Account | Delete Account | Find Account | Transfer Money | Get Balance | Deposit Money | Withdraw Money |
|----------------------------|-------------|----------------|--------------|----------------|-------------|---------------|----------------|
| Linked List (Average Case) | 0.002ms     | 0.006ms        | 0.015ms      | 0.013ms        | 0.013ms     | 0.013ms       | 0.013ms        |
| Vector (Average Case)      | 0.002ms     | 0.001ms        | 0.001ms      | 0.001ms        | 0.001ms     | 0.001ms       | 0.001ms        |

| Elements (100,000)         | Add Account | Delete Account | Find Account | Transfer Money | Get Balance | Deposit Money | Withdraw Money |
|----------------------------|-------------|----------------|--------------|----------------|-------------|---------------|----------------|
| Linked List (Average Case) | 0.002ms     | 0.559ms        | 1.315ms      | 2.069ms        | 2.079ms     | 1.336ms       | 1.296ms        |
| Vector (Average Case)      | 0.002ms     | 0.001ms        | 0.001ms      | 0.001ms        | 0.001ms     | 0.001ms       | 0.001ms        |

| Growth Rate                | Add Account | Delete Account | Find Account | Transfer Money | Get Balance | Deposit Money | Withdraw Money |
|----------------------------|-------------|----------------|--------------|----------------|-------------|---------------|----------------|
| Linked List (Average Case) | Θ(1)        | Θ(n)           | Θ(n)         | Θ(n)           | Θ(n)        | Θ(n)          | Θ(n)           |
| Vector (Average Case)      | Θ(1)        | Θ(1)           | Θ(1)         | Θ(1)           | Θ(1)        | Θ(1)          | Θ(1)           |

### Size
- **Account** (size_t (8 bytes) + int (4 bytes) + padding (4 bytes) = **16 bytes**)
- **Account Node** (Account (16 bytes) + Pointer (8 bytes) = **24 bytes**)
- **Bank Overhead (Linked List)** (3 Pointers (8 bytes * 4 = 24 bytes) + int (4 bytes) + padding (4 bytes) + 2 Helper Nodes (2 * 24 bytes) = **80 bytes**
- **Bank Overhead (Vector)** (Pointer (8 bytes) + vector<Account*> (24 bytes) = **32 bytes**)
