class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        if(nums.size()==1)
            return {nums[0]};
        for(int i=0;i<=nums.size()-k;i++){
            int temp=nums[i];
            for(int j=i;j<i+k-1;j++){
                if(nums[j]>=nums[j+1] || nums[j+1]!=nums[j]+1){
                    temp=-1;
                    break;
                }
                temp=max(temp,nums[j+1]);
                    
            }
            ans.push_back(temp);
        }
        return ans;
    }
};