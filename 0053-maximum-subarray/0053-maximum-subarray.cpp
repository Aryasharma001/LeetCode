class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0,ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            curr_sum=curr_sum+nums[i];
            ans=max(ans,curr_sum);
            if(curr_sum<0)
                curr_sum=0;
        }
        return ans;
    }
};