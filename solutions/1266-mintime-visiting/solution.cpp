/*
I feel like I'm starting to get it!

Just notice that since we can travel horizontally and vertically (diagonally) in 1 sec just take max on both edges and go
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (size_t i = 0; i < points.size() - 1; ++i) {
            int a = abs(points[i][0] - points[i + 1][0]);
            int b = abs(points[i][1] - points[i + 1][1]);

            time += max(a, b);
        }

        return time;
    }
};