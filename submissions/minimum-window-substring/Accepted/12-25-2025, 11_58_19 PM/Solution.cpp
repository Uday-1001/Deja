// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int count_req = t.size();

        unordered_map<char,int>mp;
        for(auto ch : t) mp[ch]++;

        int l = 0;
        int ans_start_pt = 0;
        int min_len_of_ans = INT_MAX;
        string ans = "";

        for(int r = 0 ; r < s.size() ; r++)
        {
            if(mp[s[r]] > 0) count_req--;
            mp[s[r]]--;

            //updating the answer when the count of char for t is met
            while(count_req == 0)
            {
                if((r - l + 1) < min_len_of_ans)
                {
                    min_len_of_ans = (r - l + 1);
                    ans_start_pt = l;
                }
                //shrinking the window using left pointer
                char left_char = s[l];
                mp[left_char]++;
                if(mp[left_char] > 0) count_req++;
                l++;
            }
        }
    return min_len_of_ans == INT_MAX ? "" : s.substr(ans_start_pt , min_len_of_ans);
    }
};