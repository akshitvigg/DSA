int findlen(Node* slow, Node* fast){
    int cnt=1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return findlen(slow,fast);
        }
    }
    return 0;
}
