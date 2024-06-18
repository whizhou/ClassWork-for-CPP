class Calculator {
    public:
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        if (abs(b) < 1e-12)
            throw "Division by zero!";
        return a / b;
    }
};  