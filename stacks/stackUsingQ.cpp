class MyStack {
public:
queue<int>q;


    MyStack() {
        
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
       int topElement = q.front();
        q.pop();
        return topElement;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
    }
};
