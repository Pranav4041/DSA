class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: build frequency map
    unordered_map<int, int> freqMap;
    for (int n : nums) {
        freqMap[n]++;
    }

    // Step 2: convert map into vector of pairs {element, frequency}
    vector<pair<int,int>> freqList(freqMap.begin(), freqMap.end());

    // Step 3: sort by frequency, descending
    sort(freqList.begin(), freqList.end(), [](pair<int,int>&a, pair<int,int>&b){
        return a.second > b.second;
    });

    // Step 4: take the top k elements
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(freqList[i].first);   // .first = element, .second = frequency
    }
    return result;
}
};