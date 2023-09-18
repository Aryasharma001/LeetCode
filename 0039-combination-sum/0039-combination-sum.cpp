class Solution {
public:
    void f(int i,vector<int>&count,vector<int>&arr,int target,vector<vector<int>>&ans){
        if(i==arr.size()){
            if(target==0)
            ans.push_back(count);
            return;
        }
        if(arr[i]<=target){
            count.push_back(arr[i]);
            f(i,count,arr,target-arr[i],ans);
            count.pop_back();
        }
        f(i+1,count,arr,target,ans);
        
        
       
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int>count;
        f(0,count,candidates,target,ans);
        
        return ans;
        
    }
};