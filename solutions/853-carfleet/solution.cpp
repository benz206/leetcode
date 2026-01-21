#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](pair<int, double> &a, pair<int, double> &b) {
            // lambda to sort so that we have farthest first descending order
            return a.first > b.first;
        });

        int fleets = 0;
        double lastTime = 0;

        for (pair<int, double> &car: cars) {
            if (car.second > lastTime) {
                ++fleets;
                lastTime = car.second;
            }
        }

        return fleets;
    }
};
