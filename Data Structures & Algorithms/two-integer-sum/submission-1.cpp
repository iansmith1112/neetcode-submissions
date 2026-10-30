class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visit;
        for (int i = 0; i < nums.size(); i++) {
            auto iterator = visit.find(target - nums[i]);
            if (iterator != visit.end() && iterator->second != i) {
                return {std::min(iterator->second, i), std::max(iterator->second, i)};
            }
            iterator = visit.find(nums[i]);
            if (iterator == visit.end()) visit.insert({nums[i], i});
        }
        return {};
    }
};
