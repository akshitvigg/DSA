class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto it: s){
            if(it=='[' || it=='{'||it=='(') st.push(it);
            else{
                if(st.size()==0) return false;
                char ch = st.top();
                st.pop();
                if((it==')' && ch =='(') or (it=='}'&& ch=='{') or (it==']' && ch=='[')) continue;
                else return false;
            }
        }
        return st.empty();
        
    }
};
