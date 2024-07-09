class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
    vector<int> result;
    map<int, int> freq;

    int mini = n / 3 + 1;

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
        if (freq[nums[i]] == mini) {
            result.push_back(nums[i]);
        }
        if (result.size() == 2) break;
    }

  
    result.clear();
    for (auto &entry : freq) {
        if (entry.second >= mini) {
            result.push_back(entry.first);
        }
    }

    return result;
}





    
    
};