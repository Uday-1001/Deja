// https://leetcode.com/problems/rearrange-string-to-avoid-character-pair

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int countx = 0;
        int county = 0;

        string news = "";

        for(int i = 0; i <s.size() ; i++)
        {
            if(s[i] == x) countx++;
            else if(s[i] == y) county++;
            else news.push_back(s[i]);
        }

        if(countx == 0) return s;
        while(county--) news.push_back(y);
        while(countx--) news.push_back(x);

        return news;
    }
};