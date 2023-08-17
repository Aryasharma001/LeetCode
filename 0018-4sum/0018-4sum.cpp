class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long int target2=target-nums[i];
                    target2=target2-nums[j];
                    if(nums[k]+nums[l]==target2){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.insert(temp);
                        l--;
                        k++;
                    }
                    else if((nums[k]+nums[l])<target2){
                        k++;
                    }
                    else
                        l--;
                
                }
        
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};