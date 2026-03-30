class Solution {
public:
    bool alphaNum(char c){
        return (c >= 'A' && c <= 'Z'||
                c >= 'a' && c <= 'z'||
                c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            while(i<j && !alphaNum(s[i])){
                i++;
            }
            while(j>i && !alphaNum(s[j])){
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
