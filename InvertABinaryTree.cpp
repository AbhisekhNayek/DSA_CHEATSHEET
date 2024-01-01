typedef TreeNode<int> * t;

void s(t r, t p, t l, bool& q, t& ans){

    if(!r){

        return;

    }

    if(r->data==l->data){

        r->left=p;

        q=1;

        ans=r;

        return;

    }

    s(r->left, r, l, q, ans);

    if(q){

      

            r->left=p;

       return;

    }

    s(r->right, r, l, q, ans);

    if(q){

       if(r->left){

           r->right=r->left;

       }

       else{

           r->right=NULL;

       }

            r->left=p;

            return;

       

    }

}

TreeNode<int> * invertBinaryTree(TreeNode<int> *r, TreeNode<int> *l)

{

    // Write your code here.

    bool q=0;

    t ans=NULL;

    s(r, NULL, l, q, ans);

    return ans; 

}
