class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> temp; // Use a vector of strings to store reversed words
        int start = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                string word = s.substr(start, i - start); // Extract the word
                reverse(word.begin(), word.end()); // Reverse the word
                temp.push_back(word); // Store the reversed word in the vector
                start = i + 1; // Update the start index for the next word
            }
        }
        
        // Handle the last word
        string lastWord = s.substr(start);
        reverse(lastWord.begin(), lastWord.end());
        temp.push_back(lastWord);
        
        // Concatenate the reversed words with spaces
        for (const string& word : temp) {
            ans += word + " ";
        }
        
        if (!ans.empty()) {
            // Remove the trailing space
            ans.pop_back();
        }
        
        return ans;
    }
};
