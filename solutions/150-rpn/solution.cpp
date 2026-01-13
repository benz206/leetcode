#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (const string& token : tokens) {
            if (!(token == "+" || token == "-" || token == "*" || token == "/")) {
                nums.push(stoi(token));
            } else {
                char op = token[0];
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();

                if (op == '+') {
                    first += second;
                } else if (op == '-') {
                    first -= second;
                } else if (op == '*') {
                    first *= second;
                } else {
                    first /= second;
                }

                nums.push(first);
            }
        }

        return nums.top();
    }
};
