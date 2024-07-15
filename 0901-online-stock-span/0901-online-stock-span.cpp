class StockSpanner {
public:
    vector<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        st.push_back(price);
        int count=0;
        int ans=1;
        int i=st.size()-1;
        while(i>=0 && st[i]<=price){
            count++;
            i--;

        }
        return max(count,ans);
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */