class Solution {
public:
    string getPalindrome(string s, int i, int j){
        int l = i;
        int r = j;
        string sub = "";
        while(l>=0 && r<s.length()){
            if(s[l] != s[r]){
                break;
            }
            sub = s.substr(l, r-l+1);
            l--;
            r++;
        }
        return sub;
    }
    string longestPalindrome(string s) {
        string sol = "";
        for(int i=0; i<s.length(); i++){
            string st = "";
            // for odd result
            string sub = getPalindrome(s, i, i);
            // for even result
            string sub1 = getPalindrome(s, i, i+1);
            sub.length()>sub1.length() ? st=sub : st=sub1;
            if(st.length() > sol.length()){
                sol = st;
            }
        }
        return sol;
    }
};
