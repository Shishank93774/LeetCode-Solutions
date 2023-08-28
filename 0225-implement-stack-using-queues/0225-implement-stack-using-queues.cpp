class MyStack {
    queue<int> mainQ;
    queue<int> helperQ;
public:
    MyStack() {
        mainQ = queue<int>();
        helperQ = queue<int>();
    }
    
    void push(int x) {
        if(mainQ.empty()){
            mainQ.push(x);
        }else{
            while(!mainQ.empty()){
                helperQ.push(mainQ.front()); mainQ.pop();
            }
            mainQ.push(x);
            while(!helperQ.empty()){
                mainQ.push(helperQ.front()); helperQ.pop();
            }
        }
    }
    
    int pop() {
        int x = mainQ.front(); mainQ.pop();
        return x;
    }
    
    int top() {
        return mainQ.front();
    }
    
    bool empty() {
        return mainQ.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */