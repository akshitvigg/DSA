class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        Node* temp = *head;
        while(temp!=nullptr){
            if(temp->data==x){
                if(temp==*head){
                    *head=temp->next;
                }
                Node* nextnode= temp->next;
                Node* prev = temp->prev;
                
                if(nextnode!=nullptr) nextnode->prev= prev;
                if(prev!=nullptr) prev->next = nextnode;
                
                
                delete(temp);
                temp=nextnode;
            }else{
                temp=temp->next;
            }
          
        }
            
    }
};
