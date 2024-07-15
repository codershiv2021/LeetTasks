class Twitter {
public:
//map to store followers vector
//stack to store  tweet (pair), time, userId
//priortiy_queue of size 10 to store userId and map
//of it ka stack
    unordered_map<int,unordered_set<int>>followers;
    unordered_map<int,vector<pair<int,int>>>tweet;
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time,tweetId});
        time++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        for (auto i: tweet[userId]){
            pq.push({i.first,i.second});
            if(pq.size()>10){
                pq.pop();
            }
        }
        for (auto i: followers[userId]){
            for (auto j: tweet[i]){
                pq.push({j.first,j.second});
                if(pq.size()>10){
                pq.pop();
            }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */