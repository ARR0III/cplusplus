#include <iostream>
#include <cmath>

using namespace std;

class Complex {
  friend class B;

  private:
    double re, im;

  public:
    Complex(const double c_re = 0.0, const double c_im = 0.0) {
      re = c_re; im = c_im;
    }

    double Modulo() const {
      return sqrt((re * re) + (im * im));
    }

    double argument() const {
      return atan2(im, re);
    }

    double get_re() const {
      return re;
    }

    double get_im() const {
      return im;
    }

    const Complex & operator=(const Complex & a) {
      re = a.re;
      im = a.im;
      return *this;
    }

  friend Complex operator+(const Complex & a, const Complex & b);

    const Complex & operator+=(const Complex & c) {
      re += c.re;
      im += c.im;
      return *this;
    }

    const Complex operator-(const Complex & op) const {
      Complex res(re - op.re, im - op.im);
      return res;
    }

    const Complex operator*(const Complex & op) const {
      Complex res(re * op.re - im * op.im,
                  re * op.im + im * op.re);
      return res;
    }

    const Complex operator/(const Complex & op) const {
      double dvs = op.re * op.re + op.im * op.im;
      Complex res((re * op.re + im * op.im) / dvs,
                  (im * op.re - re * op.im) / dvs);
      return res;
    }

    ~Complex() {
      re = im = 0;
    }
};

class B {
  Complex a;

  double x, y;

  public:
    B() : a(6.6, 9.9) {
      x = a.re;
      y = a.im;
    }

    double F(double z = 0.5) {
      return x + y + z;
    }
};

Complex operator+(const Complex & a, const Complex & b) {
  return Complex(a.re + b.re,
                 a.im + b.im);
}

int main (int argc, char * argv[]) {

  Complex r, z, t(9.1, 12.6); // t.re = 9.1; t.im = 12.6;

  z = t + 0.5; // z.re = 9.1 + 0.5; z.im = 12.6 + 0.0; == 9.6, 12,6
  z = 0.6 + t; // z.re = 0.6 + 9.1; z.im = 0.0 + 12.6; == 9.7, 12,6 

  r += t;
  r += z += t;

  cout << r.get_re() << "\t" << r.get_im() << "\n";
  cout << z.get_re() << "\t" << z.get_im() << "\n";
  cout << t.get_re() << "\t" << t.get_im() << "\n";

  r = z;

  cout << r.get_re() << "\t" << r.get_im() << "\n"; 

  B g;

  cout << g.F() << "\n";
  cout << g.F(10.5) << "\n";

  return 0;
}

