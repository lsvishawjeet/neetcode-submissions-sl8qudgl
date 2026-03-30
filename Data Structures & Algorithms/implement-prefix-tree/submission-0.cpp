class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd = false;
    bool contains(char c){
        if(children[c-'a']){
            return true;
        }
        return false;
    }
    void insert(char c, TrieNode* node){
        children[c-'a'] = node;
    }
    TrieNode* get(char c){
        return children[c-'a'];
    }
    void setEnd(){
        isEnd = true;
    }
};
class PrefixTree { 
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        // insert word to the trie
        TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i])){
                node->insert(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        // traverse throguh each work
        TrieNode* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
