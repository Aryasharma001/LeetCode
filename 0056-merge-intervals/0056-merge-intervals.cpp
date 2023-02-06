class Solution {
public:
    vector<vector<int>>merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        int s=intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
        if(s==1){
            return intervals;
        }
        else{
            int start=intervals[0][0],end=intervals[0][1];
            for(int i=1;i<s;i++){
                if(intervals[i][0]<=end){
                    end=max(intervals[i][1],end);
                }
                else{
                    v.push_back({start,end});
                    start=intervals[i][0];
                    end=intervals[i][1];
                }
                }
                v.push_back({start,end});
        }
            return v;
        }
        
    
};