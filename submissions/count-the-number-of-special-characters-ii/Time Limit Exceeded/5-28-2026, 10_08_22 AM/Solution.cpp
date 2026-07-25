// https://leetcode.com/problems/count-the-number-of-special-characters-ii

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char , bool>vis;

        int count = 0;
        for(auto it : word)
        {
            if(islower(it))
            {
                int upperidx = word.find(toupper(it));
                int loweridx = word.rfind(it);

                if(loweridx < upperidx and !vis[it]) 
                {
                    count++;
                    vis[it] = true;
                }
            } 
        }
        return count;
    }
};