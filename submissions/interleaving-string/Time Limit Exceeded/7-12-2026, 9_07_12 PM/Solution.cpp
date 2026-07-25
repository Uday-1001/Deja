// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool solve(string &s1 , string &s2 , string &s3 , int i , int j)
    {
        //base cases
        if(i > s1.size() or j > s2.size()) return false;
        if(i == s1.size() and j == s2.size()) return true;
        //if the first string is finished
        if(i == s1.size())
        {
            while(j < s2.size())
            {
                if(s2[j] != s3[i+j])
                    return false;
                j++;
            }
            return true;
        }
        //if the second string is finished
        if(j == s2.size())
        {
            while(i < s1.size())
            {
                if(s1[i] != s3[i+j])
                    return false;
                i++;
            }
            return true;
        }

        //both chars match case
        bool ans = false;
        if(s1[i] == s3[i+j] and s2[j] == s3[i+j])
        {
            bool option1 = solve(s1 , s2 , s3 , i+1 , j);
            bool option2 = solve(s1 , s2 , s3 , i , j+1);

            ans = ans or option1 or option2;
        }
        else if(s1[i] == s3[i+j])
        {
            ans = ans or solve(s1 , s2 , s3 , i+1 , j);
        }
        else if(s2[j] == s3[i+j])
        {
            ans = ans or solve(s1 , s2 , s3 , i , j+1);
        }

        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        return solve(s1 , s2 , s3 , 0 , 0);
    }
};