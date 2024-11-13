class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int lb=lower-nums[i];
            int ub=upper-nums[i];
            int low=(lower_bound(nums.begin()+i+1,nums.end(),lb)-nums.begin());
            int high=(upper_bound(nums.begin()+i+1,nums.end(),ub)-nums.begin());
            ans+=(high-low);
        }
        return ans;
    }
};