class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1;
        int start=points[0][0],end=points[0][1];
        for(int i=1;i<points.size();i++){
            if(end>=points[i][0]){
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
            else{
                count++;
                start=points[i][0];
                end=points[i][1];
            }
        }
        return count;
    }
};