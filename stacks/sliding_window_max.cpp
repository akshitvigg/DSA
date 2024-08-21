class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        int i = 0,j = 0;
        while(j<n){
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1 == k){
                int ele = dq.front();
                if(nums[i] == ele){
                    dq.pop_front();
                }
                ans.push_back(ele);
                i++;
            }
            j++;
        }
        return ans;
    }
};
