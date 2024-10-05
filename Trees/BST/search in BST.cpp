
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            root=val>root->val ? root->right: root->left;
        }
        return root;
        
    }
};
