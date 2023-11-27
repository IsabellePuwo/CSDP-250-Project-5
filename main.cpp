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
    cout << "Inorder Traversal: \n";
    tree.inorderTraversal();
    cout<< "\n\n";
    cout<<"Do you want to delete a node from the tree? (y/n): ";
    char choice;
    cin>> choice;
    
    if (choice == 'y') {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            tree.removeNode(value);
            cout << "Postorder Traversal: \n";
            tree.postOrderTraversal();
            cout << "\n\n";

            if (tree.checkifAVL()) {
                cout << "The tree is an AVL Tree.\n";
            } else {
                cout << "The tree is not an AVL Tree.\n";
            }
        } else if (choice == 'n') {
            cout << "Ending the program...\n";
            exit(0);
        } else {
            cout << "Invalid input. Ending the program.\n";
        }

        cout << "Program ended successfully.\n";
        return 0;
    
    
}
