class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int >hash;
        for(int it:nums)
            hash[it]++;
        for(auto p:hash){
            if(p.second>1)
                return true;
        }
        return false;
    }
};