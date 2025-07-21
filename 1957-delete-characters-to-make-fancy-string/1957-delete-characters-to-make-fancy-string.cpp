class Solution {
public:
    string makeFancyString(string s) {
        int count = 1, n = s.length();
        string res = "";
        if (n == 1) return s;

        res += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                count = 1;
                res += s[i];
            } else if (count < 2) {
                res += s[i];
                count++;
            } else {
                continue;
            }
        }
        return res;
    }
};