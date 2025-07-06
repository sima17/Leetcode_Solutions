class FindSumPairs {
    unordered_map<int, int> m1, m2;
    vector<int> n1, n2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;

        for (int num : nums1) {
            m1[num]++;
        }

        for (int num : nums2) {
            m2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = n2[index];
        int newVal = oldVal + val;

        m2[oldVal]--;
        m2[newVal]++;
        n2[index] = newVal;
    }

    int count(int tot) {
        int ans = 0;
        for (auto& [val2, freq2] : m2) {
            int val1 = tot - val2;
            if (m1.count(val1)) {
                ans += m1[val1] * freq2;
            }
        }
        return ans;
    }
};
