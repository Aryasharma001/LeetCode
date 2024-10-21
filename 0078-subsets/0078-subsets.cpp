class Solution {
public:
    void allSubsets(vector<int>& nums,int i,set<vector<int>>&s,vector<int>temp){
        if(i==nums.size()){
            s.insert(temp);
            return;
        }
        // we don't include the current element
        allSubsets(nums,i+1,s,temp);
        temp.push_back(nums[i]);
        // include the current element;
        allSubsets(nums,i+1,s,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>temp;
        allSubsets(nums,0,s,temp);
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};