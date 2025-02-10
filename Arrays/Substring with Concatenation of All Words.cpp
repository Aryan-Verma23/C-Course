class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> counts;
        for (int i = 0; i < words.size(); i++)
            counts[words[i]]++;

        int n = s.length();
        int wordsize = word.size();
        int len = word[0].size();
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int start = i, count = 0;
            unordered_map<string, int> mp;
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(i, len);
                if (counts.find(word) != counts.end()) {
                    mp[word]++;
                    count++;

                    
                }
            }
        }
        return ans;
    }
};