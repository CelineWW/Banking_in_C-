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
4. [Virtual Functions](#virtual_functions)
   * [Virtual Functions in Account](#virtual_functions_in_account)
   * [Virtual Functions in Checking](#virtual_functions_in_checking)
   * [Virtual Functions in Saving](#virtual_functions_in_saving)
5. [Other Functions](other_functions)
   * [Other Functions in Checking](#other_functions_in_checking)
6. [Sample Run](sample_run)
7. [Summary](#summary)

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

## Other Functions
### Other Functions in Checking
-   void write_check(double check_amount);
```
    void write_check(double check_amount) {
        if (balance < check_amount){
            balance -= 15.00;   // bounced check fee $15
            set_check_bounced(1);
            cout << "\nAn error occured: check bounced (not enough funds).\n";
            cout << "\nA fee of $15 has been charged for bounced check.\n";
        }
        else if (get_check_count() == 0 && balance >= check_amount){
            balance -= check_amount;
        }

        else if (get_check_count() > 0 && balance >= check_amount + 0.10){
            balance -= (check_amount + 0.10);    // check fee $0.1
            cout << "\nA fee of $0.10 has been charged for writing a check.\n";
        }
        set_check_count(1);
        cout << "Deducted successfully from Checking!\n";
        cout << "You have written " << get_check_count() << "check(s).\n";
        cout << "Checking balance: $" << balance << endl;
    }
```

## Sample Run
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
1. When customer register their information. There is a checking account and a saving account created automatically. To improve the program, we can add more checking account and saving account objects for the user. 
2. Credit account can be the third kind of parallel account.
3. Interest is caculated once this option is chosen from the menu. The most closest occasion to real banking should import time to automatically update the interest on the background.

