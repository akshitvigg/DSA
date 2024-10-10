
class Solution {
private:
    TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;

private:
    void inorder(TreeNode* root){
        if(root==nullptr) return ;
        inorder(root->left);
        if(prev!=nullptr &&(root->val <prev->val)){

            if(first==nullptr){
                first = prev;
                middle = root;
                
            }else{
                last = root;
            }
      
        } 
              prev=root;
            inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {

        first = middle = last =nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
        
    }
};
