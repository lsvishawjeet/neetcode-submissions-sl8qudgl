class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> mp;
        vector<vector<string>> sol;

        for(int i=0; i<strs.size(); i++){
            string strsI = strs[i];
            sort(strsI.begin(), strsI.end());
            mp[strsI].push_back(strs[i]);
        }

        for(auto &it : mp){
            sol.push_back(it.second);
        }

        return sol;
        
    }
};
