// https://leetcode.com/problems/binary-watch

class Solution {
public:
    int getbits(int n)
    {
        int count = 0;
        while(n > 0)
        {
            if(n % 2 == 1) count++;
            n /= 2;
        }
        return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        vector<int>hours(12);
        vector<int>minutes(60);

        if(turnedOn > 8 or turnedOn == 0) return ans;

        for(int i = 0 ; i<12 ; i++) hours[i] = (getbits(i));
        for(int i = 0 ; i<60 ; i++) minutes[i] = (getbits(i));


        for(int i = 0 ; i<hours.size() ; i++)
        {
            if(hours[i] <= turnedOn)
            {
                int req_bits = turnedOn - hours[i];
                for(int j = 0 ; j<minutes.size(); j++)
                {
                    string s = "";
                    if(minutes[j] == req_bits)
                    {
                        s = to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j);
                        ans.push_back(s);
                    }
                }
            }
        }
        return ans;
        
    }
};