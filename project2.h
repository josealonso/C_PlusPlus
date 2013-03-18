//Charnita Peoples,417-21-0455
//Jose Ramon Alonso, 000-07-1217
//Amos Newsome III, 422-06-3360
//CS124-03
//Project 2
//A class that performs numerical computations for complex numbers.

#include <iostream>
#include <cmath>
#ifndef Complex
#define Complex


   class Complex {
      double real, imag;  					// variables for the real and imaginary part of the complex number
   public:
      Complex();                          // constructor
      void Set(int a, int b);             // sets the value of the complex number
      void Print(void);                   // prints complex number using syntax "A + Bi"
                                        // if B is positive and "A - Bi" if B is negative
      void AddTo(const Complex&);         // adds the parameter to the current complex number
      void SubFrom(const Complex&);       // subtracts the parameter from the current complex number
      void MultiplyBy(const Complex&);    // multiplies the current complex number by the parameter
      void DivideBy(const Complex&);      // divides the current complex number by the parameter
      bool Equals(const Complex&);        // returns whether the current complex number is
                                        // equivalent to the parameter
      float Dot(const Complex&);          // returns the dot product of the current complex
                                        // number and the parameter
      float Cross(const Complex&);        // returns the cross product of the current complex
                                        // number and the parameter
      float Modulus(void);                // returns the modulus of the current complex number
      Complex ComplexConjugate(void);     // returns the complex conjugate of the current
                                        // complex number
   };

	#endif
	
