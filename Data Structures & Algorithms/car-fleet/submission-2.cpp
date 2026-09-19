class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // [6, 9, 10, 3]
        // [2, 4.5, 10, 3]
        int n = position.size();
        vector <pair<int, int>> carGPS; 

        // pair of start position and index -> index can get me absolute position and velocity at any given time 
        for (int i = 0 ; i < n; ++i) {
            carGPS.push_back({position[i], i});
        }

        // sort by start position
        sort(carGPS.begin(), carGPS.end(), std::greater<>());
        stack<double> fleet;
        for (int i = 0 ; i < n; ++i) {
            int start = carGPS[i].first;
            int idx = carGPS[i].second;
   
            // Evaluate the time to reach target = distance / speed =  (target - start) / speed
            double time = (double)(target - start) / speed[idx];
           
             // Monotonic stack 
            if (fleet.empty() or fleet.top() < time) {
                fleet.push(time);
            }
        }

        return fleet.size();
       
    }
};
