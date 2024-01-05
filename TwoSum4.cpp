class bst {
    std::stack<BinaryTreeNode<int>*> st;
    bool reverse;
public:
    bst(BinaryTreeNode<int>* root, bool x) {
        reverse = x;
        pushall(root);
    }

    void pushall(BinaryTreeNode<int>* root) {
        BinaryTreeNode<int>* temp = root;
        while (temp) {
            st.push(temp);
            if (reverse) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
    }

    bool has_next() {
        return !st.empty();
    }

    int next() {
        if (!has_next()) {
            return -1; // Return a sentinel value if there are no more elements
        }

        BinaryTreeNode<int>* cur = st.top();
        st.pop();

        if (reverse) {
            pushall(cur->left);
        } else {
            pushall(cur->right);
        }

        return cur->data;
    }
};

bool pairSumBst(BinaryTreeNode<int>* root, int k) {
    bst l(root, false);
    bst r(root, true);

    int a = l.next();
    int b = r.next();

    while (a != -1 && b != -1 && a < b) {
        int sum = a + b;
        if (sum == k) {
            return true;
        } else if (sum < k) {
            a = l.next();
        } else {
            b = r.next();
        }
    }
    return false;
}
