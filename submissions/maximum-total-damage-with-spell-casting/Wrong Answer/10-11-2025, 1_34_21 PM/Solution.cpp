// https://leetcode.com/problems/maximum-total-damage-with-spell-casting

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        set<int>st;

        int damage_done = 0;

        for(int i=0 ; i<power.size() ; i++)
        {
            int damage = power[i];
            if(st.find(damage) == st.end())
            {
                damage_done += damage;
                st.insert(damage-2);
                st.insert(damage-1);
                st.insert(damage+1);
                st.insert(damage+2);
            }
        }
    return damage_done;
    }
};