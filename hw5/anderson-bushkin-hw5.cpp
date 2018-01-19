#include <iostream>
#include <cmath>
#include <sstream>
#include "Polynomial.h"
using namespace std;

// TODO -- fix negative integers in toString()

////////////////////////////////////////////////////////
// Write your code here: evalAt, toString, and findZeroes

int main(void) {
  double c0[] = {2};
  Polynomial p0(0, c0);

  double c1[] = {3, -5};
  Polynomial p1(1, c1);

  double c2[] = {4, -7, 8};
  Polynomial p2(2, c2);

  double c5[] = {4,-6,12,-23,45,16};
  Polynomial p5(5, c5);

  cout << "==========\n";
  string p0Str;
  p0.toString(p0Str);
  cout << p0Str << " is the polynomial." << endl;
  cout << "At x=3, it is: " << p0.evalAt(3) << endl;

  cout << "==========\n";
  string p1Str;
  p1.toString(p1Str);
  cout << p1Str << " is the polynomial." << endl;
  cout << "At x=3, it is: " << p1.evalAt(3) << endl;

  cout << "==========\n";
  string p2Str;
  p2.toString(p2Str);
  cout << p2Str << " is the polynomial." << endl;
  cout << "At x=3, it is: " << p2.evalAt(3) << endl;

  cout << "==========\n";
  string p5Str;
  p5.toString(p5Str);
  cout << p5Str << " is the polynomial." << endl;
  cout << "At x=3, it is: " << p5.evalAt(3) << endl;

  cout << "==========\n";
  double cAnother[] = {4, -7, 8};
  Polynomial another(2, cAnother);

  string anotherStr;
  another.toString(anotherStr);

  cout << anotherStr << " == " << p5Str << ": " << (another == p5) << endl;
  cout << anotherStr << " != " << p5Str << ": " << (another != p5) << endl;
  cout << anotherStr << " == " << p2Str << ": " << (another == p2) << endl;
  cout << anotherStr << " != " << p2Str << ": " << (another != p2) << endl;

  cout << "==========\n";
  double c6[] = {2, 4, 1};
  Polynomial p6(2, c6);
  string p6Str;
  p6.toString(p6Str);
  cout << p6Str << " is the polynomial." << endl;

  double zeroes[2];
  p6.findZeroes(zeroes);
  cout << "The zeroes are " << zeroes[0] << " and " << zeroes[1] << endl;

  cout << "The degree is " << p6.getDegree() << "." << endl;
  cout << "The coefficient of x^2 is " << p6.getCoeff(2) << "." << endl;
  p6.setCoeff(2, 99);
  p6.toString(p6Str);
  cout << "After changing the coefficient of x^2, it is " << p6.getCoeff(2) << ", and the entire polynomial is " << p6Str << endl;

  return 0;
}
