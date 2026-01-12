/*
Notice that if we sort we can reduce comparisons down by a lot
Other thing to notice is then we just need to account for the wrap around and we're good
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Looking to find minimum diff such that addition of both is 24 or subtraction absolute value is minimized
        // to help with this we can sort and then compare once converting the time
        // this then just becomes a circle dist problem

        vector<int> times;

        for (const string& time : timePoints) {
            int HH = stoi(time.substr(0, 2));
            int SS = stoi(time.substr(3, 2));

            times.push_back(HH * 60 + SS);
        }

        sort(times.begin(), times.end());

        int ans = 1440; // worst case

        for (int i = 1; i < times.size(); ++i) {
            ans = min(ans, times[i] - times[i - 1]);
        }

        ans = min(ans, 1440 - times.back() + times.front());

        return ans;
    }
};
