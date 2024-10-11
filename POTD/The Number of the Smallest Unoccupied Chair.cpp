class Solution {
public:
    typedef pair<int, int>p;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<p, vector<p>,greater<p>> occupied;
        priority_queue<int ,vector<int>,greater<int>> free;

        int targetarrival  = times[targetFriend][0];

        sort(times.begin(), times.end());

        int chairNo = 0;

        for(int i=0; i<n; i++){
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty ()&& occupied.top().first<=arrival){
                free.push(occupied.top().second);
                occupied.pop();
            }
            if(free.empty()){
                occupied.push({depart,chairNo});
                if(arrival==targetarrival){
                    return chairNo;
                }
                chairNo++;
            }else{
                int least = free.top();
                free.pop();
                if(arrival==targetarrival){
                    return least;
                }
                occupied.push({depart,least});
            }
        }
        return -1;      
    }
};
