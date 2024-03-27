class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0,e=0;
        int prod=1;
        int count=0;
        
        while(e<nums.size()){
            prod*=nums[e++];
            while(start<e && prod>=k ){
                prod=prod/nums[start++];
            }
            if(prod<k){
                count+=e-start;
            }
        }
        return count;
    }
};