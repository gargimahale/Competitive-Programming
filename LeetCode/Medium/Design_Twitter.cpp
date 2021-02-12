#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

class Twitter {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
    int time=0;
    
    Twitter() {
        posts.clear();
        follows.clear();
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({++time, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by 
	 * users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> res;
        
        int len = posts[userId].size();
        for (int i=0; i<len; ++i){
            res.push_back(posts[userId][i]);
        }
        
        for (int x: follows[userId]){
            int len = posts[x].size();
            for (int i=0; i<len; ++i){
                res.push_back(posts[x][i]);
            }
        }
        
        sort(begin(res), end(res), [&](pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        });
        vector<int> ans;
        for (int i=0; i<10 && i<res.size(); ++i){
            ans.push_back(res[i].second);
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId){
            return;
        }
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId){
            return;
        }
        follows[followerId].erase(followeeId);
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