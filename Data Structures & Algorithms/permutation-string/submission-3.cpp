class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        
        for(char c : s1){
            freq[c]++;
        }

        for(int i=0; i<s2.length(); i++){
            unordered_map<char, int> temp;
            int count = 0;
            for(int j=i; j<s2.length(); j++){
                char c = s2[j];
                temp[c]++;
                if(freq.find(c) == freq.end() || freq[c] < temp[c] ){
                    break;
                }
                if(freq[c] == temp[c]){
                    count++;
                }
                if(count == freq.size()){
                    return true;
                }
                
            }

        }
        return false;
    }
};
