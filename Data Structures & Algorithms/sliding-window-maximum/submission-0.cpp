class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>ans;

        int left = 0;
        for( int right = 0; right < k ; right++ ){
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
        }


        for( int right = k ; right < nums.size(); right++){
            // save the current window max element 
            int winGIdx= dq.front();
            ans.push_back(nums[winGIdx]);

            if(left == winGIdx){
                dq.pop_front();
            }
            left++;

            //update the queue for position of new element;
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};
