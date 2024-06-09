#include <iostream>

class Complex {
  double r, m, mod;

 public:
    Complex() {
      r   = 0.0;
      m   = 0.0;
      mod = 0.0;
    }

    Complex(double x, double y = 0.0) {
      r   = x;
      m   = y;
      mod = 0.0;
    }

    double Modulo();

    double GetRe() {
      return r;
    }

    double GetIm() {
      return m;
    }

    Complex operator+(const Complex &op) {
      return Complex(r + op.r, m + op.m);
    }

    Complex operator=(const Complex &op) {
      r   = op.r;
      m   = op.m;
      mod = op.mod;
      return *this;
    }

    Complex operator+=(const Complex &op) {
      r  += op.r;
      m  += op.m;
      return *this;
    }

    ~Complex() {
      r = m = 0.0;
    }
};

double Complex::Modulo() {
  mod = r*r + m*m;
  return mod;
}

void min_max(int * arr, size_t size, int &min, int &max) {
  min = arr[0];
  max = arr[0];

  for (size_t i = 1; i < size; i++) {
    if (min > arr[i])
      min = arr[i];

    if (max < arr[i])
      max = arr[i];
  }
}

int main(void) {
  Complex x, y(1);

  std::cout << "x + y = " << (x + y).Modulo() << '\n';

  x = x + y;
  std::cout << "x + y mod = " << x.Modulo() << '\n';

  x += y;
  x += 2;

  std::cout << "(x += y) += 2 mod = " << x.Modulo() << '\n';

  y = 5;
  std::cout << "(y = 5) mod = " << y.Modulo() << '\n';

  int array[50];
  int min, max;

  for (size_t i = 0; i < 50; i++) {
    array[i] = i;
  }

  min_max(array, 50, min, max);

  std::cout << "min = " << min << "\nmax = " << max << '\n';

  return 0;
}