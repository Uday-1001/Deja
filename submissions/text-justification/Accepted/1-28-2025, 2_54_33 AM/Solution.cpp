// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> currentLine;
        vector<string> ans;

        int curr_line_char = 0;

        for(int i=0 ; i<words.size() ;i++)
        {
            // Fully justified case
            string &curr_word = words[i];
            int spaces_req = currentLine.size();
            // exceeding the limit means the line is complete without the curr_word
            if(spaces_req + curr_word.size() + curr_line_char > maxWidth)
            {
                int extraSpaces = maxWidth - curr_line_char;
                int spaces_in_bw = extraSpaces / max(1,(int)(currentLine.size()-1));
                // uneven no. of spaces (if given)
                int remaining = extraSpaces %  max(1,(int)(currentLine.size()-1));

                for(int j =0 ; j < currentLine.size()-1 ; j++)
                {
                    for(int k =0 ; k < spaces_in_bw ; k++)
                    {
                        currentLine[j] += " ";
                        if(remaining > 0)
                        {
                            currentLine[j] += " ";
                            remaining--;
                        }
                    }
                }
                // single word in the line 
                if(currentLine.size() == 1)
                {
                    while(extraSpaces--)
                    currentLine[0] += " ";
                }
                string final_line = "";
                for(auto str : currentLine)
                {
                    final_line += str;
                }
                ans.push_back(final_line);
                currentLine.clear();
                curr_line_char = 0;
            }

            currentLine.push_back(curr_word);
            curr_line_char += curr_word.size();
        }
        // the final last line of the output
        string last_line = "";
        for(auto word : currentLine)
        {
            last_line += word + " ";
        }
        last_line.pop_back();
        // the last left spaces to be placed in the trails
        int last_left_spaces = maxWidth - last_line.size();
        while(last_left_spaces--)
        {
            last_line += " ";
        }

        ans.push_back(last_line);
        return ans ;
    }
};