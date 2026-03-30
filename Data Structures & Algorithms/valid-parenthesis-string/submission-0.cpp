class Solution {
public:
    bool checkValidString(string s) {
        stack<char> paran;
        stack<char> stars;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') {
                paran.push(i);
            } else if(s[i] == '*') {
                stars.push(i);
            } else{
                if(paran.empty() && stars.empty()) return false;
                if(!paran.empty()) {
                    paran.pop();
                } else{
                    stars.pop();
                }
            }
        }
        
        // now there are chances paran might have elements left
        while(!paran.empty() && !stars.empty()){
            if(paran.top() > stars.top()) return false;
            paran.pop();
            stars.pop();
        }
        return paran.empty();
    }
};
