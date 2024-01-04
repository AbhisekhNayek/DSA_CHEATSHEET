#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    if(root->left && root->val > X)
    return floorInBST(root->left, X);
    
    //clearly if root->data is already equal to X we will not be able to find a better ans :
    if(root->val == X) 
    return root->val;

    if(root->val<X){
        //this will become our default ans :
        int ans=root->val;
        if(root->right){
            //in search of a better ans from the right subtree :
            auto it=floorInBST(root->right, X);
            if (it <= X) {
              ans = it;
            }
            }
        return ans;
    }
}
