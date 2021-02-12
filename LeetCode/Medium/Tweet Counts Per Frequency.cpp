#include<bits/stdc++.h>

using namespace std;

cclass TweetCounts {
public:
    unordered_map<string, vector<int>> map;
    unordered_map<string, int> f = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
    
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        map[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> t = map[tweetName];
        int size = (endTime-startTime)/f[freq];
        vector<int> res(size+1, 0);
        
        for (int x: t){
            if (x >= startTime && x <= endTime){
                res[(x-startTime)/f[freq]]++;       
            }
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */