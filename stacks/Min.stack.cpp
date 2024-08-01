class MinStack {
    stack <long long> st;
    long long mini;
public:
    MinStack() {
       while(st.empty()==false) st.pop();
       mini = INT_MAX;
    }
    
    void push(int val) {
        long long va = val;
        if(st.empty()){
            mini = va;
            st.push(va);
        }else{
            if(va<mini){
                st.push(2*va-mini);
                mini = va;
            }
            else
            st.push(va);
        }
     
        
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();

        if(el<mini){
            mini = 2*mini-el;     
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long el =st.top();
        if(el<mini) {
            el  = mini;
            
        }
        return el;
        
    }
    
    int getMin() {
        return mini;
        
    }
};

