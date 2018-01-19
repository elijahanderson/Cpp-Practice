#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <string>

class Polynomial {

 private:
  int deg;
  double* coeffs;

 public:
  Polynomial(int deg, double coeffs[]);
  ~Polynomial();
  int getDegree() const;
  double getCoeff(const int deg) const;
  void setCoeff(const int deg, const double nCoeff);
  bool operator==(const Polynomial &other);
  bool operator!=(const Polynomial &other);
  double evalAt(const double val) const;
  void toString(std::string &asString) const;
  bool findZeroes(double zeroes[]) const;  
};

#endif
