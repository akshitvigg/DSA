
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long minval , long maxval){
        if(root==nullptr) return true;
        if(root->val>=maxval || root->val<=minval)return false;
        return isValidBST(root->left,minval,root->val)&& isValidBST(root->right,root->val,maxval);
    }
};
