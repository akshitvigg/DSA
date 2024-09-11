class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxl=0, l=0, r=0,maxfr=0;
        int hash[26]={0};
        while(r<s.size()){
            hash[s[r]-'A']++;

            if(hash[s[r]-'A']>maxfr){
                maxfr = hash[s[r]-'A'];

            }if((r-l+1)-maxfr>k){
                hash[s[l]-'A']--;
                l++;
            }
            maxl = max(r-l+1,maxl);
            r++;

        }
        return maxl;
    }
};
