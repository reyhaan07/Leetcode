class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> lsrc;
        long long longest=0;
        int l=0,r=0;
        while(r<s.size())
        {
            while(lsrc.count(s[r]))
            {
                lsrc.erase(s[l]);
                l++;
            }
            lsrc.insert(s[r]);
            longest=max(longest,(long long)r-l+1);
            r++;

        }
        return longest;

    }
};