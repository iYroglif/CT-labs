#include "pch.h"
#include <iostream>
#include <cassert>

using namespace std;

long int Nod(long int a, long int b)
{
	while (a != 0 && b != 0)
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	return a + b;
}

class fraction {
private:

	short sign;

	long int numerator;

	long int denominater;

public:

	short getSign() {
		return sign;
	}

	long int getNum() {
		return numerator;
	}

	long int getDenom() {
		return denominater;
	}

	fraction() :sign(1), numerator(0), denominater(1) {}

	fraction(const fraction &frac) :sign(frac.sign), numerator(frac.numerator), denominater(frac.denominater) {}

	fraction(int currentNum) {
		if (currentNum >= 0) {
			sign = 1;
		}
		else {
			sign = -1;
			currentNum = -1 * currentNum;
		}
		numerator = int(currentNum);
		denominater = 1;
	}

	fraction(double currentNum) {
		long int nod;
		if (currentNum >= 0) {
			sign = 1;
		}
		else {
			sign = -1;
			currentNum = -1 * currentNum;
		}
		numerator = long int(currentNum * 100000);
		denominater = 100000;
		nod = Nod(numerator, denominater);
		numerator = numerator / nod;
		denominater = denominater / nod;
	}

	fraction(int currentNum, int currentDenom) {
		assert(currentDenom != 0);
		long int nod;
		if (currentNum >= 0) {
			sign = 1;
		}
		else {
			sign = -1;
			currentNum = -1 * currentNum;
		}
		if (currentDenom < 0) {
			sign = -1 * sign;
			currentDenom = -1 * currentDenom;
		}
		nod = Nod(currentNum, currentDenom);
		numerator = int(currentNum) / nod;
		denominater = int(currentDenom) / nod;
	}

	fraction(double currentNum, int currentDenom) {
		assert(currentDenom != 0);
		long int nod;
		if (currentNum >= 0) {
			sign = 1;
		}
		else {
			sign = -1;
			currentNum = -1 * currentNum;
		}
		if (currentDenom < 0) {
			sign = -1 * sign;
			currentDenom = -1 * currentDenom;
		}
		numerator = long int(currentNum * 100000);
		denominater = 100000 * int(currentDenom);
		nod = Nod(numerator, denominater);
		numerator = numerator / nod;
		denominater = denominater / nod;
	}

	fraction(int ent, int currentNum, int currentDenom) {
		if (ent >= 0) {
			*this = fraction(currentNum + ent * currentDenom, currentDenom);
		}
		else {
			ent = -1 * ent;
			*this = fraction(-(currentNum + ent * currentDenom), currentDenom);
		}
	}

	fraction(int ent, double currentNum, int currentDenom) {
		if (ent >= 0) {
			fraction(currentNum + ent * currentDenom, currentDenom);
		}
		else {
			ent = -1 * ent;
			fraction(-(currentNum + ent * currentDenom), currentDenom);
		}
	}

	friend std::istream& operator>> (std::istream &in, fraction &frac);

	fraction operator-() {
		sign = -1 * sign;
		return *this;
	}

	fraction operator+() {
		return *this;
	}

	explicit operator double() {
		return double(numerator) / denominater;
	}

	explicit operator int() {
		return int(numerator / denominater);
	}

	explicit operator long int() {
		return numerator / denominater;
	}

	fraction& operator= (const fraction &frac) {
		if (this == &frac) {
			return *this;
		}
		sign = frac.sign;
		numerator = frac.numerator;
		denominater = frac.denominater;
		return *this;
	}

	fraction operator+ (fraction frac) {
		return fraction(this->sign * frac.sign * (this->numerator*frac.denominater + frac.numerator*this->denominater), this->denominater*frac.denominater);
	}

	fraction operator+ (int val) {
		return fraction(this->sign * (this->numerator + val * this->denominater), this->denominater);
	}

	fraction operator+ (double val) {
		return fraction(this->sign * (this->numerator + val * this->denominater), this->denominater);
	}

	fraction operator* (fraction &frac) {
		return fraction(this->sign * frac.sign * this->numerator * frac.numerator, this->denominater * frac.denominater);
	}

	fraction operator* (int val) {
		return fraction(this->sign * this->numerator * val, this->denominater);
	}

	fraction operator* (double val) {
		return fraction(this->sign * this->numerator * val, this->denominater);
	}

	fraction operator- (fraction frac) {
		return *this + (-frac);
	}

	fraction operator- (int val) {
		return *this + (-1 * val);
	}

	fraction operator- (double val) {
		return *this + (-1 * val);
	}

	fraction operator/ (fraction &frac) {
		return fraction(this->sign * frac.sign * this->numerator * frac.denominater, this->denominater * frac.numerator);
	}

	fraction operator/ (int val) {
		return fraction(this->sign * this->numerator, this->denominater*val);
	}

	fraction operator/ (double val) {
		return fraction(this->sign * this->numerator, this->denominater*val);
	}

	fraction operator++ () {
		if ((sign < 0) && (numerator < denominater)) {
			sign = 1;
			numerator = denominater - numerator;
		}
		else {
			numerator = numerator + denominater;
		}
		return *this;
	}

	fraction operator-- () {
		if ((sign > 0) && (numerator < denominater)) {
			sign = -1;
			numerator = denominater - numerator;
		}
		else {
			numerator = numerator + denominater;
		}
		return *this;
	}

	fraction operator++ (int) {
		fraction temp = *this;
		++(*this);
		return temp;
	}

	fraction operator-- (int) {
		fraction temp = *this;
		--(*this);
		return temp;
	}

	fraction operator+= (fraction frac) {
		*this = *this + frac;
		return *this;
	}

	fraction operator+= (long int val) {
		*this = *this + val;
		return *this;
	}

	fraction operator+= (int val) {
		*this = *this + val;
		return *this;
	}

	fraction operator+= (double val) {
		*this = *this + val;
		return *this;
	}

	fraction operator-= (fraction frac) {
		*this = *this - frac;
		return *this;
	}

	fraction operator-= (long int val) {
		*this = *this - val;
		return *this;
	}

	fraction operator-= (int val) {
		*this = *this - val;
		return *this;
	}

	fraction operator-= (double val) {
		*this = *this - val;
		return *this;
	}
};

fraction operator+ (int val, fraction frac) {
	return fraction(val * frac.getDenom() + frac.getSign() * frac.getNum(), frac.getDenom());
}

fraction operator+ (double val, fraction &frac) {
	return fraction(val * frac.getDenom() + frac.getSign() * frac.getNum(), frac.getDenom());
}

fraction operator- (int val, fraction frac) {
	return val + (-frac);
}

fraction operator- (double val, fraction frac) {
	return val + (-frac);
}

fraction operator* (int val, fraction &frac) {
	return fraction(frac.getSign() * frac.getNum() * val, frac.getDenom());
}

fraction operator* (double val, fraction &frac) {
	return fraction(frac.getSign() * frac.getNum() * val, frac.getDenom());
}

fraction operator/ (int val, fraction &frac) {
	return fraction(frac.getNum(), frac.getSign() * frac.getDenom() * val);
}

fraction operator/ (double val, fraction &frac) {
	return fraction(frac.getNum(), frac.getSign() * frac.getDenom() * val);
}

std::ostream& operator<< (std::ostream &out, fraction frac) {
	if (frac.getSign() < 0) {
		out << "-";
	}
	if (frac.getDenom() == 1) {
		out << frac.getNum();
	}
	else {
		if (frac.getNum() < frac.getDenom()) {
			out << frac.getNum() << "/" << frac.getDenom();
		}
		else {
			long int temp;
			temp = frac.getNum() / frac.getDenom();
			out << temp << "(" << frac.getNum() - frac.getDenom()*temp << "/" << frac.getDenom() << ")";
		}
	}
	return out;
}

std::istream& operator>> (std::istream &in, fraction &frac)
{
	double currentNum, currentDenom, temp;
	int sym;
	in >> temp;
	sym = in.get();
	if (sym == 10) {
		currentNum = temp;
		currentDenom = 1;
	}
	else {
		if (sym == 47) {
			currentNum = temp;
			in >> currentDenom;
		}
		else {
			if (sym == 40) {
				in >> currentNum;
				in.get();
				in >> currentDenom;
				in.get();
				currentNum = currentNum + temp * currentDenom;
			}
		}
	}
	frac = fraction(currentNum, currentDenom);
	return in;
}

bool operator== (fraction &frac1, fraction &frac2) {
	return ((frac1.getSign() == frac2.getSign()) && (frac1.getDenom() == frac2.getDenom()) && (frac1.getNum() == frac2.getNum()));
}

bool operator!= (fraction &frac1, fraction &frac2) {
	return !(frac1 == frac2);
}

bool operator> (fraction &frac1, fraction &frac2) {
	fraction temp(frac1 - frac2);
	if (temp.getSign() > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

bool operator< (fraction &frac1, fraction &frac2) {
	fraction temp(frac1 - frac2);
	if (temp.getSign() < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

bool operator<= (fraction &frac1, fraction &frac2) {
	return !(frac1 > frac2);
}

bool operator>= (fraction &frac1, fraction &frac2) {
	return !(frac1 < frac2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	fraction a, b(-5), c(-8, 3), d(-2, 2, 3), e(-2.666), f(b);
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
	system("pause");
}