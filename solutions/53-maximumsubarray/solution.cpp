/* 
Idea is for each iteration, calculate the maximum subarray that ends at that position, this will either be the number itself, or some other subarray that should be the best beforehand
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT_MIN;
        int temp = 0;

        for (int i = 0; i < nums.size(); ++i) {
            temp = max(nums[i], nums[i] + temp);
            best = max(temp, best);
        }

        return best;
    }
};
