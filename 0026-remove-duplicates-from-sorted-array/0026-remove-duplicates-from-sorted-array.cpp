class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int max_element=INT_MIN;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_element)
                max_element=max(max_element,nums[i]);
            else if(nums[i]==max_element){
                nums[i]=1001;
                cnt++;
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size()-cnt;
    }
};