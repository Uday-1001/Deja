// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string f ="";
        unordered_map<char,int>mapping;
        //mapping the frequency of the characters
        for(int i=0 ; i<n ; i++)
        {
            mapping[s[i]]++;
        }
        //calculating the most frequent character of the string 
        int max_freq = INT_MIN;
        char most_freq;
        for(auto it : mapping)
        {
            if(it.second > max_freq)
            {
                max_freq = it.second;
                most_freq = it.first;
            }
        }
        //placing the most frequent character first in the string in one go
        int index = 0;
        while(max_freq > 0 && index < s.size())
        {
            s[index] = most_freq;
            max_freq --;
            index += 2;
        }
        if(max_freq != 0)
        {
            return "";
        }
        //manually making the most_freq character to disappear
        mapping[most_freq] = 0;
        
        for(auto &it : mapping)
        {
            while(it.second > 0)
            {
                if(index >= n) index = 1;
                s[index] = it.first;
                it.second --;
                index += 2;
            }
        }
        return s;   
    }
};