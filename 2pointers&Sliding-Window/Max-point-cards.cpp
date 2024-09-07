class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum = 0, rsum=0, maxsum=0;
        for(int i = 0; i<=k-1; i++){
            lsum+=arr[i];
           
        }
        maxsum=lsum;
        int n=arr.size();
        int rind = n-1;
        for(int i=k-1; i>=0; i--){
            lsum-=arr[i];
            rsum+=arr[rind];
            rind--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;

        
    }
};
