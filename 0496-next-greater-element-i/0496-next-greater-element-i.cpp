class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store the next greater element for each element in nums2
        unordered_map<int, int> ngeMap;
        stack<int> st;

        // Iterate over nums2 in reverse order to find the next greater elements
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            ngeMap[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Prepare the answer array for nums1
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = ngeMap[nums1[i]];
        }

        return ans;
    }
};