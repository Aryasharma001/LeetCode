class Solution {
     private:
        void swap(vector<int>& nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int mid=0,low=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums,mid,high);
                high--;
            }
            else if(nums[mid]==0){
                swap(nums,low,mid);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
        }
            
    }
};