class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right) {
                if(nums[left] + nums[right] == -nums[i]){
                    result.push_back({nums[i], nums[left], nums[right]});
                    int duplicate = nums[left];
                    while(left < right && nums[left] == duplicate) left++;
                    duplicate = nums[right];
                    while(left < right && nums[right] == duplicate) right--;
                    continue;
                }
                if(nums[left] + nums[right] > -nums[i]) {
                    right--;
                }
                else left++;

            }
        }
        return result;
    }
};
