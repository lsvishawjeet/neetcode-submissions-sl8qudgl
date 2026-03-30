class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        vector<int> c;
        int end = 0;
        int start = 0;
        for(int i = 0; i<s.length(); i++){
            freq[s[i]]--;
            end = i;
            if(freq[s[end]] == 0){
                bool isTrue = false;
                for(int j = start; j<=end; j++){
                    if(freq[s[j]] != 0){
                        isTrue = true;
                        break;
                    }
                }
                if(isTrue) continue;
            } else{
                continue;
            }
            c.push_back(end-start+1);
            start = end+1;
        }
        return c;
    }
};
