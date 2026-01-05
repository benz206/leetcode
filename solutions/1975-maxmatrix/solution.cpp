#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll total = 0;

        ll mint = LLONG_MAX;

        int negatives = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int num = matrix[i][j];
                int abso = abs(num);

                if (mint > abso) {
                    mint = abso;
                }

                if (num < 0) {
                    ++negatives;
                }

                total += abso;
            }
        }

        if (negatives % 2 == 1) {
            total -= 2 * mint;
        }

        return total;
    }
};