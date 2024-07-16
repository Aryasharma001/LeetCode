class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty())
                ans[i]=-1;
            else
                ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};