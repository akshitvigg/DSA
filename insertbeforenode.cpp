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

Node* insertBeforehead(Node* head, int val){
  Node* newHead = new Node(val,head,nullptr);
  head->back = newHead;

  return newHead;
  
}
Node* insertb4T(Node* head, int val){
  if(head->next==nullptr){
    return insertBeforehead(head,val);
  }
  Node* tail = head;
  while(tail->next!=nullptr){
    tail=tail->next;   
  }
  Node* prev = tail->back;
  Node* newNode = new Node(val, tail, prev);
  tail->back= newNode;
  prev->next = newNode;
  return head;   
}
Node* insertb4Kthnode(Node* head, int val,int k){
  if(k==1){
    return insertBeforehead(head,val);
  }Node* temp =head;
  if(temp->next==nullptr){
    return insertb4T(head, val);
  }int cnt=0;
  while(temp->next!=nullptr){
    cnt++;
    if(cnt==k) break;
    temp = temp->next;
  }
  Node* prev = temp->back;
  Node* newNode = new Node(val,temp,prev);
  prev->next = newNode;
  temp->back = newNode;
  return head;
  
  
}
Node* insertbeforenode(Node* node, int val){
  Node* prev = node->back;
  Node* newNode = new Node(val,node, prev);
  prev->next = newNode;
  node->back = newNode;
  return node;
}

int main() {

  vector<int>arr = {7,4,3,2};
  Node* head = convertArr2dll(arr);

  insertbeforenode(head->next->next,7);
  print(head);

    

    return 0;
}
