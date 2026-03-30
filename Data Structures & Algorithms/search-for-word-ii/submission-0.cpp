class TrieNode{
private:
    TrieNode* container[26];
    bool isEnded;
public:
    TrieNode(){
        for(int i=0; i<26; i++){
            container[i] = NULL;
        }
        isEnded = false;
    }
    bool contains(char c){
        return container[c-'a']!=NULL;
    }
    void add(char c, TrieNode* node){
        container[c-'a'] = node;
    }
    TrieNode* nextWord(char c){
        return container[c-'a'];
    }
    void markWordEnded(){
        isEnded = true;
    }
    bool isWordEnded(){
        return isEnded;
    }
    void markEndedFalse(){
        isEnded = false;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->add(word[i], new TrieNode());
            }
            node = node->nextWord(word[i]);
        }
        node->markWordEnded();
    }
    void dfs(vector<vector<char>>& board, TrieNode* node, int r, int c, string word, vector<vector<bool>>&vis, vector<string> &sol){
        if(vis[r][c] || !node->contains(board[r][c])){
            return;
        }
        node = node->nextWord(board[r][c]);
        word += board[r][c];
        if(node->isWordEnded()){
            node->markEndedFalse();
            sol.push_back(word);
        }
        // move left
        vis[r][c] = true;
        if(c-1 >= 0){
            dfs(board, node, r, c-1, word, vis, sol);
        }

        // move right
        if(c+1 < board[0].size()){
            dfs(board, node, r, c+1, word, vis, sol);
        }

        // mvoe top
        if(r-1 >= 0){
            dfs(board, node, r-1, c, word, vis, sol);
        }

        // move bottom
        if(r+1 < board.size()){
            dfs(board, node, r+1, c, word, vis, sol);
        }
        vis[r][c] = false;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;

        Trie wordTrie;
        // insert words to trie
        for(string word : words){
            wordTrie.insert(word);
        }
        // do dfs and find in trie
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                wordTrie.dfs(board, wordTrie.root, i, j, "", vis, sol);
            }
        }
        return sol;
    }
};