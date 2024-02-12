class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums.size()/2;
        int count=1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            // cout<<nums[i]<<" ";
            if(nums[i]==nums[i+1]){
                
                count++;
                if(count>majority){
                    return nums[i];
                }
            }
            else{
                count=1;
            }
            
        }
        
        return nums[0];
    }
};