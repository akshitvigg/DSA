class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>maxind) return false;
            maxind = max(maxind, i+nums[i]);
        }
        return true;
        
    }
};
