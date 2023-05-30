class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
    int bs(vector<int>& nums, int target,int start,int end){
        if(start>end)
            return -1;
        int mid=start+(end-start)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
            return bs(nums,target,start,mid-1);
        else
            return bs(nums,target,mid+1,end);
    }
};