
class Solution {
    void markparent( TreeNode* root, unordered_map<TreeNode* ,TreeNode* >&parent_track, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
public:
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode* >parent_track;
        markparent(root,parent_track,target);

        unordered_map<TreeNode* , bool>visi;
        queue<TreeNode*> q;
        q.push(target);
        visi[target]=true;
        int d = 0;
        while(!q.empty()){
            int size = q.size();
            if(d++==k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left &&!visi[curr->left]){
                    q.push(curr->left);
                    visi[curr->left]=true;
                }
                if(curr->right&&!visi[curr->right]){
                    q.push(curr->right);
                    visi[curr->right]=true;
                }
                 if(parent_track[curr]&&!visi[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visi[parent_track[curr]]=true;
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            res.push_back(curr->val);
        }
        return res;
        
    }
};
