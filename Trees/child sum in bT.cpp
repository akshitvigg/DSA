class Solution {
public:
    int isSumProperty(Node *root) {
      
        if (root == NULL) return 1;

    
        if (root->left == NULL && root->right == NULL) return 1;

        int leftData = (root->left) ? root->left->data : 0;
        int rightData = (root->right) ? root->right->data : 0;


        if (root->data == leftData + rightData) {
  
            return isSumProperty(root->left) && isSumProperty(root->right);
        } else {
            return 0; 
        }
    }
};
