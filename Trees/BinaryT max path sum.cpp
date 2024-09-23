
class Solution {
public:
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN;
       findmaxsum(root, maxi);
       return maxi; 
    }
    private:
    int findmaxsum(TreeNode* root , int &maxi){
        if(root==nullptr) return 0;

        int leftsum = max(0,findmaxsum(root->left, maxi));
        int rightsum = max(0,findmaxsum(root->right, maxi));
        maxi = max(maxi,(leftsum+rightsum+root->val));
        return root->val + max(leftsum, rightsum);

    }
};
