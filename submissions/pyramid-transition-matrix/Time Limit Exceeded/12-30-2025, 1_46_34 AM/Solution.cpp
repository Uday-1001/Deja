// https://leetcode.com/problems/pyramid-transition-matrix

class Solution {
public:
    static unordered_map<string , vector<char>> mp;
    bool byrec(int i , string &curr , string &next)
    {
        //reached the head of the pyramid
        if(curr.size() == 1) return true;
        //means that the above level is formed
        if(next.size() == (curr.size() - 1))
        {
            //reset the next string to empty for next level formation
            string empty = "";
            return byrec(0 , next , empty);
        }

        string basepair = curr.substr(i , 2);
        
        if(!mp.count(basepair)) return false;

        for(auto topchar : mp[basepair])
        {
            //push the topchar of the base 
            next.push_back(topchar);

            bool ans = byrec(i+1 , curr , next);
            if(ans == true) return true;

            //backtrack for more options
            next.pop_back();
        }
    return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        mp.clear();
        for(auto &it : allowed)
        {
            string base = it.substr(0 , 2);
            char top = it.back();
            mp[base].push_back(top);
        }
        string next = "";
        return byrec(0 , bottom , next);
    }
};
unordered_map<string, vector<char>> Solution::mp;