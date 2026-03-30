class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // return 0 if word is not in list
        unordered_set<string> words;
        for(string word : wordList){
            words.insert(word);
        }
        if(words.find(endWord) == words.end()) return 0;
        // algorithm:
        // start with the begin word
        // change letter at each index from 'a' to 'z'
        // if the word exist in the list then put that into queue with its level
        // once word is found return it
        queue<pair<string, int>> q;
        int wordLength = beginWord.length();
        set<string> visitedWords;
        q.push({beginWord,1});
        while(!q.empty()){
            string startWord = q.front().first;
            int startLevel = q.front().second;
            visitedWords.insert(startWord);
            q.pop();
            for(int i=0; i<wordLength; i++){
                string s = startWord;
                for(char j = 'a'; j<='z'; j++){
                    if(s[i]==j) continue;
                    string newWord = startWord;
                    newWord[i] = j;
                    if(words.find(newWord) != words.end() && visitedWords.find(newWord) == visitedWords.end()){
                        cout<<newWord<<" "<<startLevel+1<<endl;
                        if(newWord == endWord){
                            return startLevel+1;
                        }
                        q.push({newWord, startLevel+1});
                    }
                }
            }
        }
        return 0;
    }
};
