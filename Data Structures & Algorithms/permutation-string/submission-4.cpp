class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);

        for(char c : s1){
            vec1[c-'a']++;
        }

        for(int i=0; i<s1.length(); i++){
            vec2[s2[i]-'a']++;
        }

        int i = 0;
        int j = s1.length()-1;

        while(j<s2.length()){
            if(vec1 == vec2) return true;
            vec2[s2[i]-'a']--;
            j++;
            vec2[s2[j]-'a']++;
            i++;
        }
        return false;
    }
};
