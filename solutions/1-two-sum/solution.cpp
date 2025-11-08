/**
Utilize a hash map to store kv pairs of value: index,
this way if we do find a possible pair we can just immediately return.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                return {i, map[target - nums[i]]};
            }
        }
        return {0, 0};
    }
};