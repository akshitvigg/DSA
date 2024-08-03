
class Solution {
  public:
    string preToPost(string p2p) {
        stack<string>s;
        
        if(p2p.empty()){
            throw invalid_argument("error");    
        }
        
        for(int i=p2p.size()-1; i>=0; i--){
            char c = p2p[i];
            
            if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                s.push(string(1,c));
            }else{
                 if (s.size() < 2) {
                    throw invalid_argument("Invalid prefix expression: not enough operands for operator");
                }
                string t = s.top(); s.pop();
                string t2 = s.top(); s.pop();
                string f = t+t2+c;
                s.push(f);
            }
        }
          if (s.size() != 1) {
            throw invalid_argument("Invalid prefix expression: mismatched operators and operands");
        }
        
        return s.top();
    }
};
