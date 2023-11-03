class Solution {
public:
    int search(vector<int>& nums, int target) {
        //step one is finding the hinge index
        if(nums.size()==1){
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        int index=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                index=i;
                break;
            }
                
        }
        int start=0,end=index;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else
                end=mid-1;
        }
        
        int left=index+1,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else
                right=mid-1;
        }
        
        return -1;
    
    }
};