class Solution{

public:
    int floor(Node* root, int x) {
        if(root==nullptr)  return -1;
        
        int floor = -1;
        
        while(root){
            if(root->data==x){
                floor=root->data;
                return floor;
            }
            if(root->data<x){
                floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }
};
