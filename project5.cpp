#include <iostream>

   class Node{
      int data;
      Node *next;
   
   public:      //If the methods are private, the friend functions won't work
   
      Node():data(0), next(0){
      }
      Node(int e):data(e), next(0){
      }
      Node(int e, Node *n):data(e), next(n){
      }
      int GetData(void)
      {
         return data;}
      void SetData(int e) 
      {data = e;}
      Node *GetNext(void)
      {
         return next;}
      void SetNext(Node *n)
      {next = n;}
      friend class IntSet;    // Allows the IntSet class to access "data" and "next" directly
      friend IntSet& operator+ (const IntSet&, const IntSet&); // returns the union
      friend IntSet& operator- (const IntSet& A, const IntSet& B); // returns A-B
      friend ostream& operator << (ostream& , IntSet&);   
      friend ostream& operator << (ostream& os, const Node& A);   
   };

   class IntSet {
   public:
      Node* head;     //a pointer to the first node in the set
   
   //   public:
      IntSet():head(0){
      }                  // default constructor
      IntSet(const IntSet&);              // copy constructor
      IntSet(int);                        // set initially containing the integer given
      ~IntSet();                          // destructor
   
      int Add (int e);
      int Remove(int e);
   
      bool operator == (const IntSet&);    // whether the sets are equal   
      bool isElement (int X);             // whether X is in the set
      bool isSubset (IntSet& A);    // whether this is a subset of A
      bool isProperSubset (IntSet& A);  // whether this is a proper subset of A
      bool isSuperset (IntSet& A);  // whether this is a superset of A
   
      IntSet& intersect (const IntSet&);  // returns the intersection
      int cardinality (void);             // returns the cardinality
   
      friend IntSet& operator+ (const IntSet&, const IntSet&); // returns the union
      friend IntSet& operator- (const IntSet& A, const IntSet& B); // returns A-B
   
      friend IntSet& operator+ (const IntSet&, int); // adds the int to the set
      friend IntSet& operator- (const IntSet& A, int); // removes the int from the set
   
   /*    friend istream& operator>> (istream&, IntSet&); // inputs a set
          // Format is {N: #, #, #, ... #} where N is the number of integers
          // in the list to follow.  */
      friend ostream& operator<< (ostream& os, const IntSet&); // outputs a set   I'VE CHANGED THIS!!
          // Format is {#, #, #, ... #}      
   }; 

   int IntSet::Add(int e) {       
  
      if (head == 0) { // adding to empty list
        ///// cout << endl << "1st case" << endl;
         head = new Node(e);
         return 1;
      }
      if (e < head->data) {
         Node *newone = new Node(e, head);
         head = newone;
         return 1;
      }
      Node *prev=head, *curr=head;
      while ( (curr != 0) && (curr->data<e) ) {
         prev = curr;
         curr = curr->next;
      }
      if ( (curr != 0) && (curr->data == e) ) 
         return 0;
      Node *temp=new Node(e, curr);
      prev->next = temp;
      return 1;
   }

//**********************************************************************************
  
   int IntSet::Remove(int e) {
         cout << "In Remove" << endl;
         if (! head) {
            cout << "Not in list or the list is empty" << endl;
            return 0;
         }
         Node *curr = head;
         if (curr->data == e) {
            cout << "\tremoving the first element in the list" << endl;
            head = curr->next;
            cout << "\tdeleting node at location " << curr << endl;
           delete curr;
            return 1;
         }
         cout << "\tchecking middle & end of list for item to remove" << endl;
         Node *prev = head;  // *curr is already declared, still points to 1st item (head of list)
         while ( (curr) && (curr->data < e) )
         { prev = curr; curr = curr->next; }	cout << "\titem before one to be potentially removed is " << *prev << endl;
         if (! curr) {
            cout << "\titem was not in the list (looked all the way to the end of the list)" << endl;
            return 0;
         }
         if (curr->data != e) {
            cout << "\titem was not in the list (hit items bigger than it without seeing it)" << endl;
            return 0;
         }
         cout << "\tfound item, now removing it, update " << *prev << " to point to beyond it" << endl;
         prev->next = curr->next;
         cout << "\tdeleting node at location " << curr << endl;
         delete curr;
         return 1;
      }

//***********************************************************************************************

   IntSet::IntSet(const IntSet& A)              // copy constructor
   {
      head = NULL;
      Node *temp;                                 // A is an address, not an object!!!
      for (temp = A.head; temp; temp = temp->next)   // Adds each element in the set
        Add (temp->data);
   }

   IntSet::IntSet(int n)                        // set initially containing the integer given
   {
      IntSet();      //call to the default constructor
           // allocate new node
      Node *newone = new Node(n, head);
      head = newone; //update head
   }

   IntSet::~IntSet()                          // destructor
   {
 /*     Node *temp = head, *save;     
      for (;temp; save = temp, temp = temp->next)  
        delete temp;    */
   } 

   bool IntSet::operator == (const IntSet& A)    // whether the sets are equal
   {
      Node* temp;
      for (temp = A.head;temp;temp = temp->GetNext())
      {
         int number = temp->GetData();
         if (isElement(number) == 0)
            return 0;
      }
      return 1;    // The sets are equal     
   }                              // There's something left

   bool IntSet::isElement (int X)             // whether X is in the set
   {                                      // It is the "Find" function
      Node* temp;
      for (temp = head;temp && temp->GetData() != X;temp = temp->GetNext());
      if (temp)
         return 1;
      else
         return 0;
   }

   bool IntSet::isSubset (IntSet& A)    // whether this is a subset of A
   {
      Node *temp;
      for (temp = A.head;((temp) && (isElement(temp->data)== 1)); temp = temp->GetNext());
      if ((temp == 0) && (cardinality() < A.cardinality())) //all the integers are in both sets
        return 1;        // it is a subset of A
      else
        return 0;        // it is not a subset of A
   }

   bool IntSet::isProperSubset (IntSet& A)  // whether this is a proper subset of A
   {
      Node *temp;
      for (temp = A.head;((temp) && (isElement(temp->data)== 1)); temp = temp->GetNext());
      if ((temp == 0) && (cardinality() == A.cardinality())) 
        return 1;        // it is a proper subset (the same set)
      else
        return 0;
   }

   bool IntSet::isSuperset (IntSet& A)  // whether this is a superset of A
   {
      Node *temp;
      for (temp = A.head;((temp) && (isElement(temp->data)== 1)); temp = temp->GetNext());
      if ((temp == 0) && (cardinality() > A.cardinality())) 
        return 1;        // it is a superset of A
      else
        return 0;

   }

   /* IntSet& IntSet::intersect (IntSet& A)  // returns the intersection
   {
      IntSet *inter = new IntSet(A);
      Node *temp;
      IntSet inter2 = *inter;
      inter2 = 
      return inter2;
   }  */

   int IntSet::cardinality (void)             // returns the cardinality
   {  
      Node* temp = NULL;       // Temporal pointer
      int N = 0;
      for (temp = head; temp; temp = temp->GetNext(), N++);
      return N;
   }

   IntSet& operator+ (const IntSet& A, const IntSet& B) // returns the union
   {
      IntSet *Union = new IntSet(A);
      Node *temp;
      IntSet Union2 = *Union;
      for (temp = B.head; temp; temp = temp->next)   
         Union2 = Union2 + temp->data;
      return Union2;
   }
   IntSet& operator- (const IntSet& A, const IntSet& B) // returns A-B
   {
      IntSet *Subs = new IntSet(A);
      Node *temp;
      IntSet Subs2 = *Subs;
      for (temp = B.head; temp; temp = temp->next)   
         Subs2 = Subs2 - temp->data;
      return Subs2;

   }

   IntSet& operator+ (const IntSet& A, int n) // adds the int to the set
   {
      IntSet *B = new IntSet(A);  //call to the copy constructor (the new object is called B)
      IntSet C = *B;
      C.Add(n);
      return C;     //This line is correct!!!!
   }

   IntSet& operator- (const IntSet& A, int n) // removes the int from the set
   {
      IntSet *B = new IntSet(A);  //call to the copy constructor (the new object is called B)
      IntSet C = *B;
      C.Remove(n);
      return C;     //This line is correct!!!!
   }

  /*    istream& operator>> (istream& is, IntSet& A) // inputs a set
          // Format is {N: #, #, #, ... #} where N is the number of integers in the list to follow.
    {
    }
*/
   ostream& operator << (ostream& os, const Node& A)   
   {
     os << A.data;
     return os;
   }

   ostream& operator << (ostream& os, IntSet& A) // I had to remove "const" from this line
   {
      Node *temp = A.head;
      cout << endl << "  Format is {";
      for (; temp; temp = temp->next)   // Outputs each element in the set
        os << *temp << ", ";  /////// *temp or not????
      os << "}";  
      return os;
   }   

   int main()
   {
      IntSet Set_4;
      IntSet Set_1;
      IntSet Set_2;
      IntSet Set_3(Set_2);    cout << "\n First call to the c.c done\n";
      Set_4 = Set_1 + 4 + 6;   //If you put "Set_1 = ....", it compiles, but it doesn't run
      cout << Set_4;
      Set_1 = Set_4 + 5 + 7 + 11;
//      cout << Set_1;
      Set_2 = Set_1 + 5 + 8 + 12 + 14;
      cout << Set_2;
      int t = Set_2.isElement(18);     
      cout << "\nLet's see.....   " << t << "\n";
///      Set_1 = Set_2 - Set_4;
///      cout << Set_1;
        ////int f = Set_1.cardinality();
        ////cout << endl << "cardin.: " << f;
   /*      Set_3 = Set_2 + 10;
      IntSet Set_4;
      cout << Set_2;
      cout << Set_3;
      Set_4 = Set_3 + Set_2;
      cout << "\n The Union is:" <<  Set_4;
      int t = Set_3.isElement(4);     cout << "\nLet's see.....   " << t << "\n";
      cout << "\n       IT'S DONE!!!!!! so far.....\n";  */
      return 1;
   }
