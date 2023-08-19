class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        map<int,int>m;
        for(auto it:mp){
            m.insert({it.second,it.first});
        }
        for(auto it:m){
            return it.second;
        }
        return -1;
    }
};