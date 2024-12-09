
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<bool> ans(q);
        vector<int>count(n);
        count[0]=0;
        for(int i=1;i<n;i++){
            if((nums[i]%2)==(nums[i-1]%2)){
                count[i]=count[i-1]+1;
            }
            else
                count[i]=count[i-1];
        }
        
        for(int i=0;i<q;i++){
            int temp=count[queries[i][1]]-count[queries[i][0]];
            if(temp==0)
                ans[i]=true;
            else
                ans[i]=false;
        }
        return ans;
        
        
        
    }
};
