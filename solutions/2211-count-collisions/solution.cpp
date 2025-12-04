/**
key point is collisions are equal, car moving right contribs 1, car moving left contribs 1, once trimmed u just get the answer
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        while (l < directions.size() && directions[l] == 'L') {
            ++l;
        }

        int r = directions.size() - 1;
        while (r >= 0 && directions[r] == 'R') {
            --r;
        }


        int count = 0;

        for (int i = l; i <= r; ++i) {
            if (directions[i] != 'S') {
                ++count;
            }
        }

        return count;
    }
};