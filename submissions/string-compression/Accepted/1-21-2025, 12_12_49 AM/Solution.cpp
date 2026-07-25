// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& s) {
        int index =0 , count = 1;
        char prev = s[0];

        for(int i = 1 ; i<s.size() ; i++)
        {
            if(s[i] == prev)
            {
                count ++;
            }
            else
            {
                s[index++] = prev;

                if(count > 1)
                {
                    int var = index ;
                    while(count)
                    {
                        s[index++] = (count % 10) + '0';
                        count /=10;                        
                    }
                    reverse(s.begin()+var , s.begin()+index);
                }
                prev = s[i];
                count = 1;
            }
        }
        s[index] = prev;
        index++;
        if(count > 1)
            {
                int var = index ;
                while(count)
                {
                    s[index++] = (count % 10) + '0';
                    count /=10;                        
                }
                reverse(s.begin()+var , s.begin()+index);
            }
    return index;
    }
};