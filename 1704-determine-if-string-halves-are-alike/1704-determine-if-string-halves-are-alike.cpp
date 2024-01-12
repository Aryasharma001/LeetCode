class Solution {
public:
    bool halvesAreAlike(string s) {
        string a="";
        string b="";
        for(int i=0;i<(s.size()/2);i++){
            a+=s[i];
        }
        for(int i=(s.size()/2);i<s.size();i++){
            b+=s[i];
        }
        int vowelA=0,vowelB=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'|| a[i]=='o'|| a[i]=='u' || a[i]=='A'||a[i]=='E'|| a[i]=='O'||a[i]=='I'||a[i]=='U'){
                vowelA++;
            }
        }
        for(int i=0;i<b.size();i++){
            if(b[i]=='a'||b[i]=='e'||b[i]=='i'|| b[i]=='o'|| b[i]=='u' || b[i]=='A'||b[i]=='E'||                              b[i]=='O'||b[i]=='I'||b[i]=='U'){
                vowelB++;
            }
        }
        if(vowelA==vowelB){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};