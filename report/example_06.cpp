#include <iostream>
#include <string>
#include <stdio.h>

class Complex;

class Tester {
public:
	double testfunc(Complex& c);
};

class Complex {
private:
	double real, imag;

	friend Complex operator+(const Complex& lhs, const Complex& rhs);
	friend bool operator<(const Complex& lhs, const Complex& rhs);

	friend double Tester::testfunc(Complex &c);

public:
	Complex() :real(0.0), imag(0.0) {}
	Complex(double v):real(v), imag(0.0) {}
	Complex(double r, double i):real(r), imag(i) {}
	Complex(const Complex& c):real(c.real),imag(c.imag) {}

	Complex& operator = (const Complex& c) {
		real = c.real, imag = c.imag;
		return *this;
	}
	Complex operator+() const { return *this; }
	Complex operator-() const { return Complex(-real, -imag); }

	double& operator[](int i) {
		printf("no const\n");
		return i == 0 ? real : imag;
	}

	const double& operator[](int i) const {
		printf("const\n");
		return i == 0 ? real : imag;
	}

	void show(std::string sz_prefiex) {
		printf("[%s] real : %f, imag : %lf\n", sz_prefiex.c_str(), real, imag);
	}
};

double Tester::testfunc(Complex& c) {
	printf("[Tester] %lf, %lf\n", c.real, c.imag);
	return c.real;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
}

bool operator<(const Complex& lhs, const Complex& rhs) {
	return lhs.real < rhs.real && lhs.imag < rhs.imag;
}

int Test() {
	Complex a(11.0, 2.0), b(2.0, 5.0), c;
	const Complex cc(33.0, 11.0);
	Tester t;
	int n = 0;

	// overloading test
	a[n];
	cc[1];

	c = a + b;
	c.show("c = a + b");
	(a + b).show("(a + b)");
	
	// friend test
	t.testfunc(a);

	return 0;
}

int main() {
	Test();

	return 0;
}