
class Solution {
public:
    Node* merge(Node* l1, Node* l2) {
        Node* dummyN = new Node(-1); // Dummy node to simplify edge cases
        Node* res = dummyN;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                res->next = l1; // Use 'next' to link nodes
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
        delete dummyN; // Free the dummy node
        return mergedHead;
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        Node* current = head;
        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* next = current->next;

                // Flatten the child list recursively
                Node* child = flatten(current->child);

                // Connect current node to the flattened child
                current->next = child;
                child->prev = current;
                current->child = nullptr;

                // Find the tail of the flattened child list
                Node* tail = child;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // Connect the tail of the flattened child list to the next node
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
