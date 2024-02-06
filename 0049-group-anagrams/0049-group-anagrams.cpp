class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string>hashSets;
        vector<vector<string>>ans;
        map<string,vector<string>>hashMap;
        for(auto it:strs){
            string sortedStr=it;
            sort(sortedStr.begin(),sortedStr.end());
            if(hashSets.find(sortedStr)==hashSets.end()){
                hashSets.insert(sortedStr);
            }
            hashMap[sortedStr].push_back(it);
        }
        for(auto it:hashMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};