// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0;
        int prevchar = s[0];
        int count = 1;

        for(int i = 1 ; i<s.size() ; i++)
        {
            if(s[i] == prevchar) count++;
            else 
            {
                s[index] = prevchar;
                index++;
                int start = index;
                if(count > 1)
                {
                    while(count)
                    {
                        s[index] = (count % 10) + '0';
                        index++;
                        count /= 10; 
                    }
                }
                reverse(s.begin() + start , s.begin() + index);
                prevchar = s[i];
                count = 1;
            }
        }
        s[index] = prevchar;
        index++;
        int start = index;
        if(count > 1)
        {
            while(count)
            {
                s[index] = (count % 10) + '0';
                index++;
                count /= 10; 
            }
        }
        reverse(s.begin() + start , s.begin() + index);
    return index;
    }
};