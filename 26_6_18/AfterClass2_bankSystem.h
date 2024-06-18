#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class BankSystem;

class BankAccount {
    string name;
    int balance;
public:
    BankAccount(const string &name = "", int balance = 0) : name(name), balance(balance) {}
    // BankAccount(const BankAccount &other) : name(other.name), balance(other.balance) {}
    void deposit(int amount) {
        // if (amount < 0)
            // throw "Negative Input";
        balance += amount;
    }
    void withdraw(int amount) {
        if (balance < amount)
            throw runtime_error("Insufficient balance!");
        balance -= amount;
    }
    // int getBalance() { return balance; }
    friend BankSystem;
};

class BankSystem {
    vector<BankAccount> accounts;
public:
    void addAccount(const string& name, int initialBalance) {
        for (auto &account: accounts)
            if (account.name == name)
                throw runtime_error("Account already exists!");
        accounts.push_back(BankAccount(name, initialBalance));
    }
    void removeAccount(const string &name) {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->name == name) {
                accounts.erase(it);
                return;
            }
        }
        throw runtime_error("Account not found!");
    }
    void transfer(const string &fromName, const string &toName, int amount) {
        if (amount < 0)
            throw runtime_error("Invalid transfer amount!");
        decltype(accounts.begin()) fromAccount = accounts.end(), toAccount = accounts.end();
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->name == fromName)
                fromAccount = it;
            if (it->name == toName)
                toAccount = it;
        }
        if (fromAccount == accounts.end() || toAccount == accounts.end())
            throw runtime_error("Account not found!");
        fromAccount->withdraw(amount);
        toAccount->deposit(amount);
    }
    void getBalances() {
        for (const auto &account: accounts)
            cout << account.name << " " << account.balance << endl;
    }
};