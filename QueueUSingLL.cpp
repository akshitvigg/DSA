void MyQueue:: push(int x)
{
    QueueNode* temp = new QueueNode(x);
    if(front==nullptr){
        front=temp;
        rear = temp;
    }else{
        rear->next = temp;
        rear = temp;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==nullptr){
       return -1;
        
    }else{
    int value = front->data;
    QueueNode* temp = front;
    front = front->next;
    delete(temp);
    return value;
    }
  
}
