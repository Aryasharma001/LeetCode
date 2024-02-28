class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int maxProduct=1;
        int ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            maxProduct=nums[i];
            for(int j=i+1;j<nums.size();j++){
                maxProduct*=nums[j];
                ans=max(ans,maxProduct);
            }
        }
        return ans;
        
    }
};