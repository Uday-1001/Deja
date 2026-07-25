// https://leetcode.com/problems/counting-words-with-a-given-prefix

class Solution {
public:

    bool isPrefix(string &a  , string &b){
        int len = b.length();
        string pref = a.substr(0,len);

        if(pref == b)
        {
            return true;
        }
        return false;
    }

    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        string curr_string ="";
        for(auto str : words)
        {
            curr_string = str;
            if(isPrefix(str , pref))
            {
                ++count ;
            }
        }
      return count ;  
    }
};