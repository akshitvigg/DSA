class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* el = new StackNode(x);
        el->next= top;
        top = el;

        }

    int pop() {
        if(top==nullptr) return -1;
        int Topdata =top->data ;
        StackNode* temp = top;
        top = top->next;
        delete(temp);
      
        return Topdata;
    }

    MyStack() { top = NULL; }
};
