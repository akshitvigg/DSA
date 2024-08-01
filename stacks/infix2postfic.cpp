class Solution {
  public:

    int prec(char c){
        if(c=='^') return 3;
        if(c=='*'||c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
    string infixToPostfix(string s) {
        stack<char>st;
        string ans;
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            
            if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
                ans+=c;
            }
            
            else if(c=='('){
                st.push('(');
            }
            
            else if(c==')'){
                while(!st.empty()&& st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty ()&&prec(s[i])<=prec(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
          
        }
          while(!st.empty()){
                ans+=st.top();
                st.pop();
                
            }
            return ans;
            
        
 
    }
};
