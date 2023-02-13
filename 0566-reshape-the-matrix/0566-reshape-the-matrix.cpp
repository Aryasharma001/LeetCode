class Solution {
public:
     vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size();
        int n=nums[0].size();
         vector<int>single;
        for(int i=0;i<m;i++){
            for(auto it:nums[i])
                single.push_back(it);
        }
        if(m*n!=r*c)
            return nums;
         vector<vector<int>> ans;
         vector<int> rows;
         for(int i=0;i<r;i++){
             for(int j=0;j<c;j++){
                 rows.push_back(single[(i*c+j)]);
             }
             ans.push_back(rows);
             rows.clear();
         }
         
         return ans;
     }
    
};