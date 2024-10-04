
class Solution {
private:
    TreeNode* prev = nullptr; 

public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }


        flatten(root->right);
    
        flatten(root->left);


        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};


