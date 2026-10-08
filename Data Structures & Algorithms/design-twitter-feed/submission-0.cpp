class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;
    int time = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>> maxHeap;

        unordered_set<int> users = followMap[userId];
        users.insert(userId);

        for (int u : users) {
            for (const auto& tweet : tweetMap[u]) {
                maxHeap.push(tweet);
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto tweet = maxHeap.top();
            maxHeap.pop();

            res.push_back(tweet.second);
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (!followMap.count(followerId)) return;

        followMap[followerId].erase(followeeId);
    }
};