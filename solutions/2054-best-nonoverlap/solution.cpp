#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // pq solution
        // use a min-heap to store the ascending values {endTime, val} of seen events that are guarenteed to be best
        // filter out
        // For each event, if it plus best seen is available, then we have a new best, then just add

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // best past singular value that ends before the current start, we don't care about anything else
        int bestPast = 0;
        int ans = 0;

        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[0] < b[0]; // sort based on start
        });

        for (const vector<int> &e : events) {
            int start = e[0];
            int end = e[1];
            int val = e[2];

            // filter out expired
            while (pq.size() > 0 && pq.top().first < start) {
                bestPast = max(pq.top().second, bestPast);
                pq.pop();
            }

            ans = max(ans, val + bestPast);
            ans = max(ans, val);

            pq.push({end, val});
        }

        return ans;
    }
};