
class BSTIterator {
    private: stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        pushAll(node->right);
        return node->val;        
    }
    
    bool hasNext() {
        return !s.empty();
        
    }
    void pushAll(TreeNode* node){
        for( ; node!=nullptr; s.push(node), node = node->left);
    }
};

