class MyHashSet {
public:
    TreeNode* root;

    MyHashSet() {
        root = NULL;
    }
    
    void add(int key) {
        if (root == NULL) {
            root = new TreeNode(key);
            return;
        }
        TreeNode *prev, *curr = root;
        while (curr != NULL) {
            if (key == curr->val) {
                return;
            }
            prev = curr;
            curr = key > curr->val ? curr->right : curr->left;
        }
        if (key > prev->val) {
            prev->right = new TreeNode(key);
        } else {
            prev->left = new TreeNode(key);
        }
    }
    
    void remove(int key) {
        if (root == NULL) {
            return;
        }
        if (key == root->val) {
            root = removeTreeNode(root);
        }
        TreeNode *prev, *curr = root;
        while (curr != NULL) {
            if (key == curr->val) {
                if (key > prev->val) {
                    prev->right = removeTreeNode(prev->right);
                } else {
                    prev->left = removeTreeNode(prev->left);
                }
                return;
            }
            prev = curr;
            curr = key > curr->val ? curr->right : curr->left;
        }
    }
    
    bool contains(int key) {
        if (root == NULL) {
            return false;
        }
        TreeNode *prev, *curr = root;
        while (curr != NULL) {
            if (key == curr->val) {
                return true;
            }
            prev = curr;
            curr = key > curr->val ? curr->right : curr->left;
        }
        return false;
    }

    TreeNode* removeTreeNode(TreeNode* curr)
    {
        if (curr->left == NULL) {
            return curr->right;
        }
        if (curr->right == NULL) {
            return curr->left;
        }
        TreeNode* tmp = curr->left;
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }
        tmp->right = curr->right;
        return curr->left;
    } 
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */