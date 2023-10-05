class Solution {
public:
    int fact(int n){
        int f=1;
        for(int i=2;i<=n;i++)
            f=f*i;
        return f;
    }
    string getPermutation(int n, int k) {
        set<vector<int>>s;
        vector<int>temp;
        for(int i=1;i<=n;i++){
            temp.push_back(i);
        }
        //vector<int>ans=temp;
        s.insert(temp);
        for(int i=0;i<k-1;i++){
            next_permutation(temp.begin(),temp.end());
      
        }
        //s.insert(ans);
        // int count=0;
        // vector<int>temp2(n);
        string wa="";
        // for(auto it:s){
        //     if(count==k-1){
        //         temp2={it};
        //         break;
        //     }
        //     count++;
        // }
        for(auto it:temp){
            //cout<<it<<" ";
            wa+=to_string(it);
        }
        return wa;
    }
};