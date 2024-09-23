
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*>    q;
        q.push(root);
        bool leftoright = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>row(size);
            
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                int ind = (leftoright) ? i: (size-1-i);

                row[ind] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftoright = !leftoright;
            res.push_back(row);
        }
        return res;
        
    }
};
