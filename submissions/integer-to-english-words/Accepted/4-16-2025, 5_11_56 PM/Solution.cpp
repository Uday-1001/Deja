// https://leetcode.com/problems/integer-to-english-words

class Solution {
public:
    vector<pair<string, int>> mp = {
    {"Billion", 1000000000}, {"Million", 1000000}, {"Thousand", 1000}, {"Hundred", 100},
    {"Ninety", 90}, {"Eighty", 80}, {"Seventy", 70}, {"Sixty", 60}, {"Fifty", 50}, {"Forty", 40}, {"Thirty", 30},
    {"Twenty", 20}, {"Nineteen", 19}, {"Eighteen", 18}, {"Seventeen", 17}, {"Sixteen", 16}, {"Fifteen", 15}, 
    {"Fourteen", 14}, {"Thirteen", 13}, {"Twelve", 12}, {"Eleven", 11}, {"Ten", 10}, {"Nine", 9}, {"Eight", 8}, 
    {"Seven", 7}, {"Six", 6}, {"Five", 5}, {"Four", 4}, {"Three", 3}, {"Two", 2}, {"One", 1}};

    string numberToWords(int num) {
        //base case 
        if(num == 0) return "Zero";

        //ek case hum solve karenge baaki recursion karlega
        for(auto pair : mp)
        {
            if(num >= pair.second)
            {
                string firstpart = "";
                if(num >= 100)
                {
                    firstpart = numberToWords(num / pair.second) + " ";
                }

                string middlepart = pair.first;

                string lastpart = "";
                if(num % pair.second != 0)
                {
                    lastpart = " " + numberToWords(num % pair.second);
                }

                return firstpart + middlepart + lastpart;
            }
        }
    return "";
    }
};