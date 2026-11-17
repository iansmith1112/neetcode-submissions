class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> lookup;
        for(int i : nums) {
            if(lookup.find(i) != lookup.end()) return true;
            lookup.insert(i);
        }
        return false;
    }
};