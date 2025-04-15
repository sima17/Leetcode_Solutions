typedef long long ll;
class Solution {
public:
    vector<ll> seg;
    void update(int cur, int l, int r, int target, int val) {
        if (l + 1 == r) {
            seg[cur] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (target < mid) update(cur << 1, l, mid, target, val);
        else update(cur << 1 | 1, mid, r, target, val);
        seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
        return;
    }

    ll find(int cur, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[cur];
        if (l >= qr || r <= ql) return 0;
        int mid = (l + r) >> 1;
        return find(cur << 1, l, mid, ql, qr) + find(cur << 1 | 1, mid, r, ql, qr);
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        seg.resize(n << 2, 0);

        vector<int> position(n);
        for (int i = 0; i < n; i++) position[nums1[i]] = i;

        vector<ll> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            int prev = find(1, 0, n, 0, position[nums2[i]] + 1);
            cnt[i] = prev;
            update(1, 0, n, position[nums2[i]], 1);
        }

        seg.clear();
        seg.resize(n << 2, 0);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) continue;
            ll prev = find(1, 0, n, 0, position[nums2[i]] + 1);
            ans += prev;
            update(1, 0, n, position[nums2[i]], cnt[i]);
        }
        return ans;
    }
};