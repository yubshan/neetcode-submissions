class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        int i = 0;
        for(auto num : nums){
          freq[num]++;
        };
        vector<pair<int, int>> temp; 
        for (auto pair : freq){
          temp.push_back(pair);
        };
       sort(temp.begin(), temp.end(), [](pair<int, int> a , pair<int, int> b) {
        return a.second > b.second;
       });
       for(int i = 0 ; i < k ; i++){
        ans.push_back(temp[i].first);
       }
       return ans;
    }
};
