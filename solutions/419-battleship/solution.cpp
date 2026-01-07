/*
Key insight is how we count a battleship?

EG, whats the steadfast way that no matter what will tell us if a cell is a battleship.

This would be much more difficult and less optimized if it's an unknown shape/island,
but because battleships have to be 1 row/col away and have to start somewhere with no curves
we just simplify to: if nothing above and to the left are x's we can just count
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int count = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] != 'X') continue;

                bool noAbove = (i == 0 || board[i - 1][j] != 'X');
                bool noLeft  = (j == 0 || board[i][j - 1] != 'X');

                if (noAbove && noLeft) {
                    ++count;
                }
            }
        }

        return count;
    }
};
