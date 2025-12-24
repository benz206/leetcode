#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        const int n = (int)apple.size();

        sort(capacity.begin(), capacity.end(), greater<int>());

        int total = 0;

        for (int i = 0; i < n; ++i) {
            total += apple[i];
        }

        int other = 0;
        int ans = 0;

        while (other < total) {
            other += capacity[ans];
            ++ans;
        }

        return ans;
    }
};
