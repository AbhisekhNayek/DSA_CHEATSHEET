class BSTiterator{

private:
stack<TreeNode<int> *>s;

public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

 

    int next()
    {

       TreeNode<int> * temp = s.top();

        s.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !s.empty();
    }

private:

    void pushAll(TreeNode<int> * node){

        while (node != NULL) {
          s.push(node);
          node = node->left;

        }
    }
};
