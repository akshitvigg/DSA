class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
          
        int hidari= maxDepth(root->left);
        int migi = maxDepth(root->right);
        return  1+max(hidari, migi);
    
    
    }
   
};
        
