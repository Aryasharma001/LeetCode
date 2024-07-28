

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot=0;
        while(pivot<nums.size()-1 && nums[pivot]<nums[pivot+1])
            pivot++;
        //cout<<pivot<<endl;
        int start=0;
        int end = pivot;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        start=pivot+1, end=nums.size()-1;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};