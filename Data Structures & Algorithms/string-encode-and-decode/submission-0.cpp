class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &s : strs){
            int len = s.length();
            encoded += '&';
            encoded += to_string(len);
            encoded += '&';
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        bool isCompleted = true;
        for(int i = 0 ; i<s.length(); i){
            string num = "";
            string decodedS = "";
            if(s[i] == '&'){
                i++;
                while(s[i]!='&'){
                    num += s[i];
                    i++;
                }
            }
            i++;
            int sLength = stoi(num);
            while(sLength>0){
                decodedS += s[i];
                i++;
                sLength--;
            }
            decoded.push_back(decodedS);
            isCompleted = true;
        }
        return decoded;
    }
};
