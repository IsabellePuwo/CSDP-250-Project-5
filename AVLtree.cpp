//
//  CSDP 250 Project 5
//  Created by Isabelle Puwo on 11/25/23.
//

#include "AVLtree.hpp"
#include <iostream>
using namespace std;

void BST::inOrder(TreeNode* nodePtr){
    if (nodePtr == nullptr) {
        return;
    } else {
        inOrder(nodePtr->left);
        cout <<nodePtr->data << " "<<endl;
        inOrder(nodePtr->right);
    }
}

void BST::postOrder(TreeNode* nodePtr){
    if (nodePtr == nullptr) {
        return;
    } else {
        postOrder(nodePtr->left);
        postOrder(nodePtr->right);
        cout << nodePtr->data << " "<<endl;
    }
}
void BST::inorderTraversal(){
    inOrder(root);
}

void BST::postOrderTraversal() {
    postOrder(root);
}

void BST::empty(TreeNode* nodePtr) {
    if (nodePtr == nullptr) {
        return;
    }

    if (nodePtr->left != nullptr) {
        empty(nodePtr->left);
        nodePtr->left = nullptr;
    }

    if (nodePtr->right != nullptr) {
        empty(nodePtr->right);
        nodePtr->right = nullptr;
    }

    if (nodePtr->parent != nullptr) {
        if (nodePtr->parent->left == nodePtr) {
            nodePtr->parent->left = nullptr;
        } else if (nodePtr->parent->right == nodePtr) {
            nodePtr->parent->right = nullptr;
        }
    }

    if (nodePtr == root) {
        root = nullptr;
    }

    delete nodePtr;
}
BST::TreeNode* BST::insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}


void BST::deleteNode(TreeNode*& nodePtr, int value) {
    if (nodePtr == nullptr) {
        cout << "The tree is empty" <<endl;
        return;
    }
    if (value < nodePtr->data) {
        deleteNode(nodePtr->left, value);
    } else if (value > nodePtr->data) {
        deleteNode(nodePtr->right, value);
    } else {
        // Node found
        if (nodePtr->left == nullptr) {
               TreeNode* temp = nodePtr;
            nodePtr = nodePtr->right;
            delete temp;
        } else if (nodePtr->right == nullptr) {
            TreeNode* temp = nodePtr;
            nodePtr = nodePtr->left;
            delete temp;
        } else {
            // Node has both children
            TreeNode* replacement = minValueNode(nodePtr->right);
            nodePtr->data = replacement->data;
            deleteNode(nodePtr->right, replacement->data);
        }
    }
}

BST::TreeNode* BST::minValueNode(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
int BST:: height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(height(node->left), height(node->right)) + 1;
}

bool BST::isAVL(TreeNode* root){
    if (root == nullptr){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right)) {
            return true;
        }

        return false;
}


void BST:: generateRandomNumbers(int numNumbers) {
       for (int i = 0; i < numNumbers; i++) {
           int randomNumber = rand() % 100;

           NumberNode* newNode = new NumberNode(randomNumber);
           if (numberList == nullptr) {
               numberList = newNode;
               tail = newNode;
           } else {
               tail->next = newNode;
               tail = newNode;
           }

           root = insertNode(root, randomNumber);
       }
   }
