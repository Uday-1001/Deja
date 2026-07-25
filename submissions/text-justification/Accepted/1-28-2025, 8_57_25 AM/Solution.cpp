// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currentLine;
        int currentLinekechar = 0;

        for(int i=0 ; i<words.size() ;i++)
        {
            string &curr_word = words[i];
            int spaces = currentLine.size();
            
            if(curr_word.size() + spaces + currentLinekechar > maxWidth)
            {
                int extraSpaces = maxWidth - currentLinekechar;
                int spaces_in_bw = extraSpaces / max(1,(int)(currentLine.size()-1));
                int remaining_spaces = extraSpaces % max(1,(int)(currentLine.size()-1));

                for(int j=0 ; j < currentLine.size()-1 ; j++)
                {
                    for(int k =0 ; k < spaces_in_bw ; k++)
                    {
                        currentLine[j] += " ";
                        if(remaining_spaces > 0)
                        {
                            currentLine[j] += " ";
                            remaining_spaces--;
                        }
                    }
                }
                if(currentLine.size() == 1)
                {
                    while(extraSpaces--)
                    currentLine[0] += " ";
                }
            
                string final_line = "";
                for(auto str : currentLine)
                
                final_line += str;
                
                ans.push_back(final_line);
                currentLine.clear();
                currentLinekechar = 0;
            }
            currentLine.push_back(curr_word);
            currentLinekechar += curr_word.size();
        }
        string last_line = "";
        for(auto word : currentLine)
        {
            last_line += word + " ";
        }
        last_line.pop_back();
        
        int left_spaces = maxWidth - last_line.size();

        while(left_spaces--)
        {
            last_line += " "; 
        }
        ans.push_back(last_line);

        return ans ;
    }
};