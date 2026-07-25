// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        // count of the characters of the string
        for(int i=0; i<s.length(); i++)
        {
            hash[s[i] -'a'] ++;
        }
        // getting the most frequent character and the max freq of that character
        char most_frequent;
        int max_freq = INT_MIN;
        for(int i=0; i<26 ; i++)
        {
            if(hash[i]>max_freq)
            {
                max_freq = hash[i];
                most_frequent = i + 'a';
            }
        }
        // to put the most frequent character in the string 
        int index = 0;
        while(max_freq >0 && index < s.length())
        {
            s[index] = most_frequent;
            max_freq --;
            index += 2;
        }

        // if not done the above thing in one go then rearrangement is not possible
        // then return empty string
        if(max_freq != 0)
        {
            return "";
        }

        // going for the other characters after initializing most occurant count as 0
        hash[most_frequent -'a'] = 0;

        for(int i=0 ; i<26; i++)
        {
            while(hash[i]>0)
            {
                index = index >=s.length() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
       return s;     
    }
};