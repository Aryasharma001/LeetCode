class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        
        vector<int> minPrefix(n);
        minPrefix[0] = nums[0];
        
        // Calculate the minimum element on the left for each position
        for (int i = 1; i < n; i++) {
            minPrefix[i] = min(minPrefix[i - 1], nums[i]);
        }
        
        stack<int> s;
        for (int j = n - 1; j >= 0; j--) {
            // Check if nums[j] could be the middle element (nums[k])
            if (nums[j] > minPrefix[j]) {
                while (!s.empty() && s.top() <= minPrefix[j]) {
                    s.pop();
                }
                if (!s.empty() && s.top() < nums[j]) {
                    return true;
                }
            }
            s.push(nums[j]);
        }
        
        return false;
    }
};
