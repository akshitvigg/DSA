class Solution {
public:
    vector<int>res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
    
    
};
