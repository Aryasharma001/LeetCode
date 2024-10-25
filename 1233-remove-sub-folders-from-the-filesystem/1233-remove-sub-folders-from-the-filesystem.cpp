class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        set<string>hashSet;
        for(auto it:folder){
            hashSet.insert(it);
        }
        for(auto currFolder:folder){
            bool isSubFolder=false;
            string temp=currFolder;
            while(!currFolder.empty()){
                size_t end=currFolder.find_last_of('/');
                currFolder=currFolder.substr(0,end);
                if(hashSet.find(currFolder)!=hashSet.end()){
                    isSubFolder=true;
                    break;
                }
                    
            }
            if(isSubFolder==false)
                ans.push_back(temp);
            
        }
        return ans;
    }
};
