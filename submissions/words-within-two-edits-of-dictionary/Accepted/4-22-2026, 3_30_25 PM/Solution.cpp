// https://leetcode.com/problems/words-within-two-edits-of-dictionary

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;

        for(int i = 0 ; i<queries.size() ; i++)
        {
            string to_match = queries[i];

            for(int j = 0; j<dictionary.size() ; j++)
            {
                int non_matching = 0; 
                string word = dictionary[j];
                for(int k = 0 ; k<word.size() ; k++)
                {
                    if(word[k] != to_match[k]) non_matching++;
                }
                if(non_matching > 2) continue;
                else 
                {
                    ans.push_back(to_match);
                    break;
                }
            }
        }
        return ans;
    }
};