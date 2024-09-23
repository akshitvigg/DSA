
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heig(root, diameter);
        return diameter;
    }
    public:
    int heig(TreeNode* root, int& diameter){
        if(root==nullptr){
            return 0 ;
        }
        int lef =  heig(root->left, diameter);
        int rig = heig(root->right, diameter);
        diameter = max(diameter, lef+rig);
        return 1+max(lef,rig);
    }
};
