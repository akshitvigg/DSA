class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int tar =1;
        for(int n : nums){
            if(n>0 && n==tar){
                tar++;
            }else if(n>tar){
                return tar;
            }
        }return tar;
        
    }
};
