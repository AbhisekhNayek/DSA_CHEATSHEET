TreeNode<int>* helper(int s, int e,vector<int>&arr){

    if(s>e) return NULL;

    int mid=(s+e)/2;

    TreeNode<int>*root= new TreeNode<int>(arr[mid]);
    TreeNode<int>* rootLeft = helper(s,mid-1,arr);
    TreeNode<int>* rootRight = helper(mid+1,e,arr);

    root->left=rootLeft;
    root->right=rootRight;
    return root;

}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return helper(0,n-1,arr);
}
