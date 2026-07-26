class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

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
        if (size[rx] < size[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        for (int n : nums) {
            if (parent.find(n) == parent.end()) {
                parent[n] = n;
                size[n] = 1;
            }
        }

        for (int n : nums) {
            if (parent.find(n + 1) != parent.end()) {
                unite(n, n + 1);
            }
        }

        int maxSize = 0;
        for (auto& [num, _] : parent) {
            maxSize = max(maxSize, size[find(num)]);
        }
        return maxSize;
    }
};