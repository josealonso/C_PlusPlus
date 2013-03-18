 
///////////////////// Author: Jose Ramon Alonso ////////////// 
//////////////////// CS124, Project #3 //////////////////////// 
 
 # include <iostream> 
 using namespace std; 
 
 class Matrix { 
 private: 
 int rows; 
 int cols; 
 int sample [10][10]; // static memory allocation 
 public: 
 Matrix() 
 { // default constructor 
 rows =10; cols =10; 
 for (int i=0; i<rows; i++) 
 { 
 for (int j=0; j<cols; j++) 
 sample [i][j] = 0; // Initialize a new matrix to all 0s 
 } 
 } 
 Matrix(int r, int c) // constructor sets the # of rows and cols 
 { 
 rows = r; cols = c; 
 for (int i=0; i<rows; i++) 
 { 
 for (int j=0; j<cols; j++) 
 sample [i][j] = 0; 
 } 
 } 
 Matrix(const Matrix& M) // copy constructor 
 { 
 rows = M.rows; 
 cols = M.cols; 
 for (int i=0; i< M.rows; i++) 
 { 
 for (int j=0; j< M.cols; j++) 
 sample [i][j] = M.sample [i][j]; 
 } 
 } 
 void Set(int r, int c) // sets the number of rows and cols 
 { 
 rows = r; cols = c; 
 } 
 void SetElem(int r, int c, int e) // sets the element e at (r,c) 
 { 
 //rows = r; cols = c; NO!!!!!! 
 sample [r][c] = e; 
 } 
 
 int GetElem(int r, int c) // returns the element at (r,c) 
 { 
 return sample [r][c]; 
 } 
 
 friend Matrix operator+ ( const Matrix& M1, const Matrix& M2); 
 // returns the sum of two matrices if the dimensions allow 
 
 friend Matrix operator- (const Matrix& M1, const Matrix& M2); 
 // returns the difference (M1 M2) if the dimensions allow 
 
 friend Matrix Negative (const Matrix& M); 
 // used inside the "operator -" function 
 
 friend Matrix operator* (const Matrix& M1, const Matrix& M2); 
 // returns the product (M1*M2) if the dimensions allow 
 
 friend Matrix operator* (const Matrix& M1, int S); 
 // performs a scalar multiplcation (S*M1) 
 
 friend bool operator== (const Matrix& M1, const Matrix& M2); 
 // checks to see if the matrices are equal or not 
 
 friend ostream& operator << (ostream &os, const Matrix& M); 
 friend istream& operator >> (istream &is, Matrix& M); 
 }; 
 
 istream& operator >> (istream &is, Matrix& M) 
 { 
 cout << "How many rows? "; cin >> M.rows; 
 cout << "How many columns? "; cin >> M.cols; 
 
 cout << "\nInput the matrix elements separated by an empty space\n"; 
 cout << "(press Enter to input another row):\n"; 
 int element; 
 for (int i = 0; i < (M.rows*M.cols); i++) 
 { 
 is >> element; 
 } 
 return is; 
 } 
 
 ostream& operator <<(ostream &os, const Matrix& M) 
 { 
 for (int i=0; i<M.rows; i++) 
 { 
 os << "Row number " << i << ": "; 
 for (int j=0; j<M.cols; j++) 
 os << M.sample [i][j] << " "; // prints out one matrix 
 os << endl ; 
 } 
 os << endl; 
 return os; 
 } 
 
 Matrix operator* (const Matrix& M1, const Matrix& M2) 
 { 
 Matrix M_multiply; 
 
 if (M1.cols != M2.rows) 
 { 
 cout << "\n The dimensions do not allow to multiply the matrices\n"; 
 return M_multiply; 
 } 
 cout << "\nThe multiplication can be performed and the result is the following:\n"; 
 M_multiply.rows = M1.rows; M_multiply.cols = M2.cols; 
 for (int i=0; i< M_multiply.rows; i++) 
 { 
 for (int j=0; j< M_multiply.cols; j++) 
 { 
 for (int k=0; k< M1.cols; k++) //one element is formed by 
 M_multiply.sample [i][j] += M1.sample [i][k] * M2.sample [k][j]; //M1.cols addittions 
 } 
 } 
 return M_multiply; 
 
 } 
 
 Matrix operator* (const Matrix& M1, int S) 
 { 
 cout << "\nThe scalar multiplication produces the following matrix:\n"; 
 Matrix M_mul; 
 M_mul.rows = M1.rows; M_mul.cols = M1.cols; 
 for (int i=0; i< M1.rows; i++) 
 { 
 for (int j=0; j< M1.cols; j++) 
 M_mul.sample [i][j] = M1.sample [i][j] * S; 
 } 
 return M_mul; 
 } 
 
 Matrix operator+ (const Matrix& M1, const Matrix& M2) 
 { 
 Matrix M_add; 
 
 if ((M1.rows != M2.rows) || (M1.cols != M2.cols)) 
 { 
 cout << "\n The dimensions do not allow to sum the matrices\n"; 
 return M_add; 
 } 
 
 M_add.rows = M1.rows; M_add.cols = M1.cols; 
 cout << "\nThe addittion of the two matrices produces the following\n"; 
 for (int i=0; i< M1.rows; i++) 
 { 
 for (int j=0; j< M1.cols; j++) 
 M_add.sample [i][j] = M1.sample [i][j] + M2.sample [i][j]; 
 } 
 return M_add; 
 
 } 
 
 Matrix operator- (const Matrix& M1, const Matrix& M2) 
 { 
 Matrix M_subs; 
 M_subs = M1 + Negative (M2); 
 return M_subs; 
 } 
 
 Matrix Negative (const Matrix& M) 
 { 
 Matrix M_negative; 
 M_negative.rows = M.rows; M_negative.cols = M.cols; 
 for (int i=0; i< M.rows; i++) 
 { 
 for (int j=0; j< M.cols; j++) 
 M_negative.sample [i][j] = -M.sample [i][j]; 
 } 
 return M_negative; 
 } 
 
 bool operator == (const Matrix& M1, const Matrix& M2) 
 { 
 if ((M1.rows != M2.rows) || (M1.cols != M2.cols)) 
 { 
 cout << "\n The matrices are not equal\n"; 
 return 0; 
 } 
 int flag = 0; //returns 1 if every elements in both matrices are equal 
 for (int i=0; i< M1.rows; i++) 
 { 
 for (int j=0; j< M1.cols; j++) 
 { 
 if (M1.sample [i][j] != M2.sample [i][j]) 
 flag += flag; 
 } 
 } 
 if (flag == 0) 
 { 
 cout << "\nThe matrices are equal\n"; 
 return 1; 
 } 
 return 0; 
 } 
 
