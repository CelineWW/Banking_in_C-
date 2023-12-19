# Banking
# List of Employees

Table of Contents
1. [Overview](#overview)
2. [Class](#class)
   * [Account](#account)
   * [Checking](#checking)
   * [Saving](#saving)
2. [Transctions](#class)
   * [Checking](#employee_attributes)
   * [Saving](#employee_class)
4. [Summary](#summary)

## Overview

This program create a superclass *Account* and subclass *Checking* and *Saving* to allow customer to create *Checking* and *Saving* account with a unique ID. *Checking* and *Saving* account can do transctions independently and interactively. Transctions includes withdraw, deposit, settle interest, check balance, and transfer between accounts. *Checking* and *Saving* account both have their own restrictions.

Some of member functions are inheritance and virtual functions.
- Five general types of banking transactions for both accounts, Checking and Savings: 
    - withdraw
    - deposit
    - calculate interest 
    - balance
    - transfer funds (between the two accounts, from Checking to Savings and vice versa).
- Savings restrictions:
    - Become inactive if the balance falls less than $25, and under such a situation, no more withdrawals may be allowed.
    - A $1 charge for each transfer fund (to the Checking account), but not for the first transfer, which is free.
    - The monthly interest rate is 3.75% based on the current balance, no new interest if not modified.
-   Checking restrictions:
    -   A monthly service charge is $5 (automatically charged when the Checking
    account was opened).
    -   10 cents are charged for each written check, but not for the first check, which is free. A $15 charge for each bounced check (not enough funds).
    - The monthly interest rate is 2.5% based on the current balance, no new interest if not modified.

## Class
### Account
### Checking
### Saving


## Transctions
### Checking
### Saving



Each employee has the following attributes:
- ID (integer and unique)
- full name 
    -  first name 
    -  last name
- SSN(last 4 digits)
- wage
- department- 
- date of hire 
    - hire year
    - hire month
    - hire day

![PA15_list_of_employees_RUN_11.png](https://github.com/CelineWW/List_of_Employees/blob/main/PA15_list_of_employees_RUN_11.png)


### Data Validation




### Sample Run
![01.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/01.png)
![02.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/02.png)
![03.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/03.png)
![04.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/04.png)
![05.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/05.png)
![06.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/06.png)
![07.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/07.png)
![08.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/08.png)
![09.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/09.png)
![10.png](https://github.com/CelineWW/CPP_Programming/blob/main/PA13_banking/PA13_banking_Run/10.png)


## Summary
1. This program can easily add, search, edit, delete employee attributes in the list from the external files. However, some details need to be added for advanced usage of the program.
2. Maximum ID currently set as 99. If larger population added, ID has to accept 3 or 4 digit numbers.
3. Hire date accept any number between 1 ~ 31 for any combination of year, month, and day. Day of month (Lunar month - 30 days, Solar month - 31 days, Feburay - 28/29 days) and leap year is not verified. 
4. If the user attend to search employee, they can only search by employee ID. If ID is unknown, they have to display employee list first. This is not friendly to large dataset. Adding more searchin critiria (such as, employee name, hire date) can power up the program.

