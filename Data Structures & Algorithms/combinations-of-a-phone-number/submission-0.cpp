class Solution {
private:
    map<char, string> digitMap;
    void addToDigitMap(){
        digitMap['1'] = "";
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
    }
public:
    // digits to get the string from map
    // here i required as index of digit 
    void backTrack( vector<string>& sol, string digits, string & temp, int i){
        if(i>=digits.length()){
            sol.push_back(temp);
            return;
        }
        for(int m=0; m<digitMap[digits[i]].length(); m++){
            temp += digitMap[digits[i]][m];
            backTrack(sol, digits, temp, i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        addToDigitMap();
        vector<string> sol;
        if(digits.length()==0) return sol;
        string temp;
        backTrack(sol, digits, temp, 0);
        return sol;
    }
};
