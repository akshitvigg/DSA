class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(begin(points), end(points));

        vector<int> prev = points[0];
        int arrows = 1;
    
        for(int i=1 ; i<n ; i++){
            int currentStart = points[i][0];
            int currentEnd = points[i][1];

            int prevStart = prev[0];
            int prevEnd = prev[1];

          

            if(currentStart>prevEnd){
                arrows++;
                prev = points[i];
            }else{
                prev[0] = max(prevStart,currentStart);
                prev[1]= min(prevEnd,currentEnd);
            }
        }
        return arrows;
        
    }
};
