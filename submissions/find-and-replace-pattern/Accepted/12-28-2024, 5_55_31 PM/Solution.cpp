// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
     
     void normalise(string &str){
        int start = 'a';
        unordered_map<char,char> map;
        for(int i=0; i<str.length();i++)
        {
            char strKachar = str[i];
            if(map.find(strKachar) == map.end())
            //nahi hai koi mapping iska matlab 
            {
                map[strKachar] =start ;
                start ++;
            }
        }
        for (int i=0; i<str.length(); i++)
        {
            //yha pr jo mapped character hai map usko original word se replace kr diya hai 
            // jaise map me d -> a , e -> b , f -> c
            //to us map mese 'a' ko uthke 'd' ki jagah rakh diya so that word change ho jaye to abc format      
            char mappedchar = map[str[i]];
            str[i] = mappedchar;
        }
     }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //normalise krdo pattern ko
        normalise(pattern);
        vector<string> ans;
        for(int i=0; i<words.size();i++)
        {
            string currword = words[i];
           string wordKicopy = currword;
            // copy me sab changes honge aur main data lost nhi hoga
            normalise(wordKicopy);
            if(wordKicopy.compare(pattern)==0)
            {
                //means dono exact same hai 
                ans.push_back(currword);
            }  
        }
        return ans;
    }
};