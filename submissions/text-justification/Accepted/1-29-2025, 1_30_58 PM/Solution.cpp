// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string>ans;
    vector<string>currentLine;
    int Linekechars = 0;

    for(int k = 0 ;k < words.size() ;k++)
    {
        string &curr_word = words[k];
        int spaces = currentLine.size();
        if(curr_word.size() + spaces + Linekechars > maxWidth)
        {
            int extraSp = maxWidth - Linekechars;
            int space_in_bw = extraSp / max(1,(int)(currentLine.size()-1));
            int remain = extraSp % max(1,(int)(currentLine.size()-1));

            for(int i = 0 ; i < currentLine.size()-1 ; i++)
            {
                for(int j = 0 ;j < space_in_bw ;j++)
                {
                    currentLine[i] += " ";
                    if(remain > 0)
                    {
                        currentLine[i] += " ";
                        remain--;
                    }
                }
            }
            if(currentLine.size() == 1)
            {
                while(extraSp--)
                currentLine[0] += " ";
            }
            string final = "";
            for(auto &st : currentLine)
            {
            final += st;
            }
            ans.push_back(final);
            currentLine.clear();
            Linekechars = 0;
        }
            currentLine.push_back(curr_word);
            Linekechars += curr_word.size();
    }
    
    string last_line = "";
    for(auto str : currentLine)
    {
        last_line += str + " ";
    }  
    last_line.pop_back();

    int left_spaces = maxWidth - last_line.size();
    while(left_spaces--)
    {
        last_line += " ";
    }
    ans.push_back(last_line);

    return ans;
    }
};