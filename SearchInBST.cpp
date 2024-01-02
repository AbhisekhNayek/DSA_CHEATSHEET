bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root!=0) {  

   if(root->data==x) {
         return true;
    }
 
    if (root->data > x) {
         root = root->left;
    }

    else {
         root = root->right;
    }
}
return false;
}
