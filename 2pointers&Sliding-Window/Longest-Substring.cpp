class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        vector<int> charIndex(128, -1);
        int left=0;
        for(int right =0; right<n; right++){
            if(charIndex[s[right]]>=left){
                left=charIndex[s[right]]+1;

            }
            charIndex[s[right]]=right;
            maxlen = max(maxlen, right-left+1);

        }
        return maxlen;
        
    }
};
