// *************************************************************************
// ************************* CS 124, section 3 - Fall 2002 *****************
// ************************ Project 7, by Jose Ramon Alonso ****************
// ************************ SN: 000-07-1217 ********************************
// *************************************************************************

#include <iostream>

   class VectorDouble {
      double* vector;
      int length;       //indicates the size of the vector
      int length_max;   //indicates the capacity of the vector
   
   public:
      VectorDouble ();                 // default constructor init size 50
      VectorDouble (int fSize);        // constructor sets initial size
      VectorDouble (const VectorDouble& M);  // copy constructor
      ~VectorDouble ();                // destructor
   
      int size() const;      // returns the number of elements in the vector
      int capacity();  // returns the number of elements the vector can hold
      void clear();     // removes all of the elements
   
      bool add(double e);  // appends e to the vector 
      bool remove(double e);  // removes e from the vector 
      bool set(int fElem, double e);  // sets the element e at (fElem)
      bool get(int fElem, double &e);  // retrieves the element at (fElem)
   
      int indexOf (double e);
        // returns the position (1->N) of the first occurrence of e or 0 if not found
      int lastIndexOf (double e); 
        // returns the position (1->N) of the last occurrence of e or 0 if not found
      bool contains (double e);
        // returns whether e is in the vector 
   
      bool isEmpty(); // returns whether the vector is empty 
   
      friend bool operator== (const VectorDouble& V1, const VectorDouble& V2);
    // checks to see if the matrices are equal or not
   
   //    friend VectorDouble operator= (const VectorDouble& V1);
    // assignment operator 
   
      friend VectorDouble operator+ (const VectorDouble& V1, double e);
    // appends e to the vector 
   
      friend VectorDouble operator- (const VectorDouble& V1, double e);
    // removes e from the vector 
   
      friend VectorDouble operator+ (const VectorDouble& V1, const VectorDouble& V2);
    // appends all elements in V2 to V1 
   
      friend VectorDouble operator- (const VectorDouble& V1, const VectorDouble& V1);
    // removes all elements in V2 from V1 
   
      friend ostream& operator<<(ostream&, const VectorDouble&); 
      friend istream& operator>>(istream&, VectorDouble&);                                                 
   };

//********************************* DEFINITION ****************************************

   VectorDouble::VectorDouble ()                 // default constructor init size 50
   {
      vector = new double(50);
      length_max = 50;
      length = 0;              // initially, the size is zero
      for (int k = 0; k < length_max; k++)
         vector[k] = 0;
   }

   VectorDouble::VectorDouble (int fSize)        // second constructor sets initial size
   {
      vector = new double(fSize);
      length_max = fSize;
      length = 0;
      for (int k = 0; k < length_max; k++)
         vector[k] = 0;
   }

   VectorDouble::VectorDouble (const VectorDouble& M)  // copy constructor
   {
      length = M.length;
      length_max = M.length_max;
      int s = M.size();
      vector = new double(s);
      for (int k = 0; k < length_max; k++)
         vector[k] = 0;
      for (int i=0; i < s; i++)
         vector[i] = M.vector[i];
   }   
   VectorDouble::~VectorDouble ()                // destructor
   {
      //delete[];
   }

   int VectorDouble::size() const     // returns the number of elements in the vector
   {
      return length;
   }
   int VectorDouble::capacity()  // returns the number of elements the vector can hold
   {
      return length_max;
   }
   void VectorDouble::clear()     // removes all of the elements
   {
      for (int i=0; i < size(); i++)
         vector[i] = 0;
      length = 0;       // size equals to 0
   }
   bool VectorDouble::add(double e)  //appends e to the vector 
   {
   
     // If the vector is filled, the capacity should be doubled, new space of that size should be allocated, all
     // existing elements should be copied into the new space, and the old space should be removed. 
   
      if (length == length_max)
      {
         double* temp = new double(length*2);
      // double* vector = new double(length_max*2);
         int i;
         for (i = 0; i < length; i++)
            temp[i] = vector[i];        //all existing elements are copied by using a temporary pointer
         length_max = length_max * 2;
         delete vector;                 // the old space is removed
      
         temp[length++] = e;   
      }  
      if (length < length_max)
         vector[length++] = e;
   
      return 1;
   }
   bool VectorDouble::remove(double e)  // removes e from the vector 
   {
      if (indexOf(e) == 0)
         return 0;             // the element e does not exist
      else
      {
         int i; // = indexOf(e);
         for (i = indexOf(e); i < (length -1); i++)// if e exists, al the other elements after e
            vector[i] = vector[i+1];               // are moved back one position into the vector   
         length--;                       // and the size decrements in one unit
      }
   }
   bool VectorDouble::set(int fElem, double e)  // sets the element e at (fElem)
   {
      if (fElem > capacity())
         return 0;
      else 
      {
         vector[fElem] = e;
         if (fElem > size())
            length = fElem + 1;
         return 1;
      }
   
   }
   bool VectorDouble::get(int fElem, double &e)  // retrieves the element at (fElem)
   {
      if ((fElem > capacity()) || (fElem > size()))
         return 0;
      else 
      {
         e = vector[fElem];
         cout << "\n The element at the " << fElem << " position is " << e << "\n";
         return 1;
      }
   }

   int VectorDouble::indexOf (double e)
        // returns the position (1->N) of the first occurrence of e or 0 if not found
   {
      int i;
      for (i = 0; (vector[i] != e) && (i < size()); i++);
      if (vector[i] == e)
         return i;         
      else
         return 0;
   }
   int VectorDouble::lastIndexOf (double e)
        // returns the position (1->N) of the last occurrence of e or 0 if not found
   {
      int i;
      for (i = size(); (vector[i] != e) && (i != 0); i--);
      if (vector[i] == e)
         return i;         
      else
         return 0;
   }
   bool VectorDouble::contains (double e)
        // returns whether e is in the vector 
   {
      if (indexOf (e) != 0)
         return 1;      // "e" is in the vector
      else      
         return 0;
   }

   bool VectorDouble::isEmpty() // returns whether the vector is empty 
   {
      if (size() == 0)
         return 1;    // the vector is empty
      else
         return 0;
   }
   bool operator== (const VectorDouble& V1, const VectorDouble& V2)
    // checks to see if the vectors are equal or not
   {
      int i;
      if (V1.size() != V2.size())  
         return 0;
      for (i = 0; (V1.vector[i] == V2.vector[i]) && (i < V1.size()); i++);
      if (i == V1.size())        
         return 1;               // the vectors are equal
      else
         return 0;
   }
//    VectorDouble operator= (const VectorDouble& V1)    //is it a method.....?
    // assignment operator 
  //  {
    //}

   VectorDouble operator+ (const VectorDouble& V1, double e)
    // appends e to the vector 
   {
      VectorDouble* temp2;
      *temp2 = V1;
      temp2->add(e);
   }

   VectorDouble operator- (const VectorDouble& V1, double e)
    // removes e from the vector 
   {
      VectorDouble* temp2;
      *temp2 = V1;
      temp2->remove(e);
   }

   VectorDouble operator+ (const VectorDouble& V1, const VectorDouble& V2)
    // appends all elements in V2 to V1 
   {
      VectorDouble Add (V1.length_max + V2.length_max);       // call to the second constructor       
      int i;
      for (i = 0; i < V1.length; i++) 
         Add + V1.vector[i];               // appends all elements in V1 to Add
      int j = i + 1; Add.length = j;
      for (i = 0; i < V2.length; i++) 
         Add + V2.vector[i];               // appends all elements in V2 to Add
      Add.length += i;                     // updates the vector size
   }

   VectorDouble operator- (const VectorDouble& V1, const VectorDouble& V2)
    // removes all elements in V2 from V1 
   {
      VectorDouble Subs (V1);       // call to the copy constructor  
      int i, j;
      for (i = 0; i < V1.size(); i++)
      {
         for (j = 0; j < V2.size(); j++)
            if (V1.vector[i] == V2.vector[j])
            {Subs - V2.vector[j];
               Subs.length--;}         
      }
   }

   ostream& operator<<(ostream& os, const VectorDouble& V1)
   {
       // Output should appear as [ # # # ... # ]
      os << endl << "[ ";
      for (int i=0; i < V1.size(); i++)
         cout << V1.vector[i] << " ";
      os << "]";
      return os;
   }

   istream& operator>>(istream& is, VectorDouble& V1)     
   {
   //       Input is provided as [ N : # # # ... # ] 
      char garbage; int num;     // Be careful with these types!!!
      cout << "\nPlease, enter the elements, separated by a single space,\n";
      cout << "following this format: [ N : # # # ...# ], being N\n the number of elements you are to input:\n\n";
      is >> garbage; is >> num; is >> garbage; 
      if (num > V1.length)
         V1.length = num; 
   // we have to check that num <= V1.capacity()
      for (int i = 0; i < num; i++)
         is >> V1.vector[i];// cout << V1.vector[i];}
           // cout << V1.vector[2];
      return is;
   }

   int main()
   {
      VectorDouble table;
      cout << endl << "the size of table is  " << table.size();
      VectorDouble table2(14);
      cout << endl << "the size of table2 is  " << table2.size();
      cout << endl << "the capacity of table2 is  " << table2.capacity();
   
      table2.set(5,668);
      table2.set(0,24821);
      cout << table2;
      cout << endl << "the size of table2 is  " << table2.size();
      table2.set(7,668);
      table2.set(10,700);
      cout << table2;
      cout << "\nThe last occurrence of 668 is at" << table2.lastIndexOf(668);
   //*****************************************************
      VectorDouble table3(table2);
      cout << endl << "the capacity of table3 is  " << table3.capacity(); 
      cout << table3;
      table3.set(12,30);
      cout << endl << table3.size();
      table3.add(123);
      cout << table3;      
      cout << endl << table3.size();
      table3.add(001);
      cout << endl << "the capacity of table3 is  " << table3.capacity(); 
      cout << table3;      
   
      return 0;
   }
