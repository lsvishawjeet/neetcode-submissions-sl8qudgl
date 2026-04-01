class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // seems to be topo sort problem
        // first create the adj vector
        unordered_map<char, vector<char>> mp;
        unordered_map<char, int> indegree;
        
        for(auto &word : words){
            for(char c : word){
                indegree[c] = 0;
            }
        }

        for(int i = 0; i < words.size()-1; i++){
            bool mismatchFound = false;
            for(int j = 0; j<min(words[i].length(), words[i+1].length()); j++){
                if(words[i][j] != words[i+1][j]){
                    mismatchFound = true;
                    mp[words[i][j]].push_back(words[i+1][j]);
                    indegree[words[i+1][j]]++;
                    break;
                }
            }
            if(!mismatchFound && words[i].length() > words[i+1].length()) return "";
        }
        
        // kahns algorithm
        queue<char> bfs;
        string sol = "";
        // take elements with indegree 0 and push to bfs queue
        for(auto &it : indegree){
            if(it.second == 0){
                bfs.push(it.first);
            }
        }
        while(!bfs.empty()){
            char frontEl = bfs.front();
            bfs.pop();
            sol += frontEl;
            // now visit all the elements to which it goes
            
            for(char el : mp[frontEl]){
                indegree[el]--;
                if(indegree[el] == 0){
                    bfs.push(el);
                }
            }
        }

        if(sol.length() != indegree.size()) return "";
        return sol;

    }
};
