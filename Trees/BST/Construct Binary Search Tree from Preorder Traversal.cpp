class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& Ar) {
        int i =0;
        return build (Ar, i , INT_MAX);
        
    }
    TreeNode* build(vector<int>& Ar, int &i, int bound){
        if(i==Ar.size()||Ar[i]>bound) return nullptr;
        TreeNode* root = new TreeNode (Ar[i++]);
        root->left  = build(Ar, i, root->val);
        root->right = build(Ar, i, bound);
        return root;
    }
};
