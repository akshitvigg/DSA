class Solution {
public:
    static bool comp(vector<int>& a , vector<int> & b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), comp);
        int lastind = intervals[0][1];

        int cnt = 0;
        for(int i = 1;i<n; i++){
            if(intervals[i][0]<lastind){
                cnt++;
             
            }else{
                   lastind = intervals [i][1];
            }            
            
        }
        return cnt;
    }
};
