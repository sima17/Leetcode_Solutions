class Solution {
public:
    static long maximumTripletValue(const vector<int>& a) {
        const int n = a.size();
        long maxt = 0;
        long maxd = 0;
        long maxi = 0;
        for (int k = 0; k < n; ++k) {
            const long ak = a[k];
            maxt = max(maxt, maxd * ak);
            maxd = max(maxd, maxi - ak);
            maxi = max(maxi, ak);
        }
        return maxt;
    }
};