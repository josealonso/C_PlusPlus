/**************************************************
     Names: Eugene Pawlik III  	
		 Bradley Hall		   
		 Jose Alonso			   
**************************************************/


#ifndef PROJECT6_H		// make sure this is included only once
#define PROJECT6_H

#include <iostream>		
#include <string>
   using namespace std;


	// Node class. will hold the word, the amount of times it was used, and
	// the left and right children of the node
   class Node 
   {
      string word;
      int count;
      Node *left, *right;
   
   public:
      Node(const string& w);
      Node(const Node& t);
      friend class Tree;
      friend ostream& operator<<(ostream& os, const Node& n);
   };


   // will do most of the work for the program.
   class Tree
   {
      Node *root;		// hold the root node of the tree
      int  DoAdd(const string& word, Node *n);		// add a node to the tree. used by Add()
      bool DoFind(const string& word, Node *n) const;	// find a node in the tree. Used by Find()
      int getDistinctWords(const Node& n, int num);	// distinct words. Used by DistinctWords()
      int getTotalWords(const Node& n, int);			// total words in the tree. Used by TotalWords()
   public:
      Tree();
      ~Tree();
   
      // compare two trees and find any similar words
      int findSimilar(const Tree& shakes, const Node* n, int num);
   
      void removeList(Node& n);					// delete the tree
      int  Add(const string& word);				// adds the word to the tree
      bool Find(const string& word) const;		// will look for the word in the tree
      int  Remove(const string& word);			
      Node* getRoot() { 
         return root; }			// get the root of the tree
      int  TotalWords();						// total words in the tree
      int DistinctWords();						// # of different words in the tree
   
     // friend to output a tree
      friend ostream& operator<<(ostream& os, const Tree& tree);
   };



#endif // PROJECT6_h
