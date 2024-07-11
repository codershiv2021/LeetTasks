class MyStack {
public:
    queue<int>q; queue<int>qt;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        return;
    }
    
    int pop() {
        //2 3 4 5 
        int n = q.size();
        int ans = q.back();
        n--;
        while(n--){
            qt.push(q.front());
            q.pop();
        }
        q.pop();
        while(!qt.empty()){
            q.push(qt.front());
            qt.pop();
        }
        return ans;
    }
    
    int top() {
        // int n = q.size();
        // int ans = -1;
        // while(n--){
        //     ans = q.front();
        //     qt.push(q.front());
        //     q.pop();
        // }
        
        // while(!qt.empty()){
        //     q.push(qt.front());
        //     qt.pop();
        // }
        return q.back();
    }
    
    bool empty() {
        return (q.empty());
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