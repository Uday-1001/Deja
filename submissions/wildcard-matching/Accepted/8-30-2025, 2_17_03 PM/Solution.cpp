// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    //make a dp array
    int dp[2001][2001];

    bool bymemo(string &s , int i , string &p , int j)
    {
        //means saare characters match hone ke baad khatam ho gyi string
        if(i == s.size() && j == p.size())
        {
            return dp[i][j] = 1;
        }

        //hum log tabhi true return karenge agar p string me last me sarre '*' ho kyuki unko NULL treat krliya jayega
        if(i == s.size() && j < p.size())
        {
            while(j < p.size())
            {
                if(p[j] != '*') return dp[i][j] = 0;
                j++;
            }
            return dp[i][j] = 1;
        }

        //check for existence of an answer
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        //ek case hum solve karenge baaaki recursion kardega
        if(s[i] == p[j] || p[j] == '?')
        {
            // means simple match ho rha h to dono pointers aage badhenge aur recursion aage dekhega
            ans = bymemo(s , i+1 , p , j+1);
        }
        // agar p string me character he '*' ho to fir -> 2 case banenge
        if(p[j] == '*')
        {
            //'*' ko as a NULL string treat kro aur aage badhao p pe pointer
            bool first_case = bymemo(s , i , p , j+1);

            //'*' ko 1 character consume krvado s string ka i.e s pointer ko aage badhao
            bool second_case = bymemo(s , i+1 , p , j);
            
            //khi se bhi agar tumhe true mile to true he output dedo
            ans = (first_case || second_case);
        }
    return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {

        memset(dp , -1 , sizeof(dp));

        return bymemo(s , 0 , p , 0);
    }
};