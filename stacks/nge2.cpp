class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n,-1);
        stack<int>s;
        for(int i=2*n-1; i>=0; i--){
            while(!s.empty()&& s.top()<=nums[i%n]){
                s.pop();
            }
            if(i<n){
                if(!s.empty()){
                    result[i] =s.top();
                }

            }
            s.push(nums[i%n]);
        }
        return result;
    }
};
