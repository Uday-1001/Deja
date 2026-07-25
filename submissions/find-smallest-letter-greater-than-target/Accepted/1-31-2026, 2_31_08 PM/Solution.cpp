// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char max_letter = letters[0];
        for(int i = 0 ; i<letters.size() ; i++)
        {
            char l = letters[i];
            if(l > target)
            {
                max_letter = l;
                break;
            }
        }
        return max_letter;
    }
};