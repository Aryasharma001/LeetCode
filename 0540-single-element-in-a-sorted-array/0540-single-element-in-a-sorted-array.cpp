class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        vector<int> hash(100000,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==1)
                return i;
        }
        return -1;
    }
};