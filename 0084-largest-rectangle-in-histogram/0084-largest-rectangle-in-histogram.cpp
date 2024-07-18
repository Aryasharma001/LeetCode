class Solution {
public:
    void previous_smaller_element(vector<int>& heights, vector<int>& pse) {
        stack<int> st;
        pse[0] = -1;
        st.push(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }
    }

    void next_smaller_element(vector<int>& heights, vector<int>& nse) {
        stack<int> st;
        int n = heights.size();
        nse[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        int ans = 0;
        next_smaller_element(heights, nse);
        previous_smaller_element(heights, pse);
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1)); 
        }
        return ans;
    }
};
