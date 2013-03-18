//Charnita Peoples,417-21-0455
//Jose Ramon Alonso, 000-07-1217
//Amos Newsome III, 422-06-3360
//CS124-03
//Project 2
//A class that performs numerical computations for complex numbers.

#include <iostream>
#include <cmath>
#include "project2.h"
   using namespace std;

   Complex::Complex()   {
      real = 1; imag = 1;}                          // constructor

   Complex::Set(int a, int b) {
      real = a; imag = b;}        		// sets the value of the complex number

   Complex::Print(void) {
      cout << "  " << real;
      if (imag<0)
         cout << imag << "i" << endl;
      else
         cout << "+" << imag << "i" << endl;  }

   Complex::AddTo(const Complex& s){
      real += s.real;								// adds the real part of the complex number
      imag += s.imag;								//adds the imaginary part of the complex number
   }

   Complex::SubFrom(const Complex& d){
      real=real-d.real;						// substracts the real parts 
      imag=imag-d.imag;						//substracts the imaginary parts
   }

   Complex::MultiplyBy(const Complex& d){
      real=(real*d.real)-(imag*d.imag);	//calculates the real part of the complex number when multiplying
      imag=(real*d.imag)+(imag*d.real);	//calculates the imaginary part of the complex number when multiplying
   }

   Complex::DivideBy(const Complex& d) {	
      real=(real*d.real + imag*d.imag)/(pow(d.real,2)+pow(d.imag,2));	//calculates the real part of the complex number when dividing
      imag=(imag*d.real + real*d.imag)/(pow(d.real,2)+pow(d.imag,2));	//calculates the imaginary part of the complex number when dividing
   }

   Complex::Dot(const Complex& d){
      return (real*d.real+imag*d.imag);	//calculates the dot product of two complex numbers
   }

   Complex::Cross(const Complex& d) {
      return (real*d.imag-imag*d.real);	//calculates the cross product of two complex numbers
   }

   Complex::Equals(const Complex&)
   
   {      
      if((real==next.real)&&(imag==next.imag))//checks to see if the two complex numbers are equal
         return 1;
      else
         return 0;
   
   
   }


   Complex::Modulus(void) { 
   
      return sqrt(pow(real,2)+pow(imag,2)); } 	// finds the modulus of a complex number


   Complex::Complex ComplexConjugate(void){
      Complex conjugate;					
      conjugate.real = real;
      conjugate.imag = -imag;	//returns the complex conjugate
      return conjugate;
   }        





