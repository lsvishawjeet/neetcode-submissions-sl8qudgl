class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        cout<<"program of min stack";
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        } else{
            int topMin = st.top().second;
            if(topMin > val){
                st.push({val, val});
            } else{
                st.push({val, topMin});
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
    }
    
    int getMin() {
        if(!st.empty()){
            return st.top().second;
        }
    }
};
