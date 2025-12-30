#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) {
                return false;
            }

            // greedy step is just find max dist from current place
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return true;
    }
};
