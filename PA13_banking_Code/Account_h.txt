//
//  Account.h
//  PA13_banking
//
//  Created by Celine Wang on 11/28/23.
//

#ifndef Account_h
#define Account_h

#include <string>
using std::string;

class Account {
protected:
    string name;
    string title;
    string ssn;
//    double balance;
//    double interest_rate;
private:
    int customer_id;

public:
    double balance;
    double interest_rate;
    double divident;
    Account (int customer_id = 0, string name = "", string title = "", string ssn = "", double balance = 0, double interest_rate = 0, double divident = 0);

    int get_id() const { return customer_id; }
    void set_interest_rate(double);
    
    void set_name(string);
    string get_name() const { return name; }
    
    void set_title(string);
    string get_title() const { return title; }
    
    void set_ssn(string);
    string get_ssn() const { return ssn; }
    
    double calculate_interest();
    
    static void display_menu();
    static void display_activity_menu();
    
    // virtual function
    virtual void deposit(double);
    virtual void withdraw(double) ;
    virtual string get_description() const;
};

#endif /* Account_h */
