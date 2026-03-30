class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length()-1;
        while(l<=r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string sol = "";
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                string newSub = s.substr(i, j-i+1);
                if(isPalindrome(newSub) && newSub.length() > sol.length()){
                    sol = newSub;
                }
            }
        }
        return sol;
    }
};
