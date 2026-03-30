class Solution {
public:
    bool isOpen(char a){
        if(a=='(' || a=='{'|| a=='['){
            return true;
        }
        return false;
    }
    bool doesMatch(char a, char b){
        if(a=='('&&b==')'|| a=='{'&&b=='}'|| a=='['&&b==']'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;

        for(char c:s){
            if(isOpen(c)){
                st.push(c);
            } else{
                if(!st.empty() && doesMatch(st.top(), c)){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
