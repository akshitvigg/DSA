class BSTIterator {
private:
    stack<TreeNode*> s;
    bool reverse;

public:
    // Constructor
    BSTIterator(TreeNode* root, bool isreverse) {
        reverse = isreverse;
        pushAll(root); // Initialize the stack with the root's subtree
    }
    
    // Get the next value
    int next() {
        TreeNode* node = s.top();
        s.pop();
        
        // Based on reverse flag, decide which subtree to push onto the stack
        if(reverse) {
            pushAll(node->left); // Move to left subtree in reverse mode
        } else {
            pushAll(node->right); // Move to right subtree in normal mode
        }
        
        return node->val;
    }
    
    // Check if there are more nodes
    bool hasNext() {
        return !s.empty();
    }
    
    // Push nodes onto the stack
    void pushAll(TreeNode* node) {
        while(node != nullptr) {
            s.push(node);
            if(reverse) {
                node = node->right; // In reverse mode, move to the right
            } else {
                node = node->left;  // In normal mode, move to the left
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true); 
        int i = l.next();  
        int j = r.next(); 

      
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }

        return false; 
    }
};
