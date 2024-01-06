/************************************************************

 

    Following is the TreeNode class structure

 

    template <typename T>

    class TreeNode {

       public:

        T data;

        TreeNode<T> *left;

        TreeNode<T> *right;

 

        TreeNode(T data) {

            this->data = data;

            left = NULL;

            right = NULL;

        }

    };

 

************************************************************/

 

string serializeTree(TreeNode<int> *root)

{

 //    Write your code here for serializing the tree

    if(!root) return "";

    queue<TreeNode<int>*> q;

    string s = "";

    q.push(root);

    while(!q.empty()){

        TreeNode<int>* currNode = q.front();

        q.pop();

        if(currNode == NULL){

            s.append("#,");

        }

        else{

            s.append(to_string(currNode->data)+",");

        }

        if(currNode!=NULL){

            q.push(currNode->left);

            q.push(currNode->right);

        }

    }

    return s;

 

}

 

TreeNode<int>* deserializeTree(string &s)

{

 //    Write your code here for deserializing the tree

    if(s.size() == 0) return NULL;

 

    stringstream x(s);

    string st;

    getline(x,st,',');

    queue<TreeNode<int>*> q;

    TreeNode<int>* temp = new TreeNode<int>(stoi(st));

    q.push(temp);

 

    while(!q.empty()){

        auto top = q.front();

        q.pop();

        getline(x,st,',');

        top->left = st=="#"?NULL:new TreeNode<int>(stoi(st));

        if(st!="#")

        q.push(top->left);

        getline(x,st,',');

        top->right = st=="#"?NULL:new TreeNode<int>(stoi(st));

         if(st!="#")q.push(top->right);

 }

 

 return temp;

 

}
