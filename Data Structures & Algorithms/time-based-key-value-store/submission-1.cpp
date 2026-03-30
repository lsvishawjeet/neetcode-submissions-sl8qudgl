class TimeMap {
private:
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string matched = "";
        if(mp.find(key)!=mp.end()){
            int l = 0;
            int r = mp[key].size()-1;
    
            while(l<=r){
                int mid = (l+r)/2;
                if(mp[key][mid].first <= timestamp){
                    matched = mp[key][mid].second;
                    l = mid+1;
                } else{
                    r = mid-1;
                }
            }
        }
        return matched;
    }
};
