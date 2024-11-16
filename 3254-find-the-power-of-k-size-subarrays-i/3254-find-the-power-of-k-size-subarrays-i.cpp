class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]!=nums[i]-1){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                if(dq.size()==k) ans.push_back(nums[dq.back()]);
                else{
                    ans.push_back(-1);
                }
            }
            
        }
        return ans;
    }
};