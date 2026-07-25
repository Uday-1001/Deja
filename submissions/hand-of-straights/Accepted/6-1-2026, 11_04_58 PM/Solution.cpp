// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        sort(begin(hand) , end(hand));

        map<int , int>mp;

        for(auto it : hand) mp[it]++;

        for(auto it : hand)
        {
            if(mp.empty()) break;
            
            int next = mp.begin()->first;
            for(int i = 0 ; i<groupSize ; i++)
            {
                if(mp.count(next)) 
                {
                    mp[next]--;
                    if(mp[next] == 0) mp.erase(next);
                    next++;
                }
                else return false;
            }
        }
        return true;
    }
};