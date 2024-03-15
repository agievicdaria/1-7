#pragma once

class Money {
private:
    long hryvnia;
    unsigned char kopiyky;

public:
    Money();
    Money(long hryvnia, unsigned char kopiyky);

    long GetHryvnia() const { return hryvnia; }
    unsigned char GetKopiyky() const { return kopiyky; }
    void SetHryvnia(long value) { hryvnia = value; }
    void SetKopiyky(unsigned char value) { kopiyky = value; }

    Money Add(const Money& secondValue) const;
    Money Subtract(const Money& secondValue) const;
    Money DivideInt(int divisor) const;
    Money DivideDouble(double divisor) const;
    Money Multiply(double multiplier) const;

    bool IsEqual(const Money& secondValue) const;
    bool IsLessThan(const Money& secondValue) const;
    bool IsGreaterThan(const Money& secondValue) const;

    void Display() const;
};
 