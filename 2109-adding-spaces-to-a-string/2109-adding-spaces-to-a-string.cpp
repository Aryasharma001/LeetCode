class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int spaceInd=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(spaceInd<spaces.size() && i==spaces[spaceInd]){
                ans+=" ";
                spaceInd++;
            }
            ans+=s[i];
        }
        return ans;
    }
};