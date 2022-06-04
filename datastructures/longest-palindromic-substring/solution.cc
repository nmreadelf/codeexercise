class Solution {
public:
    string palindrome(std::string& s, int left, int right) {
        while (left >= 0 &&  right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1, right-(left+1));
    }
    string longestPalindrome(string s) {
        std::string res = "";
        for (int i = 0; i < s.size(); i++) {
            // s[i] as middle long palindrome
            std::string s1 = palindrome(s, i, i);
            // s[i] and s[i+1] as middle long palindrome
            std::string s2 = palindrome(s, i, i+1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }
};

