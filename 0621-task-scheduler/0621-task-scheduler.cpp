class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_freq=0, sz=tasks.size();
        int freq[26]={0};
        for(char c: tasks){
            int f=++freq[c-'A'];
            max_freq=max(max_freq, f);
        }
        int num_maxFreq=count(freq, freq+26, max_freq);
        
        int time=(max_freq-1)*(n+1)+num_maxFreq;
        return max(time, sz);
    }
};