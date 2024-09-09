#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* jo(vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Node* removeHead(Node* head) {
//     if (head == nullptr) {
//         return head;
//     }
//     Node* temp = head;
//     head = head->next;
//     delete temp;
//     return head;
// }
// Node* removeTail(Node* head){
//     if(head==nullptr || head->next==nullptr) return nullptr;
//     Node*temp=head;
//     while(temp->next->next!=nullptr){
//         temp=temp->next;
//     }
//     delete temp->next;
//     temp->next=nullptr;
//     return head;
    
// }
Node* RemoveEle(Node* head, int el){
    if (head==nullptr) return head;
    if(head->data==el){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
 
        if(temp->data==el){
            prev->next= prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 4, 5, 6};
    Node* head = jo(arr);  

    head= RemoveEle(head, 6);
    print(head); 

 
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
