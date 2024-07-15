class StockSpanner {
public:
    stack<pair<int, int>> st; // Stack to hold pairs of (price, span)
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; // Initial span value is 1
        // While the stack is not empty and the top price is less than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the span of the top price to the current span
            st.pop(); // Pop the top element
        }
        st.push({price, span}); // Push the current price and its span onto the stack
        return span; // Return the calculated span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
