class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path compression
            x = parent[x];
        }
        return x;
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        parent[ry] = rx;
        sz[rx] += sz[ry];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // coordinate compression: map each number to an index
        unordered_map<int, int> index;
        int n = 0;
        for (int num : nums) {
            if (index.find(num) == index.end()) {
                index[num] = n++;
            }
        }

        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int num : nums) {
            if (index.count(num + 1)) {
                unite(index[num], index[num + 1]);
            }
        }

        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            maxSize = max(maxSize, sz[find(i)]);
        }
        return maxSize;
    }
};