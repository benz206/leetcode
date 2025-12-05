/**
Recognize that adding or subtracting keeps the same diff
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;

        for (int n : nums) {
            total += n;
        }

        if (total % 2 == 0) {
            return nums.size() - 1;
        }
        return 0;
    }
};