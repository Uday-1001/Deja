// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatching(string &s , int i , string &p , int j)
    {
        //base cases are somewhat little bit complex ->

        //means saare characters match hone ke baad khatam ho gyi string
        if(i == s.size() && j == p.size()) return true;

        //hum log tabhi true return karenge agar p string me last me sarre '*' ho kyuki unko NULL treat krliya jayega
        if(i == s.size() && j < p.size())
        {
            while(j < p.size())
            {
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        //ek case hum solve karenge baaaki recursion kardega
        if(s[i] == p[j] || p[j] == '?')
        {
            // means simple match ho rha h to dono pointers aage badhenge aur recursion aage dekhega
            return isMatching(s , i+1 , p , j+1);
        }
        // agar p string me character he '*' ho to fir -> 2 case banenge
        if(p[j] == '*')
        {
            //'*' ko as a NULL string treat kro aur aage badhao p pe pointer
            bool first_case = isMatching(s , i , p , j+1);

            //'*' ko 1 character consume krvado s string ka i.e s pointer ko aage badhao
            bool second_case = isMatching(s , i+1 , p , j);
            
            //khi se bhi agar tumhe true mile to true he output dedo
            return first_case || second_case;
        }

        //match nhi to fir ->
        return false;
    }
    
    bool isMatch(string s, string p) {
        int i = 0; 
        int j = 0;

        return isMatching(s , i , p , j);
    }
};