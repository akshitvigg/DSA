class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookie) {
        sort(child.begin(),child.end());
        sort(cookie.begin(),cookie.end());
        int l=0, r=0;
        while(l<cookie.size() && r<child.size()){
            if(cookie[l]>=child[r]){
               r++;
            }
            l++;

        }
        return r;
    }
};
