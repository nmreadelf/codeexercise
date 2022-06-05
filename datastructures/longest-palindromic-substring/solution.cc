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



class Solution {
public:
    struct res {
        int start;
        int len;

        res(): start(0), len(0) {
        }

        res(int _start, int _len): start(_start), len(_len) {
        }

    };

    res palindrome(std::string& s, int left, int right) {
        while (left >= 0 &&  right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        const int n = right - (left + 1);
        return res(left+1, n);
    }
    string longestPalindrome(string s) {
        res r;
        for (int i = 0; i < s.size(); i++) {
            // s[i] as middle long palindrome
            const res res1 = palindrome(s, i, i);
            // s[i] and s[i+1] as middle long palindrome
            const res res2 = palindrome(s, i, i+1);
            if (res1.len > r.len) {
                r = res1;
            }
            if (res2.len > r.len) {
                r = res2;
            }
        }
        if (r.len == 0) {
            return "";
        }
        return s.substr(r.start, r.len);
    }
};


class Solution {
public:
    std::tuple<int, int> palindrome(std::string& s, int left, int right) {
        while (left >= 0 &&  right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        const int n = right - (left + 1);
        return std::make_tuple(left+1, n);
    }
    string longestPalindrome(string s) {
        std::tuple<int, int> r{0, 0};
        for (int i = 0; i < s.size(); i++) {
            // s[i] as middle long palindrome
            std::tuple<int, int> res1 = palindrome(s, i, i);
            // s[i] and s[i+1] as middle long palindrome
            std::tuple<int, int> res2 = palindrome(s, i, i+1);
            if (std::get<1>(res1) > std::get<1>(r)) {
                r = res1;
            }
            if (std::get<1>(res2) > std::get<1>(r)) {
                r = res2;
            }
        }
        if (std::get<1>(r) == 0) {
            return "";
        }
        return s.substr(std::get<0>(r), std::get<1>(r));
    }
};

