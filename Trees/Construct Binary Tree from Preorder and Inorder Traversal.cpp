class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int> inMap;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root = buildTree(preorder,0, preorder.size()-1, inorder,0,inorder.size()-1,inMap);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder,int prestart,int prend,vector<int>& inorder,int instart,int inend, map<int,int>&inMap){
        if(prestart>prend || instart>inend) return nullptr;
        TreeNode* root =   new TreeNode (preorder[prestart]);

        int inroot = inMap[root->val];
        int numsLeft = inroot-instart;

        root->left = buildTree(preorder, prestart+1,prestart+numsLeft,inorder, instart, inroot-1,inMap);
        root->right = buildTree(preorder, prestart+numsLeft+1,prend,inorder, inroot+1, inend,inMap);
        return root;
    }
};
