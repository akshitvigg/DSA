
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root)!=-1;
    }
    int check(TreeNode* root){
        if(root ==nullptr) return 0;

        int lef = check(root->left);
        if(lef==-1) return -1;
        int righ = check(root->right);
        if(righ ==-1) return -1;
        if(abs(lef-righ)>1) return -1;
        return max(lef, righ)+1;
    }
};
