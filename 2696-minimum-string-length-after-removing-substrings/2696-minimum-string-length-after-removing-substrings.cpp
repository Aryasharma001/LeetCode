class Solution {
public:
    int minLength(string s) {
        // Use a stack to process the string
        stack<char> st;
        for (char c : s) {
            // Check for "AB" or "CD" patterns and remove them
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                st.pop();  // Remove the previous character if a pattern is found
            } else {
                st.push(c);  // Otherwise, add the character to the stack
            }
        }
        return st.size();  // The size of the stack gives the minimum length
    }
};
