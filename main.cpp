//
//  CSDP 250 Project 5
//  Created by Isabelle Puwo on 11/25/23.
//

#include <iostream>
#include "AVLtree.hpp"

using namespace std;

int main(){
    BST tree;
    const int numNumbers = 35;
    
   tree.generateRandomNumbers(numNumbers);
    while (true) {
           cout << "Menu:\n";
           cout << "1. Display Inorder Traversal\n";
           cout << "2. Delete a Node\n";
           cout << "3. Check if it's an AVL Tree\n";
           cout << "4. Exit\n";
           cout << "Enter your choice (1-4): ";

           int choice;
           cin >> choice;

           switch (choice) {
               case 1:
                   cout << "Inorder Traversal: \n";
                   tree.inorderTraversal();
                   cout << "\n\n";
                   break;
               case 2:
                   cout << "Enter the value to delete: ";
                   int value;
                   cin >> value;
                   tree.removeNode(value);
                   cout << "Postorder Traversal: \n";
                   tree.postOrderTraversal();
                   cout << "\n\n";
                   break;
               case 3:
                   if (tree.checkifAVL()) {
                       cout << "The tree is an AVL Tree.\n";
                   } else {
                       cout << "The tree is not an AVL Tree.\n";
                   }
                   break;
               case 4:
                   cout << "Ending the program...\n";
                   exit(0);
               default:
                   cout << "Invalid input. Please enter a number between 1 and 5.\n";
           }
       }

       return 0;
    
}
