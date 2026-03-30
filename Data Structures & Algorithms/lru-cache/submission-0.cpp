class LRUCache {
public:
    list<pair<int,int>> l; //store key and value pair
    map<int, list<pair<int,int>>::iterator> mp; //store key and pointer address of value
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        auto node = mp[key];
        int value = node->second;
        
        //remove the node with this key and add it to front
        l.erase(node);
        l.push_front({key, value});
        mp[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {
        // if key already exist
        if(mp.find(key) != mp.end()){
            l.erase(mp[key]);
        } else if(mp.size() == cap){
            int backKey = l.back().first;
            mp.erase(backKey);
            l.pop_back();
        }
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};
