class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visit;
        for (int i = 0; i < nums.size(); i++) {
            auto iterator = visit.find(target - nums[i]);
            if (iterator != visit.end() && iterator->second != i) {
                return {iterator->second, i};
            }
            visit[nums[i]] = i;
        }
        return {};
    }
};
