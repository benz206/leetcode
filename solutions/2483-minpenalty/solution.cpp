#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int best = 0;
        int time = 0;
        int temp = 0;

        for (int i = 0; i < customers.size(); ++i) {
            const char c = customers[i];

            if (c == 'Y') {
                ++temp;
                if (best < temp) {
                    best = temp;
                    time = i + 1;
                }
            } else {
                temp--;
            }
        }

        return time;
    }
};
