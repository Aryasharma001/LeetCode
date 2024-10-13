class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxVal=INT_MIN;
        int minVal=INT_MAX;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],i,0});
            maxVal=max(maxVal,nums[i][0]);
            minVal=min(minVal,nums[i][0]);
        }
        //int maxi=INT_MIN;
        vector<int>ans={minVal,maxVal};
        while(true){
            vector<int>cur=pq.top();
            int curMinVal=cur[0];
            int listIndex=cur[1];
            int elementIndex=cur[2];
            pq.pop();
            if(maxVal-curMinVal<ans[1]-ans[0]){
                ans[0]=curMinVal;
                ans[1]=maxVal;
            }
            if(elementIndex==nums[listIndex].size()-1) break;
            int next=nums[listIndex][elementIndex+1];
            maxVal=max(maxVal,next);
            pq.push({next,listIndex,(elementIndex+1)});
        }
        return ans;
    }
};