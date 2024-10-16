class Solution {
public:
    typedef pair<int , char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p, vector<p>> pq;

        if(a>0){
            pq.push({a, 'a'});
        }
        if(b>0){
            pq.push({b ,'b'});
        }if(c>0){
            pq.push({c ,'c'});
        }
        string res = "";

        while(!pq.empty()){
            int currCnt  = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(res.length()>=2 && res[res.length()-1]==currChar && res[res.length()-2]==currChar){
                if(pq.empty()){
                    break;
                }
                int nxtCnt = pq.top().first;
                int nxtChar = pq.top().second;
                pq.pop();

                res.push_back(nxtChar);
                nxtCnt--;
                if(nxtCnt>0){
                    pq.push({nxtCnt, nxtChar});
                }
            }else{
                res.push_back(currChar);
                currCnt--;

            }if(currCnt>0){
                pq.push({currCnt, currChar});
            }
        }
        return res;
    }
};
