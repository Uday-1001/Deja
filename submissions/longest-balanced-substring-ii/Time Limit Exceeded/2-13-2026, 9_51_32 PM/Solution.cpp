// https://leetcode.com/problems/longest-balanced-substring-ii

class Solution {
public:
    int n;
    unordered_map<int , int>diff_two;
    unordered_map<string , int>diff_three;

    int forOnlyOneCharacter(string &s)
    {
        char ch = s[0];
        int count = 1;
        int max_count = 1; 

        for(int i = 1 ; i<n ; i++)
        {
            if(ch == s[i]) 
            {
                count++;
                max_count = max(max_count , count);
            }
            else
            {
                ch = s[i];
                count = 1;
            }
        }
    return max_count;
    }

    int forOnlyTwoCharacters(string &s , char first , char second)
    {   
        diff_two.clear();
        diff_two[0] = -1;

        int first_cnt = 0;
        int second_cnt = 0;
        int maxlen = 0;

        for(int i = 0 ; i<n; i++)
        {
            char ch = s[i];
            if(first == ch) first_cnt++;
            else if(second == ch) second_cnt++;
            else 
            {
                //streak for the two characters has been broken 
                //so reset all the parameters
                first_cnt = 0;
                second_cnt = 0;
                diff_two.clear();
                diff_two[0] = i;
                continue;
            }

            int diff = first_cnt - second_cnt;

            if(!diff_two.count(diff))
            {
                diff_two[diff] = i;
            }
            else maxlen = max(maxlen , i - diff_two[diff]);
        }
    return maxlen;
    }

    int forAllThreeCharacters(string &s , char first , char second , char third)
    {
        diff_three.clear();
        diff_three["0_0"] = -1;

        int first_cnt = 0;
        int second_cnt = 0;
        int third_cnt = 0;
        int maxlen = 0;

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s[i];
            //here there is no case of streak to be broken
            //so we just use continue
            if(first == ch) first_cnt++;
            else if(second == ch) second_cnt++;
            else if(third == ch) third_cnt++;
            else continue;

            int first_diff = first_cnt - second_cnt;
            int second_diff = second_cnt - third_cnt;

            string pair = to_string(first_diff) + "_" + to_string(second_diff);

            if(!diff_three.count(pair))
            {
                diff_three[pair] = i;
            }
            else maxlen = max(maxlen , i - diff_three[pair]);
        }
    return maxlen;
    }

    int longestBalanced(string s) {
        n = s.size();

        int ans1 = forOnlyOneCharacter(s);

        int ans2 = max({forOnlyTwoCharacters(s , 'a' , 'b') , forOnlyTwoCharacters(s , 'b' , 'c') , forOnlyTwoCharacters(s , 'a' , 'c')});

        int ans3 = forAllThreeCharacters(s , 'a'  , 'b' , 'c');

        return max({ans1 , ans2 , ans3});
    }
};