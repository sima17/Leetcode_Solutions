 class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        bool hascenter = false;

        for (const string& word : words) {
            map[word]++;
        }

        int equal = 0; // count of same-letter word pairs
        int rev = 0;   // count of reversible pairs

        for (auto it = map.begin(); it != map.end(); ++it) {
            string st = it->first;
            if (st[0] == st[1]) {
                // e.g., "gg", "cc"
                if (it->second % 2 != 0) {
                    hascenter = true;
                    equal += it->second - 1;
                } else {
                    equal += it->second;
                }
            } else {
                string ts = st;
                reverse(ts.begin(), ts.end());
                if (map.find(ts) != map.end()) {
                    rev += min(it->second, map[ts]);
                }
            }
        }

        // Each reversible pair counted twice, so halve it
        rev /= 2;

        // Each pair contributes 4 letters, and center (if any) adds 2
        return rev * 4 + equal * 2 + (hascenter ? 2 : 0);
    }
};