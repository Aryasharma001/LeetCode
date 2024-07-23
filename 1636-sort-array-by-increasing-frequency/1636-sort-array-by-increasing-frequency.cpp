class Solution {
public:
    static bool descendingSort(const pair<int,int>&a, const pair<int,int>&b){
        if(a.second==b.second)
            return a.first>b.first;
        return a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freqMap;
        for(int i=0;i<nums.size();i++)
            freqMap[nums[i]]++;
                    
        vector<pair<int, int>> freqVector(freqMap.begin(), freqMap.end());
        sort(freqVector.begin(), freqVector.end(), descendingSort);
        
        vector<int>ans;
        for(auto it:freqVector){
            while(it.second--)
                ans.push_back(it.first);
        }
        return ans;
        
    }
};