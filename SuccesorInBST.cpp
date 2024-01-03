/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)

{

int pred = -1;
int succ = -1;

TreeNode* temp = root;

while(root){

if(key >= root->data){
root= root->right;
}

else{
succ = root->data;
root= root->left;
}
}

 

while(temp){
if(key > temp->data){
pred = temp->data;
temp= temp->right;
}

else{
temp= temp->left;
}
}
return {pred,succ};
}
