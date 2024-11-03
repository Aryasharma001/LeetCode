class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size())
            return false;
        if(s==goal) return true;
        string newString="";
        
        for(int i=0;i<s.size()-1;i++){
            newString+=s[i];
            string temp=s.substr(i+1,n);
            //cout<<temp<<" "<<newString<<" "<<endl;
            if((temp+newString)==goal) return true;
        }
        return false;
    }
};