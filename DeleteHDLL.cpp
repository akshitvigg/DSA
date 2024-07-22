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


int main() {

  vector<int>arr = {7,4,3,2};
  Node* head = convertArr2dll(arr);

  head = deleteHEad(head);
  print(head);

    

    return 0;
}
