class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupsOfAnagrams;
        for(string toCheck : strs){
            string sorted = toCheck;
            std::sort(sorted.begin(), sorted.end());
            groupsOfAnagrams[sorted].push_back(toCheck);
        }
        vector<vector<string>> finalGroups;
        for(auto iterator = groupsOfAnagrams.begin(); iterator != groupsOfAnagrams.end(); ++iterator) {
            finalGroups.push_back(iterator->second);
        }
        return finalGroups;
    }
};
