class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars;
        for(int i = 0 ; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        int fleet = 1;
        double prevTime = (double) (target - cars[0].first ) / cars[0].second;
        for(int i = 1 ; i < cars.size(); i++){
            double currTime = (double) (target - cars[i].first ) / cars[i].second;
            if(currTime > prevTime){
                fleet++;
                prevTime = currTime;
            }
        }
        return fleet;
    }
};
