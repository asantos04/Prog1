#include <iostream>

class Fraction {
private:
    int numerator_;
    int denominator_;
    
    // Helper functions
    int gcd(int a, int b);
    void normalise();
    
public:
    // Constructors
    Fraction() : numerator_(0), denominator_(1) {
        // Do nothing
    }
    
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        normalise();
    }
    
    // Accessors
    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }
    
    // Arithmetic operations
    Fraction sum(const Fraction& right) const;
    Fraction sub(const Fraction& right) const;
    Fraction mul(const Fraction& right) const;
    Fraction div(const Fraction& right) const;
    
    // Output
    void write() const {
        std::cout << numerator_ << "/" << denominator_;
    }
};

// Helper functions
int Fraction::gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void Fraction::normalise() {
    if (denominator_ < 0) {
        numerator_ = -numerator_;
        denominator_ = -denominator_;
    }
    int divisor = gcd(abs(numerator_), denominator_);
    numerator_ /= divisor;
    denominator_ /= divisor;
}

// Arithmetic operations
Fraction Fraction::sum(const Fraction& right) const {
    int new_num = numerator_ * right.denominator() + right.numerator() * denominator_;
    int new_den = denominator_ * right.denominator();
    return Fraction(new_num, new_den);
}

Fraction Fraction::sub(const Fraction& right) const {
    int new_num = numerator_ * right.denominator() - right.numerator() * denominator_;
    int new_den = denominator_ * right.denominator();
    return Fraction(new_num, new_den);
}

Fraction Fraction::mul(const Fraction& right) const {
    int new_num = numerator_ * right.numerator();
    int new_den = denominator_ * right.denominator();
    return Fraction(new_num, new_den);
}

Fraction Fraction::div(const Fraction& right) const {
    int new_num = numerator_ * right.denominator();
    int new_den = denominator_ * right.numerator();
    return Fraction(new_num, new_den);
}
