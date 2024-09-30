class Solution {
  public:
    void markParent(Node* root, unordered_map<Node*,Node*> &umap,Node* &tar, int target){
        if(root==NULL) return;
        if(root->data == target) tar = root;
        if(root->left){
            umap[root->left] = root;
        }
        if(root->right){
            umap[root->right] = root;
        }
        markParent(root->left,umap,tar,target);
        markParent(root->right,umap,tar,target);
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> umap;
        Node* tar;
        markParent(root,umap,tar,target);
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        vis[tar] = true;
        q.push(tar);
        int time = 0;
        while(!q.empty()){
            int count = q.size();
            time++;
            for(int i=0;i<count;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push({node->left});
                    vis[node->left] = true;
                } 
                if(node->right && !vis[node->right]){
                    q.push({node->right});
                    vis[node->right] = true;
                }
                if(umap.find(node)!=umap.end() && !vis[umap[node]]){
                        q.push({umap[node]});
                        vis[umap[node]] = true;
                }
            }
        }
        return time-1;
    }
};
