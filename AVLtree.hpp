//
//  CSDP 250 Project 5
//  Created by Isabelle Puwo on 11/25/23.
//

#ifndef AVLtree_hpp
#define AVLtree_hpp

#include <stdio.h>


class BST{
private:
    struct TreeNode {
        int data;
        TreeNode* parent;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    };
    struct NumberNode {
           int data;
           NumberNode* next;
           NumberNode(int value) : data(value), next(nullptr) {}
       };
    NumberNode* numberList;
    NumberNode* tail;
    TreeNode* root;
    TreeNode* insertNode(TreeNode* root, int);
    void inOrder(TreeNode* nodePtr);
    void postOrder(TreeNode* nodePtr);
    void deleteNode(TreeNode*& nodePtr, int);
    TreeNode* minValueNode(TreeNode* node);
    bool isAVLTree;
    int height(TreeNode* node);
    bool isAVL(TreeNode* nodePtr);
    void empty(TreeNode* nodePtr);
    
public:
    void inorderTraversal();
    void postOrderTraversal();
    void generateRandomNumbers(int);
    BST(): root(nullptr), isAVLTree(false){}
    void clearTree(){
        empty(root);
    }
    ~BST(){
        clearTree();
    }
    void addNode(int value){
        insertNode(root, value);
    }
    void removeNode(int value){
        deleteNode(root, value);
    }
    bool checkifAVL(){
        isAVLTree = isAVL(root);
        return isAVLTree;
    }
    
};
#endif /* AVLtree_hpp */
