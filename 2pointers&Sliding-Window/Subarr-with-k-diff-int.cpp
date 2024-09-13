class Solution {
public:
    int su(vector<int>& str, int k) {
        int l = 0,r=0, cnt=0;
        int n = str.size();
        unordered_map<int,int> m;

        while(r<n){
             m[str[r]]++;

            while(m.size()>k){
                m[str[l]]--;
                if(m[str[l]]==0){
                    m.erase(str[l]);
                }
                l++;    
            }
            if(m.size()<=k){
                cnt+=r-l+1;
              
            }
            r++;
        
    
          
      
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& str, int k) {
    return su(str,k)-su(str,k-1);
    }
};
