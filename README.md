# Banking

Table of Contents
1. [Overview](#overview)
2. [Class](#class)
   * [Account Class](#account)
   * [Checking Class](#checking)
   * [Saving Class](#saving)
3. [Static Functions](#static_functions)
   * [Static Functions in Account](#static_functions_in_account)
   * [Static Functions in Checking](#static_functions_in_checking)
   * [Static Functions in Saving](#static_functions_in_saving)   
4. [Virtual Functions](#vitual_functions)
   * [Account](#vitual_functions_in_account)
   * [Checking](#vitual_functions_in_checking)
   * [Saving](#vitual_functions_in_saving)
4. [Summary](#summary)

## Overview

This program create a superclass *Account* and subclass *Checking* and *Saving* to allow customer to create *Checking* and *Saving* account with a unique ID. *Checking* and *Saving* account can do transctions independently and interactively. Transctions includes withdraw, deposit, settle interest, check balance, and transfer between accounts. *Checking* and *Saving* account both have their own restrictions.


## Class
### Account
![9_2.png](https://github.com/CelineWW/Banking_in_CPP/blob/main/PA13_banking_Run/9_2.png)

- Five general types of banking transactions for both accounts, Checking and Savings: 
    - withdraw
    - deposit
    - calculate interest 
    - balance
    - transfer funds (between the two accounts, from Checking to Savings and vice versa).

```
class Account {
protected:
    string name;
    string title;
    string ssn;
private:
    int customer_id;
public:
    double balance;
    double interest_rate;
    double divident;
    Account (int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0, double divident = 0);
    < -------- member functions here ------>
};
```
### Checking
![9_3.png](https://github.com/CelineWW/Banking_in_CPP/blob/main/PA13_banking_Run/9_3.png)
-   Checking restrictions:
    -   A monthly service charge is $5 (automatically charged when the Checking
    account was opened).
    -   10 cents are charged for each written check, but not for the first check, which is free. A $15 charge for each bounced check (not enough funds).
    - The monthly interest rate is 2.5% based on the current balance, no new interest if not modified.

```
class Checking : public Account {
private:
    int check_count;
    int check_bounced;
public:
    // Checking constructor
    Checking(int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0.025, double divident = 0, int check_count_param = 0, int check_bounced_param = 0) :
        Account(customer_id, name, title, ssn, balance, interest_rate, divident){
            check_count = check_count_param; check_bounced = check_bounced_param;
    }
    < -------- member functions here ------>
};
```
### Saving
![9_4.png](https://github.com/CelineWW/Banking_in_CPP/blob/main/PA13_banking_Run/9_4.png)
- Savings restrictions:
    - Become inactive if the balance falls less than $25, and under such a situation, no more withdrawals may be allowed.
    - A $1 charge for each transfer fund (to the Checking account), but not for the first transfer, which is free.
    - The monthly interest rate is 3.75% based on the current balance, no new interest if not modified.

```
class Savings : public Account {
private:
    int transfer_count;
    
public:
    // Savings constructor
    Savings(int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0.0375, double divident = 0, int transfer_count_param = 0) :
        Account(customer_id, name, title, ssn, balance, interest_rate, divident){
        transfer_count = transfer_count_param;
    }
    < -------- member functions here ------>
};
```


## Static Functions
### Static Functions in Account 
-   static void display_menu();
-   static void display_activity_menu();
### Static Functions in Checking
-   static void display_activity_menu();
### Static Functions in Saving
-   static void display_activity_menu();
```   
   static void display_activity_menu() {
        cout << endl << endl;
        cout << "---------------------------------------------------------------------------\n\n";
        cout << "                            *** Savings ***                                \n";
        Account::display_activity_menu();
    }
```

## Virtual Functions
Some of member functions are inheritance and virtual functions.
### Virtual Functions in Account 
-   virtual string get_description() const;
-   virtual void withdraw(double);
-   virtual void deposit(double);

### Virtual Functions in Checking
-   string get_description() const override{...}
```
    string Account::get_description() const {
        return "\n>ID: " + to_string(customer_id) + "\n>Name: " + name +
        + "\n>Title: " + title + "\n>SSN: " + ssn + "\nBalance: " + to_string(balance) + "\nDivident: " + to_string(divident);
    }
```
-   void withdraw(double withdraw_amount) override{...}
-   void deposit(double deposit_amount) override {...}

```
    string get_description() const override{
        return  "\n>Checking Status" + Account::get_description() + "\nChecks written: " + to_string(check_count) + "\nCheck Bounced: " + to_string(check_bounced) ;
    };
```
### Virtual Functions in Saving
-   void withdraw(double withdraw_amount) override {...}
```
    void withdraw(double withdraw_amount) override {
        if (balance > 25.00 && balance >= withdraw_amount){
            balance -= withdraw_amount;
            cout << "Deducted successfully from Savings!\n";
            cout << "Savings balance: $" << balance << endl;
        }
        else if (balance > 25.00 && balance < withdraw_amount){
            cout << "An error occured: low balance.\n";
        }
        else
            cout<< "An error occured: the account is inactive.\n";
    }
```
-   void deposit(double deposit_amount) override {...}




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

