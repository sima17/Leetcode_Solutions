class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> result;
        result.reserve(words.size());    
        result.push_back(std::move(words[0]));
        int last = groups[0];
        for (int i = 1; i < (int)words.size(); ++i) {
            if (groups[i] != last) {
                result.push_back(std::move(words[i]));
                last = groups[i];
            }
        }
        return result;
    }
};