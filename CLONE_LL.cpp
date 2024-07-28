/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void inserti(Node* head){
        Node* temp = head;
        while(temp!=nullptr){
            Node* nextele = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextele;
            temp->next = copy;

            temp=nextele;
        }
    }
    void copyRandom(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy = temp->next;
            if(temp->random){
                 copy->random = temp->random->next;
            }else{
                copy->random=NULL;
            }
            temp=temp->next->next;
        }
    }

    Node* nextpoint(Node* head){
        Node* temp = head;
        Node* dummn = new Node(-1);
        Node* res = dummn;
        while(temp!=nullptr){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp=temp->next;
        }
        return dummn->next;
    }
    Node* copyRandomList(Node* head) {
        inserti(head);
        copyRandom(head);
        
        return nextpoint(head);
    }
};
