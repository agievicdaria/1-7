#include "Money.h"
#include <iostream>

Money::Money() {
    hryvnia = 0;
    kopiyky = 0;
}

Money::Money(long hryvnia, unsigned char kopiyky) {
    this->hryvnia = hryvnia;
    this->kopiyky = kopiyky;
}


Money Money::Add(const Money& secondValue) const {
    long totalHryvnia = hryvnia + secondValue.hryvnia;
    int totalKopiyky = kopiyky + secondValue.kopiyky;

    if (totalKopiyky >= 100) {
        totalHryvnia += totalKopiyky / 100;
        totalKopiyky %= 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::Subtract(const Money& secondValue) const {
    long totalHryvnia = hryvnia - secondValue.hryvnia;
    int totalKopiyky = kopiyky - secondValue.kopiyky;

    if (totalKopiyky < 0) {
        totalHryvnia -= 1;
        totalKopiyky += 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::DivideInt(int divisor) const {
    long totalHryvnia = hryvnia / divisor;
    int totalKopiyky = (hryvnia % divisor) * 100 / divisor + kopiyky / divisor;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::DivideDouble(double divisor) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) / divisor;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::Multiply(double multiplier) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) * multiplier;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

bool Money::IsEqual(const Money& secondValue) const {
    return hryvnia == secondValue.hryvnia && kopiyky == secondValue.kopiyky;
}

bool Money::IsLessThan(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky < secondValue.kopiyky;
    }
    return hryvnia < secondValue.hryvnia;
}

bool Money::IsGreaterThan(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky > secondValue.kopiyky;
    }
    return hryvnia > secondValue.hryvnia;
}

void Money::Display() const {
    std::cout << hryvnia << "," << static_cast<int>(kopiyky);
}

