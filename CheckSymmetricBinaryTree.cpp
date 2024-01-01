#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isSymmetricUtil(node * root1, node * root2) {
  if (root1 == NULL || root2 == NULL)
    return root1 == root2;
  return (root1 -> data == root2 -> data) && isSymmetricUtil(root1 -> left, root2->
  right) && isSymmetricUtil(root1 -> right, root2 -> left);
}
bool isSymmetric(node * root) {
  if (!root) return true;
  return isSymmetricUtil(root -> left, root -> right);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(2);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(3);

  bool res;
  res = isSymmetric(root);

  if (res)
    cout << "The tree is symmetrical";
  else cout << "The tree is NOT symmetrical";

  return 0;
}
