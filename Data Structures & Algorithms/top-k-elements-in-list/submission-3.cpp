class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        for(auto i : nums){
            freq[i]++;
        }
        vector<pair<int, int>> sortedTable(freq.begin(), freq.end()); 
        sort(sortedTable.begin(), sortedTable.end(), [](const auto&a, const auto&b){
            return a.second < b.second;
        });
        for(int i = 0 ; i < k ; i++){
            auto p = sortedTable.back();
            result.push_back(p.first);
            sortedTable.pop_back();
        }
        return result;
        
    }
};
