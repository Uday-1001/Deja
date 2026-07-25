// https://leetcode.com/problems/count-the-number-of-special-characters-ii

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char , int>stupper;
        unordered_map<char , int>stlower;

        for(auto it : word)
        {
            if(isupper(it)) stupper[it] = word.find(it);
            else stlower[it] = word.rfind(it);
        }

        int count = 0;
        for(auto it : word)
        {
            if(islower(it))
            {
                if(stlower[it] < stupper[toupper(it)]) 
                {
                    count++;
                    stlower[it] = 0;
                    stupper[toupper(it)] = -1;
                }
            }
        }
        return count;
    }
};