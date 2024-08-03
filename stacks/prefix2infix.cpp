class Solution {
public:
    string preToInfix(string pre_exp) {
        stack<string> c;
                if (pre_exp.empty()) {
            throw invalid_argument("Prefix expression cannot be empty");
        }
        

        for(int i = pre_exp.size() - 1; i >= 0; i--) {
            char s = pre_exp[i];
            

            if((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                c.push(string(1, s));
            } else {
          
                if (c.size() < 2) {
                    throw invalid_argument("Invalid prefix expression: not enough operands for operator");
                }
                
                string top1 = c.top(); c.pop();
                string top2 = c.top(); c.pop();
                
            
                string final = '(' + top1 + s + top2 + ')';
                c.push(final);
            }

        if (c.size() != 1) {
            throw invalid_argument("Invalid prefix expression: mismatched operators and operands");
        }
        
        return c.top();
    }
};
