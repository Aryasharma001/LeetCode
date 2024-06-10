class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>given_heights=heights;
        int count=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=given_heights[i]){
                count++;
            }
        }
        return count;
        
    }
};