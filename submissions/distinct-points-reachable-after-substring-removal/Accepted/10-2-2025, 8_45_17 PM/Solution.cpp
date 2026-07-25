// https://leetcode.com/problems/distinct-points-reachable-after-substring-removal

class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>>st;
        pair<int,int>coord = {0,0};

        if(s.size() == k) return 1;
    
        for(auto ch : s)
        {
            if(ch == 'L') 
                coord.first--;
            else if(ch == 'R') 
                coord.first++;
            else if(ch == 'U') 
                coord.second++;
            else 
                coord.second--;
        }
        for(int i=0 ; i<k; i++)
        {
            //removing the elements of first window
            if(s[i] == 'L') 
                coord.first++;
            else if(s[i] == 'R')    
                coord.first--;
            else if(s[i] == 'U') 
                coord.second--;
            else
                coord.second++;

            // st.insert(coord); 
        }
        st.insert(coord);
        for(int i=k ; i<s.size() ; i++)
        {
            //removing the element
            int to_remove = s[i - k];

            if(to_remove == 'L') 
                coord.first++;
            else if(to_remove == 'R')    
                coord.first--;
            else if(to_remove == 'U') 
                coord.second--;
            else
                coord.second++; 

            //adding the element
            int to_add = s[i];

            if(to_add == 'L') 
                coord.first--;
            else if(to_add == 'R')    
                coord.first++;
            else if(to_add == 'U') 
                coord.second++;
            else
                coord.second--; 

            st.insert(coord);
        }
    return st.size();
    }
};