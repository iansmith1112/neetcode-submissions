class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> que;
        unordered_map<int, int> counts;
        for(int i : nums) {
            counts[i]++;
        }
        for(auto iterator = counts.begin(); iterator != counts.end(); iterator++) {
            que.push({iterator->second, iterator->first}); // second goes first because it is the element used for compare
        }   
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(que.top().second);
            que.pop();
        }
        return result;
    }
};
