class Solution {
public:
    bool isOperation(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/") {
            return true;
        }
        return false;
    }
    int performOperation(string opr, int a, int b){
        if(opr=="+"){
            return a+b;
        } else if(opr=="-"){
            return a-b;
        } else if(opr=="*"){
            return a*b;
        } else if(opr=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0; i<tokens.size(); i++){
            if(isOperation(tokens[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result = performOperation(tokens[i],b,a);
                st.push(result);
            } else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};
