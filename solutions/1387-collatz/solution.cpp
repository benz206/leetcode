#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> memo;

    int calculate(int num) {
        if (memo.count(num)) return memo[num];

        int steps = 0, temp = num;
        while (temp != 1) {
            if (memo.count(temp)) {
                steps += memo[temp];
                break;
            }
            steps++;
            temp = (temp % 2 == 0) ? temp / 2 : 3 * temp + 1;
        }

        return memo[num] = steps;
    }

    int getKth(int lo, int hi, int k) {
        memo[1] = 0;

        priority_queue<pair<int, int>> pq;

        for (int i = lo; i <= hi; i++) {
            pq.push({calculate(i), i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top().second;
    }
};
