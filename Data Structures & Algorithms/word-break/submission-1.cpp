class Solution {
public:
    bool dfs(string s, vector<string>& words, int start,  vector<int>& dp){
        if(start == s.length()) return true;
        if(dp[start] != -1) return dp[start];
        for(auto &word : words){
            int len = word.length();
            // check if this word is equal to the subs of s
            string sub = s.substr(start, len);
            if(word == sub){
                if(dfs(s, words, start+len, dp)) return true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // so the problem is to create s from wordDict
        // is it possible to create string s from wordDic
        vector<int> dp(s.length(), -1);
        return dfs(s, wordDict, 0, dp);
    }
};