// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations

class Solution {
public:
    string additionOfAatoddpositions(string &s , int &a)
    {
        for(int i=1 ; i<s.size() ; i+=2)
        {
            int added_digit = ((s[i]-'0') + a) % 10;
            s[i] = (added_digit + '0');
        }
    return s;
    }

    string rotationByBMoves(string &s , int &b)
    {
        string first_part = s.substr(0,s.size() - b);
        string second_part = s.substr(s.size() - b);

        string final_str = second_part + first_part;

        return final_str;
    }

    string findLexSmallestString(string s, int a, int b) {
        set<string>vis;
        queue<string>q;

        string mini = s;

        q.push(s);
        vis.insert(s);

        while(!q.empty())
        {
            string front = q.front();
            q.pop();

            mini = min(mini , front);

            string added = additionOfAatoddpositions(front , a);
            if(!vis.count(added))
            {
                q.push(added);
                vis.insert(added);
            }

            string rotated = rotationByBMoves(front , b);
            if(!vis.count(rotated))
            {
                q.push(rotated);
                vis.insert(rotated);
            }
        }
    return mini;
    }
};