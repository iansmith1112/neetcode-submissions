class Solution {
public:
    string encode(vector<string>& strs) {
        string built;
        for(string s : strs) {
            built.append(to_string(s.length()) + " " + s);
        }
        return built;
    }

    vector<string> decode(string s) {
        size_t pos = 0;
        vector<string> list; 
        while(pos < s.size()) {
            size_t chars_read = 0;
            int len = std::stoi(s.substr(pos), &chars_read);
            pos += chars_read + 1;
            list.push_back(s.substr(pos, len));
            pos += len;
        }
        return list;
    }
};
