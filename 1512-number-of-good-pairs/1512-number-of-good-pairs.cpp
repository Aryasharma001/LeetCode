class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int hash[101]={0};
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=hash[nums[i]]++;
        }
        
        
        return count;
    }
};