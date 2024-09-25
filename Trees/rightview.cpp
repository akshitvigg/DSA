
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root, 0 ,res);
        return res;
        
    }
    public:
    void recursion( TreeNode* node, int level, vector<int>& res){
        if(node==nullptr) return;
        if(level==res.size()) res.push_back(node->val);
        recursion(node->right, level+1, res);
        recursion(node->left , level+1 ,res);
    }
};
