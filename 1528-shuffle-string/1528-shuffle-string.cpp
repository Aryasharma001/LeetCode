class Solution {
public:
    void f(string s,vector<int>&indices,vector<int>&ans,int i){
        if(i==s.size()){
            return;
        }                                                                                                                                                                                                       
        ans[indices[i]]=s[i];
        f(s,indices,ans,i+1);
    }
    string restoreString(string s, vector<int>& indices) {
        vector<int>ans(s.size());
        f(s,indices,ans,0);
        string ans2="";
        for(int i=0;i<s.size();i++){
            ans2+=ans[i];
        }
        return ans2;
    }
};