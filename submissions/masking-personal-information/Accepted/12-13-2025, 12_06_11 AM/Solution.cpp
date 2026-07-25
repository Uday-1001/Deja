// https://leetcode.com/problems/masking-personal-information

class Solution {
public:
    string maskPII(string s) {
        int n = s.size();
        string result = "";

        //email contains the '@' sign
        int symbolpos = s.find('@');
        if(symbolpos != string::npos)
        {        
            for(auto &ch : s) ch = tolower(ch);
            string name = s.substr(0 , symbolpos);
            string domain = s.substr(symbolpos);

            result.push_back(name.front());
            result += "*****";
            result.push_back(name.back());
            result += domain;

            return result;
        }
        else 
        {
            //confirms that it is a number 
            string str = "";
            for(auto &ch : s) if(isdigit(ch)) str.push_back(ch);

            int n = str.size();
            string masked_no = "***-***-";
            string lastfourdigits = str.substr(n-4);

            if(n == 10)
            {
                result += masked_no + lastfourdigits;
            }
            else
            {
                int country_code = n - 10;
                result = '+';
                result += string(country_code , '*');
                result += '-';
                result += masked_no;
                result += lastfourdigits;
            }
        return result;
        }
    }
};