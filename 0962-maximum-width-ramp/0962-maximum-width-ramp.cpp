class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monoStack;  // Stack to store indices
        int ans = 0;

        // Step 1: Build a decreasing monotonic stack of indices
        for (int i = 0; i < nums.size(); i++) {
            // Only push indices where nums[i] is smaller than the value at the top of the stack
            if (monoStack.empty() || nums[monoStack.top()] > nums[i]) {
                monoStack.push(i);
            }
        }

        // Step 2: Traverse from the end and find the maximum width ramp
        for (int i = nums.size() - 1; i >= 0; i--) {
            // Find the largest valid ramp where nums[monoStack.top()] <= nums[i]
            while (!monoStack.empty() && nums[monoStack.top()] <= nums[i]) {
                ans = max(ans, i - monoStack.top());
                monoStack.pop();
            }
        }

        return ans;
    }
};
