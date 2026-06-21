class Solution {
public:
    bool isPalindrome(string s) {
      s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        for(int i = 0;i < s.size(); i++)
        {   if(isalpha(s[i]) || isdigit(s[i]))
                s[i] = toupper(s[i]);
            else
            {
                s.erase(i, 1);
                i--;
            }
        }
        for(int i = 0, j = s.size() - 1; i <= s.size() / 2; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
