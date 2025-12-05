/**
key point is collisions are equal, car moving right contribs 1, car moving left contribs 1, once trimmed u just get the answer
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row - digit, seen row digit
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][d] || col[j][d] || box[b][d]) return false;

                row[i][d] = col[j][d] = box[b][d] = true;
            }
        }
        return true;
    }
};