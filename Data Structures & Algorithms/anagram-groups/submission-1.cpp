#include <algorithm>

class Solution {
private:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> sCount;
        unordered_map<char, int> tCount;
        for (int i = 0; i < s.size(); i++) {
            sCount[s[i]]++;
            tCount[t[i]]++;
        }
        return sCount == tCount;
    }
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
