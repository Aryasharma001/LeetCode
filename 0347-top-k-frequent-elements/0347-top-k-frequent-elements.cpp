class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        priority_queue<pair<int, int>> pq;

        // Count the frequency of each number in nums
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Insert elements into the max-heap based on frequency
        for (const auto& pair : frequencyMap) {
            pq.push({pair.second, pair.first});
        }

        vector<int> ans;

        while (k > 0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
