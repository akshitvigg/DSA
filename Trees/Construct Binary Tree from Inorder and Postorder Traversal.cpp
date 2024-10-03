
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
           map<int , int> inMap;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root = Tree( inorder,0,inorder.size()-1,postorder,0, postorder.size()-1,inMap);
        return root;
        
    }
    TreeNode* Tree(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe, map<int,int>&inMap){
        if(is>ie || ps>pe) return nullptr;
        TreeNode* root =   new TreeNode (postorder[pe]);

        int inroot = inMap[root->val];
        int numsLeft = inroot-is;

        root->left = Tree(inorder, is, inroot-1,postorder,ps,ps+numsLeft-1,inMap);
        root->right = Tree(inorder, inroot+1,ie,postorder,ps+numsLeft, pe-1,inMap);
        return root;
    }
};
