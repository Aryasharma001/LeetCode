class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            string lastString=ans.back();
            lastString+='/';
            if(folder[i].find(lastString)!=0)
                ans.push_back(folder[i]);
        }
        return ans; // Return the result vector
    }
};
