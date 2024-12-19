class MinStack {
public:
    stack<int>st; vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (v.empty()){
            v.push_back(val);
        }
        else{
            if (v.back()>=val){
                v.push_back(val);
            }
        }
        
        return;
    }
    
    void pop() {
        if (st.top()==v.back()){
            v.pop_back();
        }
        st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return v.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */