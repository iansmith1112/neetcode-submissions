class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        sort(nums.begin(), nums.end());
        int count, maxCount;
        count = maxCount = 0;
        for(int i : nums) {
            if(lookup.find(i) != lookup.end()) continue;
            if (lookup.find(i-1) == lookup.end()) {
                count = 1; 
            }
            else {
                count++; 
            }
            lookup.insert(i);
            if(maxCount < count) maxCount = count;
        }
        return maxCount;
    }
};
