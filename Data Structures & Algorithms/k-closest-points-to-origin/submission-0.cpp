class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<double, vector<int>>,
            vector<pair<double, vector<int>>>,
            greater<pair<double, vector<int>>>
        > minHeap;

        for (auto p : points) {
            double dist = p[0] * p[0] + p[1] * p[1];
            minHeap.push({dist, p});
        }

        vector<vector<int>> ans;

        while (k != 0) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return ans;
    }
};