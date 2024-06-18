class BankAccount {
    int balance;
public:
    BankAccount(int a = 0) : balance(a) {}
    void deposit(int amount) {
        if (amount < 0)
            throw "Negative Input";
        balance += amount;
    }
    void withdraw(int amount) {
        if (balance < amount)
            throw "Insufficient account balance";
        balance -= amount;
    }
    int getBalance() { return balance; }
};