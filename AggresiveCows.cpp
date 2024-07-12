class Solution {
public:
    bool canwePlace(vector<int> & baskets, int balls,int dist){
        int cntCows=1, last = baskets[0];
        for(int i=1; i<baskets.size(); i++){
            if(baskets[i]- last>=dist){
                cntBalls++;
                last=baskets[i];
            }if(cntBalls>=balls) return true;   
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(), position.end());
        int low=0, high = position[n-1] - position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canwePlace(position,m,mid)==true){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
        
    }
};
