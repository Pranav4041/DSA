class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& nums, int index) {

        // Base case
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Don't take current element
        backtrack(nums, index + 1);

        // Choice 2: Take current element
        current.push_back(nums[index]);

        backtrack(nums, index + 1);

        // Undo the choice (Backtrack)
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, 0);

        return ans;
    }
};