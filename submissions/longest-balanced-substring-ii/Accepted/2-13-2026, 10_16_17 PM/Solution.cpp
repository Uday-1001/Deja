// https://leetcode.com/problems/longest-balanced-substring-ii

class Solution {
public:
    using pi = pair<int,int>;
    int n;
    struct PairHash 
    {
        size_t operator()(const pair<int,int>& p) const 
        {
            return ((uint64_t)p.first << 32) ^ (uint32_t)p.second;
        }
    };

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
        unordered_map<int , int>diff_two;

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
                diff_two.clear();
                first_cnt = 0;
                second_cnt = 0;
                continue;
            }

            if(first_cnt == second_cnt) 
            {
                maxlen = max(maxlen , first_cnt + second_cnt);
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
        unordered_map<pi , int , PairHash>diff_three;

        int first_cnt = 0;
        int second_cnt = 0;
        int third_cnt = 0;
        int maxlen = 0;

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s[i];
            //here, there is no case of streak to be broken
            //so we just use continue

            if(first == ch) first_cnt++;
            else if(second == ch) second_cnt++;
            else if(third == ch) third_cnt++;
            else continue;

            int first_diff = first_cnt - second_cnt;
            int second_diff = second_cnt - third_cnt;

            if(first_cnt == second_cnt && second_cnt == third_cnt) 
            {
                maxlen = max(maxlen , first_cnt + second_cnt + third_cnt);
            }

            pi pair = {first_cnt - second_cnt , second_cnt - third_cnt};

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