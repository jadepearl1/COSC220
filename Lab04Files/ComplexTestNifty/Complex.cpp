#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
  real = 0;
  imag = 0;
}

Complex::Complex(double r, double i)
{
  real = r;
  imag = i;
}

Complex::Complex(double r)
{
    real = r;
    imag = 0;
}

Complex::~Complex()
{

}

void Complex::setReal(double r)
{
  real = r;
}

double Complex::getReal()
{
  return real;
}

void Complex::setImag(double i)
{
  imag = i;
}

double Complex::getImag()
{
  return imag;
}

void Complex::set(double r, double i)
{
  real = r;
  imag = i;
}

Complex Complex::operator+(const Complex &right)
{
    Complex opPlus;
    opPlus.real = real+right.real;
    opPlus.imag = imag+right.imag;
    return opPlus;
}

Complex Complex::operator+(double num)
{
    Complex opPlus2;
    opPlus2.real = num+real;
    opPlus2.imag = imag;
    return opPlus2;
}

Complex operator+(double num, const Complex &right)
{
    Complex opPlus3;
    opPlus3.real = num+right.real;
    opPlus3.imag = right.imag;
    return opPlus3;
}

Complex Complex::operator-(const Complex &right)
{
    Complex opMinus;
    opMinus.real = real-right.real;
    opMinus.imag = imag-right.imag;
    return opMinus;
}

Complex Complex::operator-(double num)
{
    Complex opMinus2;
    opMinus2.real = real-num;
    opMinus2.imag = imag;
    return opMinus2;
}

Complex operator-(double num, const Complex &right)
{
    Complex opMinus3;
    opMinus3.real = num-right.real;
    opMinus3.imag = 0-right.imag;
    return opMinus3;
}

Complex Complex::operator*(const Complex &right)
{
    Complex opMult;
    opMult.real = (real*right.real)-(imag*right.imag);
    opMult.imag = (imag*right.real)+(real*right.imag);
    return opMult;
}

Complex Complex::operator*(double num)
{
    Complex opMult2;
    opMult2.real = real*num;
    opMult2.imag = imag*num;
    return opMult2;
}

Complex operator*(double num, const Complex &right)
{
    Complex opMult3;
    opMult3.real = num*right.real;
    opMult3.imag = num*right.imag;
    return opMult3;
}

Complex Complex::operator/(const Complex &right)
{
    Complex opDiv;
    opDiv.real = (real*right.real + imag*right.imag)/(pow(right.real,2) + pow(right.imag,2));
    opDiv.imag = ((imag*right.real)-(real*right.imag))/(pow(right.real,2)+pow(right.imag,2));
    return opDiv;
}

Complex Complex::operator/(double num)
{
    Complex opDiv2;
    opDiv2.real = (((real*num)+(real*0))/(pow(num,2)+pow(0,2)));
    opDiv2.imag = ((imag*num)-(real*0))/(pow(num,2)+pow(0,2));
    return opDiv2;
}

Complex operator/(double num, const Complex &right)
{
    Complex opDiv3;
    opDiv3.real = (((num*right.real)+(0*right.real))/(pow(right.real,2)+pow(right.imag,2)));
    opDiv3.imag = (((0*right.real)-(num*right.imag))/(pow(right.real,2)+pow(right.imag,2)));
    return opDiv3;
}

void Complex::operator+=(const Complex &right)
{
    real = real + right.real;
    imag = imag + right.imag;
}

void Complex::operator-=(const Complex &right)
{
    real = real-right.real;
    imag = imag-right.imag;
}

Complex Complex::operator^(int a)
{
    Complex expoComp = *this;
    for (int i=1; i<a; i++) {
        expoComp = expoComp * *this;
    }
    return expoComp;
}

bool Complex::operator==(const Complex &right)
{
    return (real==right.real && imag==right.imag);
}

bool Complex::operator!=(const Complex &right)
{
    return (real!=right.real && imag!=right.imag);
}

const Complex Complex::operator=(const Complex &right)
{
    return ((real=right.real) && (imag=right.imag));
}

double Complex::mod()
{
    return sqrt(pow(real,2)+pow(imag,2));
}

ostream &operator<<(ostream &output, const Complex &right)
{
    if (right.real == 0 && right.imag != 0)
    {
        output << right.imag << "i";
    }
    else if (right.imag == 0 && right.real != 0)
    {
        output << right.real;
    }
    else if (right.real == 0 && right.imag == 0)
    {
        output << right.real;
    }
    else
    {
        if (right.real > 0 && right.imag > 0)
            output << right.real << " + " << right.imag << "i";
        else if (right.real > 0 && right.imag < 0)
            output << right.real << " - " << abs(right.imag) << "i";
        else if (right.real < 0 && right.imag < 0)
            output << right.real << " - " << abs(right.imag) << "i";
        else
            output << right.real << " + " << right.imag << "i";
    }
    return output;
}

istream &operator>>(istream &input, Complex &right)
{
    input >> right.real;
    input >> right.imag;
    return input;
}