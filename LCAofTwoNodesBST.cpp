/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{

    if(root==NULL){
            return NULL;
    }

    int x=P->data;
    int y=Q->data;

    if(root->data==x||root->data==y){
        return root;
    }

    if(x<root->data && root->data<y || x>root->data && root->data>y){
        return root;
    }

    else if(x<root->data && root->data>y){
        return LCAinaBST(root->left,P,Q);
    }

    else{
        return LCAinaBST(root->right,P,Q);
    }
}
