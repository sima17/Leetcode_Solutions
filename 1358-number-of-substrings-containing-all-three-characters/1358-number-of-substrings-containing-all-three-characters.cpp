class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mappa;
        int res = 0;
        int i = 0, j = 0, n = s.size();
        while(j < n){
            mappa[s[j]]++;
            while(mappa.size() == 3){
                mappa[s[i]]--;
                if(mappa[s[i]] == 0)
                    mappa.erase(s[i]);
                res += n - j;
                i++;
            }
            j++;
        }
        return res;
    }
};