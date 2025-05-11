class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int c = 0;
        for (int x : a) {
            c = (x % 2) ? c + 1 : 0;
            if (c == 3) return true;
        }
        return false;
    }
};