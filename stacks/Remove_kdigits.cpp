class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;

        for(char digit : num){
            while(!s.empty()&& k>0 && s.top()>digit){
                s.pop();
                k--;
            } 
            s.push(digit);
        }
        while(k>0 && !s.empty()) {
            s.pop();
            k--;
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }

        reverse(res.begin(), res.end());

        size_t pos = res.find_first_not_of('0');
        res = (pos== std::string ::npos) ? "0" : res.substr(pos);
        return res;
    }
};
