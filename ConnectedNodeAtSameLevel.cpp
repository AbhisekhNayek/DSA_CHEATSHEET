void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        BinaryTreeNode<int>*prev=NULL;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>*node=q.front();
            q.pop();
            if(prev){
                prev->next=node;
            }
            prev=node;

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
}

