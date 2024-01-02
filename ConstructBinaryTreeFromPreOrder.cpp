TreeNode *solve(vector<int>&pre,int s,int e)
{
    if(s>e)return NULL;
    TreeNode *r=new TreeNode(pre[s]);

    int root=r->data;
 int i=s+1; //root next is start of its left
    while(i<=e && pre[i]<root)i++;

    r->left = solve(pre,s+1,i-1);
    r->right =solve(pre,i,e);

    return r;
}
TreeNode *preOrderTree(vector<int> &pre)
{
    return solve(pre,0,pre.size()-1);
}
