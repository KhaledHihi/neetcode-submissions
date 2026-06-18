#include <algorithm>
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        std::cout << t << " " << s << std::endl;
        return s == t;
    }
};
