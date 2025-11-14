class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] >= dq.back().second)
                dq.pop_back();
            dq.push_back({i, nums[i]});

            if (dq.front().first <= i - k)
                dq.pop_front();
            if (i >= k - 1)
                res.push_back(dq.front().second);
        }

        return res;
    }
};
