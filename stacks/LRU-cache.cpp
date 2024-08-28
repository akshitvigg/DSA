class Node
{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node (int key , int val){
        this->key = key;
        this->val = val;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int ,Node*>m;
    Node* head  = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node){
        Node* pre = node->prev;
        Node* aftnode = node->next;
        pre->next = aftnode;
        aftnode->prev = pre;
    }
    void addNode(Node* newnode){
        Node* temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        newnode->prev = head;
        temp->prev = newnode;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        Node* node = m[key];
        deleteNode(node);
        addNode(node);
        m[key]=head->next;
        return head->next->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* c = m[key];
            deleteNode(c);
            c->val = value;
            addNode(c);
            m[key]=head->next;
        }
        else{
            if(m.size()==size){
                Node* prev = tail->prev;
                deleteNode(prev);
                Node* l = new Node(key,value);
                addNode(l);
                m.erase(prev->key);
                m[key]=head->next; 
            }else{
                Node* l = new Node(key,value);
                addNode(l);
                m[key]=head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
