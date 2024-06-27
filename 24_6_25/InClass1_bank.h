#include <stdexcept>

class BankAccount {
    double balance;
public:
    BankAccount(double balance=10.0) : balance(balance) {}

    void deposit(double amount) {
        if (amount < 0)
            throw std::invalid_argument("Deposit amount must be positive!");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0)
            throw std::invalid_argument("Withdrawal amount must be positive!");
        if (amount > balance)
            throw std::runtime_error("Insufficient funds!");
        
        balance -= amount;
    }
};