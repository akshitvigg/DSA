
class StockSpanner {
public:
    int index;
    stack<pair<int ,int>> s;
    StockSpanner() {
    
        index = -1;
        
    }
    
    int next(int price) {
         index+=1;
        int ans;
        while(!s.empty()&& s.top().first<=price ){
            s.pop();
        }
        ans  = index - (s.empty()? -1 : s.top().second);
        s.push({price,index});
        return ans ;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
