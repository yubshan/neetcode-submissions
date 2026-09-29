class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto w : stones){
            maxHeap.push(w);
        }
        while(maxHeap.size() > 1){
            int w1 = maxHeap.top();
            maxHeap.pop();
            int w2 = maxHeap.top();
            maxHeap.pop();
            int wDiff = abs(w1 - w2);
            if(wDiff > 0){
                maxHeap.push(wDiff);
            }
        }
        if(maxHeap.empty()){
            return 0;
        }

        return maxHeap.top();
    }
};
