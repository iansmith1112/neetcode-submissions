class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int size = 0;
        int maxSize = 0;
        unordered_set<char> lookup;
        for (; right < s.size(); right++) {
            // check if char is already present and move left until it doesn't
            while(lookup.find(s[right]) != lookup.end() && left < right){
                lookup.erase(s[left]);
                left++;
                size--;
            }
            // add char to hash set
            lookup.insert(s[right]);
            size++;
            if(maxSize < size) maxSize = size;
        }
        return maxSize;
    }
};
