class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<vector<int>>hashSets;
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>hashMap;
        for(auto it:strs){
            vector<int>hashSet(27,0);
            for(int i=0;i<it.size();i++)
                hashSet[int(it[i]-'a')]++;
            if(hashSets.find(hashSet)==hashSets.end()){
                hashSets.insert(hashSet);
            }
            hashMap[hashSet].push_back(it);
        }
        for(auto it:hashMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};