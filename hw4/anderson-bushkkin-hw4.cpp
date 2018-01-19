#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

// TODO -- fix negative integers in toString()

////////////////////////////////////////////////////////
// Write your code here: evalAt, toString, and findZeroes

double evalAt(const double coefficients[], int deg, const double val) {
  double returnVal = 0.0;
  for(deg; deg >= 0; deg--) {
    returnVal += coefficients[deg] * pow(val, deg);
  }
  return returnVal;
}

void toString(const double coefficients[], int deg, string &asString) {
  stringstream s;
  for(deg; deg >= 0; deg--) {
    
    if (deg == 0)
      s << coefficients[deg];
    else if (deg == 1 && coefficients[deg] == 0)
      ;
    else if (deg == 1) {
      s << coefficients[deg] << "x" << " + " ;
    }
    else if (deg == 1 && coefficients[deg] == 0)
      ;
    else if (coefficients[deg] != 0) {
      s << coefficients[deg] << "x^" << deg << " + ";
    }
    else 
      ;
  }
  asString = s.str();
}

bool findZeroes(const double coeffs[], int deg, double zeros[]) {
  if (deg >= 3 || deg < 0)
    return false;
  if (deg == 2) {
    zeros[0] = (-(coeffs[deg-1]) + sqrt(coeffs[deg-1]*coeffs[deg-1] - (4 * coeffs[deg] * coeffs[deg-2]))) / (2 * coeffs[deg]);
    zeros[1] = (-(coeffs[deg-1]) - sqrt(coeffs[deg-1]*coeffs[deg-1] - (4 * coeffs[deg] * coeffs[deg-2]))) / (2 * coeffs[deg]);

  }
  else {
    zeros[0] = -(coeffs[deg-1] / coeffs[deg]);
  }
  
  return true;
}


////////////////////////////////////////////////////////
// Don't touch any of the code below at all!
// Write evalAt, toString, and findZeroes such that the code below works correctly.
// If you get an error in the code below, it means something is wrong with one of the
// functions you wrote.

void cubicExample(double coeffs[]) {
  int degree = 3;

  double * zeroes = NULL;
  bool retValue = findZeroes(coeffs, degree, zeroes);
  // We know retValue is false here, indicating that we don't support finding zeroes for
  // cubic equations.

  string asString;
  toString(coeffs, degree, asString);

  cout << "The cubic expression is: " << asString << ". We didn't try to find zeroes." << endl;
  cout << "This polynomial, at x = 2.5, is: " << evalAt(coeffs, degree, 2.5) << endl;
}

void quadraticExample(double coeffs[]) {
  int degree = 2;

  double zeroes[2];
  findZeroes(coeffs, degree, zeroes);

  string asString;
  toString(coeffs, degree, asString);

  cout << asString << " has zeroes " << zeroes[0] << " and " << zeroes[1] << endl;
  cout << "This polynomial, at x = 2.5, is: " << evalAt(coeffs, degree, 2.5) << endl;
}

void linearExample(double coeffs[]) {
  int degree = 1;

  double zeroes[1];
  findZeroes(coeffs, degree, zeroes);

  string asString;
  toString(coeffs, degree, asString);

  cout << asString << " has zero " << zeroes[0] << endl;
  cout << "This polynomial, at x = 2.5, is: " << evalAt(coeffs, degree, 2.5) << endl;
}

int main() {
 
  int degree;
  cout << "========== Cubic ==========" << endl;
  degree = 3;
  double ccoeffs[degree+1] = {0, -5, 0, 12}; // 12x^3 - 5x
  cubicExample(ccoeffs);

  cout << "========== Quadratic ==========" << endl;
  degree = 2;
  double qcoeffs[degree+1] = {1, 0, -8}; // -8x^2 + 1
  quadraticExample(qcoeffs);

  cout << "---------------" << endl;

  double qcoeffs2[degree+1] = {-4, 3, 1}; // x^2 + 3x - 4
  quadraticExample(qcoeffs2);

  cout << "========== Linear ==========" << endl;
  degree = 1;
  double lcoeffs[degree+1] = {5, 2}; // 2x + 5
  linearExample(lcoeffs);
  /*
  double coeffs[] = {1.26, 5, 0, 12, 13};
  cout << evalAt(coeffs, 4, 1) << endl;

  string asString;
  toString(coeffs, 4, asString);

  cout << asString << endl;
  return 0;*/
}
