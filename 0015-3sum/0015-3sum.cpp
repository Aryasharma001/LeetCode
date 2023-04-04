class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1]) ){
                int start=i+1,end=n-1,sum;
                while(start<end ){
                    sum=nums[start]+nums[end]+nums[i];
                    if(sum==0){
                        vector<int> triplet={nums[i],nums[start],nums[end]};
                        ans.push_back(triplet);
                        while(nums[start]==nums[start+1] &&start<(end-1)) start++;
                        while(nums[end]==nums[end-1] &&start<(end-1)) end--;
                        start++;end--;
                    }
                    else if(sum>0){
                        end--;
                    }
                    else
                        start++;
                }
            }
            
        }
    return ans;
}

};