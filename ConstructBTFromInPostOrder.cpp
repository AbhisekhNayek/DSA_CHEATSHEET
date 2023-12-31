#include<map>

void createMapping(vector<int> inOrder, map<int,int> &nodeToIndex, int n){

        for(int i=0;i<n;i++){

            nodeToIndex[inOrder[i]]=i;

        }

    }

 

 TreeNode<int> *solve(vector<int> &inOrder, vector<int> &postorder,int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> &nodeToIndex){

        if(index<0 || inOrderStart > inOrderEnd){

            return NULL;

        }

        int element = postorder[index--];

        TreeNode<int> *root= new TreeNode<int>(element);

        int position =nodeToIndex[element];

        root->right=solve(inOrder,postorder,index,position+1,inOrderEnd,n,nodeToIndex);

        root->left=solve(inOrder,postorder,index,inOrderStart,position-1,n,nodeToIndex);

        return root;

    }

 

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){

      int n=inOrder.size();

    int postOrderIndex=n-1;

    map<int,int> nodeToIndex;

    createMapping(inOrder,nodeToIndex,n);

    TreeNode<int> *ans=solve(inOrder,postOrder,postOrderIndex,0,n-1,n,nodeToIndex);

    return ans;

}
