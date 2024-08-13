class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        long long res = 0;
        for(int i=0; i<a.size(); i++ ){
            int ma = a[i], mi = a[i];
            for(int j=i+1; j<a.size(); j++){
                ma = max(ma,a[j]);
                mi = min(mi,a[j]);
                res += (ma-mi);

            }
        }
        return res;
        
    }
};
