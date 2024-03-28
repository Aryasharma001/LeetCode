class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MIN;
        unordered_map<int,int>m;
        
        int start=0,end=0;
        while(start<nums.size() && end<nums.size()){
            m[nums[end]]++;
            while( m[nums[end]]>k){
                m[nums[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
            
        }
        return ans;
    }
};