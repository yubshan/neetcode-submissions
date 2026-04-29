class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto i : nums){
            freq[i]++;
        };
        for(auto [number, frequency]: freq){
            if(frequency > 1){
                return true;
            }
        }
        return false;
    }
};