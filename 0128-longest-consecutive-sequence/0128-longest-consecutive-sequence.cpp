class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        set<int>st;
        vector<int>arr;
        int ans=0;
        int count=0;
        for(auto it:nums)
            st.insert(it);
        for(auto it:st){
            arr.push_back(it);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]==arr[i]+1){
                count++;
                ans=max(count,ans);
            }
            else
                count=0;
        }
        return ans+1;
    }
};