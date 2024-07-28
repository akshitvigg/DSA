
class Solution {
public:
    Node* merge(Node* l1, Node* l2) {
        Node* dummyN = new Node(-1); 
        Node* res = dummyN;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                res->next = l1;
                l1->prev = res;
                res = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2->prev = res;
                res = l2;
                l2 = l2->next;
            }
        }

        if (l1) {
            res->next = l1;
            l1->prev = res;
        } else {
            res->next = l2;
            if (l2) l2->prev = res;
        }

        Node* mergedHead = dummyN->next;
        if (mergedHead) mergedHead->prev = nullptr;
        delete dummyN; 
        return mergedHead;
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        Node* current = head;
        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* next = current->next;

      
                Node* child = flatten(current->child);

  
                current->next = child;
                child->prev = current;
                current->child = nullptr;


                Node* tail = child;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }


                tail->next = next;
                if (next != nullptr) {
                    next->prev = tail;
                }
            }
            current = current->next;
        }

        return head;
    }
};
