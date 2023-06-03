class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int j=0,i,l;
        int mn=INT_MAX;
        int sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[j++];
                }
                sum+=nums[--j];
                l=i-j+1;
                mn=min(mn,l);
            }
        }
        if(mn==INT_MAX)return 0;
        return mn;
    }
};