class Solution {
public:
    void func(int index,vector<string>&path,vector<vector<string>>&res,string s){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,path,res,s);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int index,int i){
        while(index<=i){
            if(s[index++]!=s[i--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
       vector<string>path;
        vector<vector<string>>res;
        func(0,path,res,s);
        return res;
    }
};