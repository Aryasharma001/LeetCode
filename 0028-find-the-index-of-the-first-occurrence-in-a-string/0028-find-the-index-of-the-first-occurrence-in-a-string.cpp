class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if(haystack.size()<needle.size())
            return -1;
        int i=0,j=0;
        int index=-1;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
               if (j == 0) index = i; // Set the starting index when first character matches
               j++;
               if (j == needle.size()) return index;
            }
            else{
                if(j>0){
                    i=index;
                    j=0;
                }
            }
                

                
            //cout<<i<<" "<<j<<" "<<endl;
            i++;
        }
        return -1;
    }
};