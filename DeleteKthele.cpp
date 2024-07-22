#include <iostream>
using namespace std;
#include <vector>
class Node {
public:
    int data;        
    Node* next;
    Node* back;

    
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back=back1;
    }

  
    Node(int data1) {
        data = data1;
        next = nullptr;
        back= nullptr;
    }
};

Node* convertArr2dll(vector<int>arr){
  if(arr.empty()){
    return nullptr;
  }
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i =1; i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    temp->back = mover; 
    mover = temp;
    
  }  
  return head;
}

void  print(Node* head){
  while(head!=nullptr){
    cout<<head->data<<" ";
    head= head->next;
  }
  cout<<endl;
  
}
Node* deleteHEad(Node* head){
  if(head==nullptr||head->next==nullptr){
    return nullptr;
  }  
  Node* prev=head;
  head = head->next;

  head->back=nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}  

Node* deleteT(Node* head){
  if(head==nullptr||head->next==nullptr){
    return nullptr;
  }  
  Node* tail=head;
  while(tail->next!=nullptr){
      tail = tail->next;
  }
  Node* prev=tail->back;
  prev->next=nullptr;
  tail->back=nullptr;
  delete tail;
    
  return head;
}  

Node* deletKnode(Node* head, int k){
  if(head==nullptr){
    return nullptr;
  }
  int cnt= 0;
  Node* knode = head;
  while(knode!=nullptr){
    cnt++;
    if(cnt==k) break;
    knode = knode->next;
  }
  Node* prev = knode->back;
  Node* front = knode->next;
  if(prev==nullptr && front==nullptr){
    return nullptr;
  }else if(prev==nullptr){
    return deleteHEad(head);
  }else if(front==nullptr){
    return deleteT(head);
  }
  prev->next = front;
  front->back = prev;

  knode->next = nullptr;
  knode->back=nullptr;

  delete knode;
  return head;
  
}

int main() {

  vector<int>arr = {7,4,3,2};
  Node* head = convertArr2dll(arr);

  head = deletKnode(head,4);
  print(head);

    

    return 0;
}
