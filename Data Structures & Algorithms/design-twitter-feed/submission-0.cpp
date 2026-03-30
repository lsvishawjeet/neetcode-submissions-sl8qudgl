class Twitter {
public:
    map<int, set<int>> followMap;
    map<int, vector<vector<int>>> tweetMap;
    int count;
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // we need to return the top 10 posts of the users that user follow (including self)
        // return top 10 posts according to time (count)
        vector<int> sol;
        // merge the k sorted arrays
        auto comparator = [](const vector<int>&a , const vector<int> &b){
            return a[0]<b[0];
        };
        followMap[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> maxHeap(comparator); 
        for(int userId : followMap[userId]){
            // we have all users that user follow
            // inseart letest post of each user in queue including index of the post
            if(tweetMap.count(userId)){
                const vector<vector<int>>& tweets = tweetMap[userId];
                int index = tweets.size()-1;
                int timeStamp = tweets[index][0];
                int tweetId = tweets[index][1];
                maxHeap.push({timeStamp, tweetId, userId, index});
            }
        }
        // now our max heap contains the latest tweet of all the users
        // run a while loop and push the top most tweet to sol and pop and add next index of top user tweet to the heap
        while(!maxHeap.empty() && sol.size()<10){
            auto curr = maxHeap.top();
            sol.push_back(curr[1]);
            maxHeap.pop();
            int currIndex = curr[3];
            if(currIndex > 0){
                int currUser = curr[2];
                int newIndex = currIndex-1;
                const vector<int>& tweet = tweetMap[currUser][newIndex];
                maxHeap.push({tweet[0], tweet[1], currUser, newIndex});
            }
        }
        return sol;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)){
            followMap[followerId].erase(followeeId);
        }
    }
};
