class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int min = INT_MAX;
        int maxi = INT_MIN;
        vector<vector<int>> ans;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < min)
                min = intervals[i][0];
            else if(intervals[i][0]>maxi){
                ans.push_back({min,maxi});
                min=intervals[i][0];
                maxi=intervals[i][1];
            }
                
            
            if (intervals[i][1] > maxi)
                maxi = intervals[i][1];
            
        }
        
        ans.push_back({min, maxi}); // Add the last interval
        
        return ans;
    }
};
