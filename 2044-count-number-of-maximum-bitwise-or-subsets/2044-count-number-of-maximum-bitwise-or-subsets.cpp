class Solution {
public:
    void subsets(vector<int>& nums,int i,int subset, int& count, int target){
        if(i==nums.size()){
            if(subset==target)
                count++;
            return;
        }
        subsets(nums,i+1,(subset|nums[i]),count,target);
        subsets(nums,i+1,subset,count,target);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++)
            target|=nums[i];
        int subset=0,count=0;
        subsets(nums,0,subset,count,target);
        return count;
        
    }
};