#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use like a 2p sliding window technique? just go over and solve
        // keep track of everything using a hashmap
        
        int best = 0;

        int left = 0;
        int right = 1;

        // char to pos
        unordered_map<char, int> map;

        for (const char &c : s) {
            if (map.find(c) != map.end()) {
                left = map[c];
            }
            map[c] = right;

            best = max(best, right - left);
            ++right;
        }

        return best;
    }
};