class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;

        for (size_t i = 0; i < strs.size(); i++) {
            string key = strs[i];

            sort(key.begin(), key.end());

            mp[key].push_back(strs[i]);
        }

        vector<vector<string> > result;

        for (unordered_map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
