class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int limit=arr.size()/4;
        //map<int,int> count;
        vector<int> hash(1000001,0);
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]>limit)
                return i;
        }
        return 0;
    }
};