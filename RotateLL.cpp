  class Solution {
public:
    ListNode* kthnode(ListNode* temp , int k){
        int cnt=1;
        while(temp!=nullptr){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode* tail = head;
        int len=1;
        while(tail->next!=nullptr){
            tail = tail->next;
            len++;
        }
        if(k%len==0) return head;
        k = k%len;

        tail->next = head;
        ListNode* newnode = kthnode(head , len-k);
        head = newnode->next;
        newnode->next=nullptr; 
           return head;
    }
 
};
