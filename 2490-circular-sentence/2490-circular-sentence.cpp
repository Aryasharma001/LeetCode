class Solution {
public:
    bool isCircularSentence(string sentence) {
        char last_char=sentence[0];
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                if(i+1<sentence.size() && sentence[i+1]!=last_char)
                    return false;
            }
            last_char=sentence[i];
        }
        if(last_char!=sentence[0])
            return false;
        return true;    
    }
};