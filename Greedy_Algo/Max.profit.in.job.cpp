class Solution {
public:
    int memo[50000];
    int n;
    int getNext(vector<vector<int >>& arr,int  l , int currentIntEnd){
        int r = n-1;
        int res = n+1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(arr[mid][0]>=currentIntEnd){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>> & arr,int  i){
        if(i>=n){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int next = getNext(arr, i+1,arr[i][1]);
        int taken = arr[i][2]+solve(arr, next);
        int notaken = solve(arr,i+1);

        return memo[i] = max(taken , notaken);
    }    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       n = startTime.size();

        memset(memo, -1, sizeof(memo));

        vector<vector<int>> arr(n, vector<int>(3,0));

        for(int i = 0; i<n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];

            
        }
        auto comp = [&](auto& vec1, auto& vec2){
            return vec1[0]<vec2[0];
        };

        sort(begin(arr), end(arr), comp);

        return solve(arr , 0);
    }
};
