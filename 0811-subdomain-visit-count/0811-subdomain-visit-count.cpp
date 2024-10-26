class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hashMap;
        
        for (string it : cpdomains) {
            int num = 0;
            int i = 0;
            
            // Parse the visit count
            while (isdigit(it[i])) {
                num = num * 10 + int(it[i] - '0'); // Corrected the accumulation formula
                i++;
            }
            
            while (it[i] == ' ') {
                i++;
            }

            // Get the full domain after the count
            string parentDomain = it.substr(i, it.size() - i);
            hashMap[parentDomain] += num;

            // Split into subdomains
            while (true) {
                int start = parentDomain.find('.');
                
                if (start == string::npos) break; // No more subdomains

                string subDomain = parentDomain.substr(start + 1); 
                hashMap[subDomain] += num;
                
                parentDomain = subDomain; // Move to the next subdomain level
            }
        }

        // Prepare the result vector
        vector<string> ans;
        for (auto& pair : hashMap) {
            string viewCount = to_string(pair.second);
            string countPair = viewCount + " " + pair.first; // Corrected formatting of the result
            ans.push_back(countPair);
        }
        
        return ans;
    }
};
