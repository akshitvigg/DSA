class Solution {
public:
    int bb(vector<int>& nums,int k){
        int l=0, r=0, maxl=0, sum=0,cnt=0;
        while(r<nums.size()){
           
            sum+=nums[r]%2;

            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;       
    } 
    int numberOfSubarrays(vector<int>& nums, int k) {
         return bb(nums,k)-bb(nums,k-1);
    }
};
