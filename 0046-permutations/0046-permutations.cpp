class Solution {
public:
    int fact(int n){
        int count=1;
        for(int i=2;i<=n;i++)
            count*=i;
        return count;
    }
 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        ans.push_back(nums);
        for(int i=2;i<=fact(nums.size());i++){
            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
        }
        return ans;
        
    }
};