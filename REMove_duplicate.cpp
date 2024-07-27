
class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* temp = head ;
        while(temp!=nullptr && temp->next!=nullptr){
            Node* nextnode = temp->next;
            
            while(nextnode!=nullptr && nextnode->data== temp->data){
                Node* dup = nextnode;
                nextnode = nextnode->next;
                delete(dup);

            }
            temp->next = nextnode;
            if(nextnode) nextnode->prev = temp;
            temp=temp->next;
        }
        return head;
    }
};
