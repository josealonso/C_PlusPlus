 /************* STUDENT: Jose Ramon Alonso *************************************
 *************** STUDENT NUMBER: 000 - 07 - 1217 *********************************
 *************** COURSE: CS 124,COMPUTER SCIENCE II (fall 2002) ******************
 *************** PROJECT #1, due on September 03 *********************************/

   #include <fstream>    // For file manipulation
   #include <iostream>
   #include <string>
   #include <ctype.h>
   #include <cctype>
   #include <cstdlib>    // This library contains the "exit" function

   string translate (string& s); // Declaration of the function that converts the words

   string translate (string& s)
   {
      string parole(s);  
      int position;
      string trans;
      string vowels;
   
      if (parole[0]=='y')         // If "y" is the first letter of the word,
         vowels="aeiouAEIOU";      
      else                        // it is treated as a consonant.
         vowels="aeiouyAEIOUY";
      position=parole.find_first_of(vowels,0); // Finds the position of the first vowel.
   
   
      if (isupper(parole[0]))                    // If the first letter is capital,
      {                                          // this letter is made lowercase and 
         parole[0]= (char) tolower(parole[0]);
         for (int e=1; e<parole.length(); e++)   // the rest of the letters (of that word)
         {
            parole[e]=(char) toupper(parole[e]); // is capitalized.
         }
      }
   
      //      if ((parole[position]=='u') && (parole[position-1]=='q'))
      //      {
      //
      //      }
      if ((position==0) || (position==-1))       // If the first letter is a vowel 
      {                                          // or there are no vowels,
         parole +="way";                         // just adds "way" to the end of the word.
         cout << parole;
      }
      else                                       // Otherwise, the word is translated in two steps:
      
      {
         trans=parole;      //IT WONT WORK WITHOUT THIS LINE!!!!
         for (int d=0; d<=(parole.length()-position); d++)  // first, translates the previous letters
            trans[d]=parole[d+position];                    // to the first vowel and the vowel itself.
         int b=0;
      
         for (int a=0; a<=(parole.length()-position); a++)  // Second, translates the rest of the letters
         {                                                  // of the word.
            trans[(parole.length()-position)+a]=parole[b]; 
            b++;
         }
         trans +="ay";                                      // Finally, adds "ay" to the end of the word.
         cout << trans;
      }   //else bracket
      return trans;
   }


   int main( ) 
   { 
   
      using namespace std;
   
      char z;   
      string line;
      string word=line;
      ifstream in_file;               // Input file stream
      ofstream out_file;              // Output file stream
   
      in_file.open("data.en.txt");     //you have to add the "txt" extension
      if (in_file.fail())
      {
         cout << "The input file cannot be opened.\n";
         exit (1);
      }
   
      out_file.open("data.pl.txt");
      if (out_file.fail())
      {
         cout << "The output file cannot be opened.\n";
         exit (1);
      }
   
      cout << "\nNow, the output\n";    
   
      while (!in_file.eof())      // Reads the input file until its end,
      {
         getline (in_file,line);
         for (int i=0; i<line.length(); i++)  //line by line.
         
         {     // ASCII Table is used to see whether the character is a letter.
         
            if (((int)line[i]>64 && (int)line[i]<91) || ((int) line[i]>96 && (int)line[i]<123)) 
             // The character is either a letter  
            { 
              // word=line;
               int j=0; 
               while (((int)line[i]>64 && (int)line[i]<91) || ((int) line[i]>96 && (int)line[i]<123))
               {
                  word[j]=line[i];
                  //out_file << (word[j]);  // Breaks up the text into words.
                  j++; i++;  
               }
               i=i-(word.length())-1; word[j]='0'; // '0' indicates the word ending
            
               word=translate(word);       // If I uncomment this, a core dump is produced         
                                                   //        (I don't know why)
               out_file << word;
               int c=0;
               z=word[c];                                  
               while(z!='0')                     // Print one word  in each line
               { z=word[c]; cout << z << "\t"; c++;} //It prints the words with some strange extra characters
            
               cout << endl;   
            }   
            
            else   // or the character is a non-letter.
               out_file << (line[i]);
         
         } // for brace
         out_file << endl; // Another line
      
         cout << "\nThe length of this line is:" << line.length() << endl;// cout << line[25] << line[26] << line [27];
      }  // while brace    
      in_file.close();
      out_file.close();
   
      return 0;
   }

