# include <fstream>    // For file manipulation
# include <iostream>
# include <string>
# include <ctype.h>

   using namespace std;

   struct card
   {
      string Name;
      int Year;
      string Manufac;
      int Value;
      int Quant;
   };

   class BBCC
   {
   private:
      card collection [1000];
      int next[1000];
      int first, free;
   
   public:
      BBCC();   //default constructor
      BBCC (const BBCC&);        // copy constructor
      friend BBCC operator + (const BBCC&, const BBCC&);
      friend BBCC operator - (const BBCC&, const BBCC&);
      friend ostream& operator << (ostream &, const BBCC&);
      friend istream& operator >> (istream &, BBCC&);  // reads in from a file
      friend BBCC operator + (const BBCC&, const card&);
      friend BBCC operator - (const BBCC&, const card&);
      int value (void);    // returns the total value of the entire collection (class)
      bool same (const BBCC&, const BBCC&);
      int find (const BBCC&, const card&);
      int find (const BBCC&, const string&);
   };
   ostream& operator << (ostream &, const card&);    
//   istream& operator >> (istream &, card&);          

   BBCC::BBCC()   //default constructor
   {
      first = -1;
      free = 0;
      for (int i = 0; i < 999; i++)
      {
         next[i] = 0;
         collection[i].Name = "Smith"; 
         collection[i].Year = 1984;
         collection[i].Manufac = "Topps";
         collection[i].Value = 10;
         collection[i].Quant = 1; 
      }
      cout << collection[0].Name ;
      cout << collection[0].Year ;
      cout << endl << collection[1].Value << endl;
   
   }
   BBCC::BBCC (const BBCC& cl)        // copy constructor
   {
      first = cl.first;
      free = cl.free;
      for (int j = 0; j < 999; j++)
      {
         next[j] = 0;
         collection[j].Name = cl.collection[j].Name;
         collection[j].Year = cl.collection[j].Year;
         collection[j].Manufac = cl.collection[j].Manufac;
         collection[j].Value = cl.collection[j].Value;
         collection[j].Quant = cl.collection[j].Quant;
      }
   }

/*   BBCC::int value (void)    // returns the total value of the entire collection (class)
   {
   
   }

   BBCC::bool same (const BBCC&, const BBCC&)
   {
   
   }

   BBCC::int find (const BBCC&, const card&)
   {
   
   }

   BBCC::int find (const BBCC&, const string&)
   {
   
   }
*/

////---------------------------------------------------------------------------------------------

   istream& operator >> (istream& is, BBCC& C) {
   
      ifstream file;
      file.open("collection.txt"); cout << "File opened\n"; 
      card info;
      file >> info.Name; cout << "\nWhy??\n" << info.Name;
      while(info.Name != "end") {
         file >> info.Year >> info.Manufac >> info.Value >> info.Quant;//cout << info.Year << info.Manufac << info.Value << info.Quant;
      
         file >> info.Name;
      }
      cout << "\nOutside the while\n";
      return file;} //is;
   //} 

  /*  ===================================================
      ifstream file;
      file.open("collections.txt");
      int total,tvalue;
      card temp;
      while(getline!="end")
      {
         is>>temp.Name;
         temp.Name = toupper(temp.Name);
         is>>temp.Year;
         temp.Year = toupper(temp.Year);
         is>>temp.Manu;
         temp.Manu = toupper(temp.Manu);
         is>>temp.Value;
         temp.Value = toupper(temp.Value);
         is>>temp.Quan;
         temp.Quan = toupper(temp.Quan);
         total++;
         tvalue+=temp.Value;
         Add(temp);
         temp.Name=void;
         temp.Year=0;
         temp.Manu=void;
         temp.Value=0;
         temp.Quan=0;
      }
      cout<<"The total number of cards added to the collection was "<<total<<endl;
      cout<<"and the value of the cards is "<<tvalue<<"."<<endl;
      return is;
   }
======================================================== */

/*   istream& operator >> (istream& is, card& newone)
   {
      cout<<"Enter the name on the card:";
      cin>>newone.Name;
      cout<<"Enter the year of the card:";
      cin>>newone.Year;
      cout<<"Enter the Manufacturer of the card:";
      cin>>newone.Manufac;
      cout<<"Enter the Value of the card:";
      cin>>newone.Value;
      cout<<"Enter the number of cards you have:";
      cin>>newone.Quant;
      return is;
   }
*/

   ostream& operator << (ostream& out, const card& newone)
   {
      cout<< endl << "The name on the card is "<<newone.Name<<endl;
      cout<<"The year on the card is "<<newone.Year<<endl;
      cout<<"The Manufacturer of the card is "<<newone.Manufac<<endl;
      cout<<"The Value of the card is "<<newone.Value<<endl;
      cout<<"The number of cards you have is "<<newone.Quant<<endl;
   }

   BBCC operator + (const BBCC& starter, const card& newone)
   {
      BBCC temp(starter);
   //      temp.add(newone);
      return temp;
   }
    
/*   Add(card e)
   {
      if(free==-1)
      {
         cout<<"Error:Full"<<endl;
      }
      if (first ==-1)
      {
         first=free;
         free=next[free];
         card[first].Name=e.Name;
         card[first].Year=e.Year;
         card[first].Manu=e.Manu;
         card[first].Value=e.Value;
         card[first].Quan=e.Quan;
         next[first]=-1;
         return 1;
      }
      if(e.Name<card[first].Name)
      {
         temp=free;
         free=next(free);
         card[temp].Name=e.Name;
         card[temp].Year=e.Year;
         card[temp].Manu=e.Manu;
         card[temp].Value=e.Value;
         card[temp].Quan=e.Quan;
         next[temp]=first;
         first=temp;
         return1;
      }
      int temp=first,temp2=first;
      while((t!=1)&&(card[t]<e))
      {
         temp2=temp;
         temp=next[temp];
      }
      if((temp!=1)&&(card[temp].Name==e.Name))
         if((card[temp].Name==e.Name)&&(card[temp].Year==e.Year)&&(card[temp].Manu==e.Manu)&&(card[temp].Value==e.Value))
         {
            cout<<"Error:Exists"<<endl;
            card[temp].Quantity=card[temp].Quantity+e.Quantity;
            return 0;
         }
      int temp3=free;
      free=next[free];
      card[temp3].Name=e.Name;
      card[temp3].Year=e.Year;
      card[temp3].Manu=e.Manu;
      card[temp3].Value=e.Value;
      card[temp3].Quan=e.Quan;
      next[temp2]=temp3;
      next[temp3]=temp;
      return 1;
   }

 */

   int main ( ){
      BBCC starter;  // BBCC is a class for a baseball card collection
   
      cin >> starter;  // reads in a baseball card collection from an 
   // external file -- stops when it encounters the string "end"
   
   /*      cout << starter; // prints to the screen an entire BBCC alphabetically
   
      BBCC reserve(starter);  // makes a copy of starter */
   
      card newOne; //  card is a data structure for a baseball card 
   
      cin >> newOne;  // reads in a new card from keyboard input
   
      cout << newOne; // prints this card to the screen 
   
   /*   BBCC updated = starter + newOne; // adds a card to a collection
   
   
      BBCC purchase;   
      cin >> purchase;
      cout << "The total value of this purchase is: " << purchase.value();
      updated = updated + purchase; // adds two collections
   
      BBCC acquisitions = updated - reserve; // removes a collection from a collection
   
      acquisitions = acquisitions - newOne;  // removes a card from a 
   // collection
   
      if (same(acquisitions,purchase))
         cout << "Calculations are correct." << endl;
      else
         cout << "Bookkeeping error has occurred." << endl;
   
      if ( find(updated, newOne)) {
         cout << "Card located as card number: ";
         cout << find(updated, newOne);
         cout << "in the collection." << endl;}
      else
         cout << "Card not in collection." << endl;
   
      if (find(updated, "Ruth")){
         cout << "Card located as card number: ";
         cout << find(updated, "Ruth");
         cout << "in the collection." << endl;}
      else
         cout << "Card not in collection." << endl;
      cout << updated;
   */
      return 0;}


