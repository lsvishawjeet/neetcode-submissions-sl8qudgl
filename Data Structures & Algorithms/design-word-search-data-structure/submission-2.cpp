class TrieNode {
public:
    TrieNode* container[26];
    bool wordEnd = false;
    bool contains(char ch){
        return container[ch-'a']!=NULL;
    }
    void addLetter(char ch, TrieNode* node){
        container[ch-'a'] = node;
    }
    void markEnd(){
        wordEnd = true;
    }
    bool getIsEnded(){
        return wordEnd;
    }
    TrieNode* getNext(char c){
        return container[c-'a'];
    }
};
class WordDictionary {
private:
    TrieNode* root;
    bool dfs(string &word, int index, TrieNode* node){
        if(index == word.length()){
            return node->getIsEnded();
        }
        char ch = word[index];
        if(ch!='.'){
            if(!node->contains(ch)){
                return false;
            }
            return dfs(word, index+1, node->getNext(ch));
        } else{
            for(int i=0; i<26; i++){
                if(node->container[i]){
                    if(dfs(word, index+1, node->container[i])) return true;
                }
            }
            return false;
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->addLetter(word[i], new TrieNode());
            }
            node = node->getNext(word[i]);
        }
        node->markEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
