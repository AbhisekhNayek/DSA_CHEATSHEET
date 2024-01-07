#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void solve(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &prev1,BinaryTreeNode<int>* &head)
{
    if(!root) return;
    solve(root->left,prev1,head);

    if(prev1==NULL) {
        head = root;
    }
    else {
        root->left = prev1;
        prev1->right = root;
    }
    prev1 = root;

    solve(root->right,prev1,head);
}


BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev1 = NULL;
    solve(root,prev1,head);
    return head;
}
