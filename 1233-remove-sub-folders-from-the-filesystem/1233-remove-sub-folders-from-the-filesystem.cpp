class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        set<string>hashSet;
        for(auto it:folder){
            hashSet.insert(it);
        }
        for(int i=0;i<folder.size();i++){
            bool isSubFolder=false;
            string s=folder[i];
            while(!s.empty()){
                size_t end=s.find_last_of('/');
                s=folder[i].substr(0,end);
                if(hashSet.find(s)!=hashSet.end()){
                    isSubFolder=true;
                    break;
                }
                    
            }
            if(isSubFolder==false)
                ans.push_back(folder[i]);
            
        }
        return ans;
    }
};
