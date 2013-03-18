#include <string>
#include <fstream>    // For file manipulation
#include <iostream>
#include <stdlib.h>

   using namespace std;

   class TreeNode {
      int counter;
      string data;
      TreeNode *left;
      TreeNode *right;
      TreeNode( ) : counter(0), data(0), left(0), right(0) { 
      }
      TreeNode(string e) : counter(0), data(e), left(0), right(0) { 
      }
      friend class BinaryTree;
      friend ostream& operator<<(ostream&, const TreeNode&);
   };

   class BinaryTree {
      TreeNode *root;
      int DoAdd(string e, TreeNode* n) {
         if (n == 0) 
            return 0;
         if (e == n->data) {
            (n->counter)++;   // add the "duplicates"
            return 0;
         }
         if (e < n->data)
            if (n->left) {
               return DoAdd(e, n->left);
            }
            else {
               n->left = new TreeNode(e);
               return 1;
            }
         if (e > n->data)
            if (n->right){
               return DoAdd(e, n->right);
            }
            else {
               n->right = new TreeNode(e);
               return 1;
            }
      }
      int DoFind(string e, TreeNode* n) {
         if (n ->data == e) 
            return 1;
         if (n->data > e)
            if (n->left) 
               return DoFind(e, n->left);
            else 
               return 0;
         else 
            if (n->right) 
               return DoFind(e, n->right);
            else 
               return 0;
      }
   
      int DoRemove(TreeNode*& n, string e) {
         cout << "In DoRemove with node " << n << endl;
         if (n == 0) 
            return 0;
         cout << "\tdata value in this node is    : " << n->data << endl
            << "\tleft subtree of this node is  : " << n->left;
         if (n->left) cout << " with value " << n->left->data << endl; 
         else cout << endl;
         cout << "\tright subtree of this node is : " << n->right;
         if (n->right) cout << 
               " with value " << n->right->data << endl; 
         else cout << endl;
      
         TreeNode *tmp;
         if (e < n->data) {
            cout << "\t\tcalling DoRemove on left subtree" << endl;
            return DoRemove(n->left, e);
         }
         else
            if (e > n->data) {
               cout << "\t\tcalling DoRemove on right subtree" << endl;
               return DoRemove(n->right, e);
            }
            else {
               cout << "*** DELETING THE NODE ***" << endl; 
               if (n->left == 0) {
                  cout << "No left child, replacing node with right child (or NULL)" << endl;
                  tmp=n;
                  n=n->right;
                  delete tmp;
                  return 1;
               }
               else
                  if (n->right == 0) {
                     cout << "No right child, replacing node with left child" << endl;
                     tmp=n;
                     n=n->left;
                     delete tmp;
                     return 1;
                  }
                  else {
                     cout << "Two children, must find predecessor and swap values" << endl;
                     tmp=n->left;
                     while (tmp->right != 0) tmp=tmp->right;
                     cout << "\tPredecessor is : " << tmp->data << ", replacing " << n->data << " with this value" << endl;
                     n->data=tmp->data;
                     cout << "\tRemoving predecessor node with value " << tmp->data << endl;
                     return DoRemove(n->left, tmp->data);
                  }
            }
      }
   public:
      BinaryTree( ) : root(0) { 
      }
      int Add(string e) {     
         cout << "Adding...." << e;
         if (!root) root = new TreeNode(e);
         else 
            return DoAdd(e, root);
      }
      int Remove(string e) {
         if (!root) 
            return 0;
         else 
            return DoRemove(root, e);
      }
      int Find(string e) {     
         cout << "Finding...." << e;
         if (!root) root = new TreeNode(e);
         else 
            return DoFind(e, root);
      }
   
      friend ostream& operator<<(ostream&, const BinaryTree&);
   };



   ostream& operator<<(ostream& os, const TreeNode& n) {
      if (n.left) os << *n.left;
      os << n.data << " ";
      if (n.right) os << *n.right;
      return os;
   }

   ostream& operator<<(ostream& os, const BinaryTree& t) {
      os << "< ";
      if (t.root) {
         os << *t.root;
      }
      os << ">";
      return os;
   }

//******************************************* MAIN Function *************************************
   int main( ) {
      BinaryTree Shakes_tree;
      BinaryTree peers_tree;
      int index = 0; 
      string element; // It seems a string cannot be iniatilized in its declaration = '\0';
      char word [20];
      ifstream in_file;               // Input file stream
   
   //********************* Building the Shakespeare's binary tree **********************************
   
      in_file.open("comedyoferrors2.txt");     //you have to add the "txt" extension
      if (in_file.fail())
      {
         cout << "The input file cannot be opened.\n";
         exit (1);
      }
   
      in_file.get (word [index]); 
      while (!in_file.eof())      // Reads the input file until its end.
      {    // cout << endl << "Inside the while....\n";
         if ((!isspace (word[index])) && (!ispunct(word[index]))) {   // It is a letter
            word[index] = (char) toupper(word[index]);      // convert all the letters to uppercase
            //cout << word[index];
            element += word[index]; // cout << element;
            index++;}
         else{
            //cout << word[index];
            if (element.length() > 4)
               peers_tree.Add(element);
            element = '\0';
            index = 0;
         }
         in_file.get (word [index]); 
      
      }
      in_file.close();
      cout << endl << endl;
   
   //******************** Building the candidate peer's binary tree **************************************** 
   
      in_file.open("comedyoferrors3.txt");     //you have to add the "txt" extension
      if (in_file.fail())
      {
         cout << "The input file cannot be opened.\n";
         exit (1);
      }
   
   
      in_file.get (word [index]); 
      while (!in_file.eof())      // Reads the input file until its end.
      {    // cout << endl << "Inside the while....\n";
         if ((!isspace (word[index])) && (!ispunct(word[index]))) {   // It is a letter
            word[index] = (char) toupper(word[index]);      // convert all the letters to uppercase
            //cout << word[index];
            element += word[index]; // cout << element;
            index++;}
         else{
            //cout << word[index];
            if (element.length() > 4)
               peers_tree.Add(element);
            element = '\0';
            index = 0;
         }
         in_file.get (word [index]); 
      
      }
   
   //             Output
   /////
   /////             The candidate peer used 3 distinct large words.
   /////             Shakespeare used 3 distinct large words.
   /////             Based on large words, the candidate covered 66% of the work by Shakespeare 
   
   }

