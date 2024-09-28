class MyCircularDeque {
    vector<int> deq;
    int n;
    int currsize ;
    int front ;
    int rear;
public:
    MyCircularDeque(int k) {
        n=k;
        front = 0;
        rear = n-1;
        deq = vector<int>(n,0);
        currsize = 0   ;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        front  = (front-1+n)%n;
        deq[front] = value;
        currsize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear = (rear+1)%n;
        deq[rear] = value;
        currsize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front+1)%n;
        currsize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear-1+n)% n;
        currsize--;       
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deq[front];
        
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return currsize==0 ;
    }
    
    bool isFull() {
        return currsize==n ;
        
    }
};

