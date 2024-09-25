class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root ==nullptr || testSymm(root->left, root->right);   
    }
    bool testSymm(TreeNode* left, TreeNode* right){
        if(left==nullptr || right==nullptr) return left==right;

        if(left->val!=right->val) return false;
        return testSymm(left->left,right->right)&&testSymm(left->right,right->left);
    }
};
