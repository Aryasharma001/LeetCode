class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        // step one find the break point 
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                ind=i;
                break;
            }
        }
        // if ind==-1 , that means the array is in decreasing order so just reverse the array
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            // step 2 find the element just greater than nums[ind] and swap both
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            // step 3 reverse the remaining array to get the next permutation
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};