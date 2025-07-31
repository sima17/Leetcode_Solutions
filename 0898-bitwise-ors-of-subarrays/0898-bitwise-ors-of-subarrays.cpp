class Solution {
public:
    int subarrayBitwiseORs(vector<int>& ar) {
    
        int zero_seen = 0;
        vector<int> no_extra_zeros;
        for (int x : ar) {
            if (x == 0) {
                if (!zero_seen) {
                    no_extra_zeros.push_back(0);
                    zero_seen = 1;
                }
            } else {
                no_extra_zeros.push_back(x);
            }
        }

       
        vector<int> arr;
        for (int i = 0; i < no_extra_zeros.size(); ++i) {
            if (i == 0 || no_extra_zeros[i] != no_extra_zeros[i - 1]) {
                arr.push_back(no_extra_zeros[i]);
            }
        }

        int greatest = 0;
        for (auto k : arr) greatest |= k;
        if (greatest == 0) return 1;

        unordered_set<int> hash;
        int n = arr.size();
        int live = 0;
        for (int i = 0; i < n; i++) {
            live = arr[i];
            for (int j = i; j < n; j++) {
                live |= arr[j];
                hash.insert(live);
                if (live == greatest) break;
            }
        }
        return hash.size();
    }
};
---

---

---