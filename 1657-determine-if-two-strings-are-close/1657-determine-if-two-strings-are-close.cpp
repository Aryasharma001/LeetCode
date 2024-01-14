class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>hash1(28,0);
        vector<int>hash2(28,0);
        
        for(int i=0;i<word1.size();i++){
            hash1[int(word1[i]-'a')]++;
        }
        for(int i=0;i<word2.size();i++){
            hash2[int(word2[i]-'a')]++;
        }
        // for(int i=0;i<28;i++){
        //     cout<<hash1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<28;i++){
        //     cout<<hash2[i]<<" ";
        // }
        // cout<<endl;
        if(hash1==hash2){
            return true;
        }
        for(int i=0;i<28;i++){
            if(hash1[i]==0 && hash2[i]!=0 || hash2[i]==0 && hash1[i]!=0)
                return false;
        }
        vector<int>leftOut1;
        vector<int>leftOut2;
        for(int i=0;i<28;i++){
            if(hash1[i]!=hash2[i]){
                leftOut1.push_back(hash1[i]);
                leftOut2.push_back(hash2[i]);
            }
                
        }
        sort(leftOut1.begin(),leftOut1.end());
        sort(leftOut2.begin(),leftOut2.end());
        
        return leftOut1==leftOut2;
        
        
    }
};