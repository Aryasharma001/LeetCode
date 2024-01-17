class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>occurences;
        unordered_map<int,int>hashMap;
        
        for(int i=0;i<arr.size();i++){
            hashMap[arr[i]]++;
        }
        for(auto it:hashMap){
            if(occurences.find(it.second)==occurences.end())
                occurences.insert(it.second);
            else{
                return false;
            }
        }
        return true;
    }
};