class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());

        for(int i=0; i<s2.length()-s1.length()+1; i++){
            string currString = "";
            for(int j=i; j<i+s1.length(); j++){
                currString += s2[j];
            }
            sort(currString.begin(), currString.end());
            if(currString == sortedS1) return true;
        }
        return false;
    }
};
