class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0) return 0;

        int l=0, r=0, jump = 0;
        while(r<n-1){
            int farthest = 0;
            for(int i= l; i<=r;i++){
                farthest = max(farthest, i+nums[i]);

            }
            l =r+1;
            r = farthest;
            jump++;
        }
        return jump;
        
    }
};
