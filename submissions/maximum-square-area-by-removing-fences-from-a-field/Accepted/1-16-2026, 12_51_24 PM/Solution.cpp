// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field

class Solution {
public:
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int>newh = hFences;
        vector<int>newv = vFences;
        long long maxside = 0;

        newh.push_back(1);
        newh.push_back(m);
        newv.push_back(1);
        newv.push_back(n);

        sort(newh.begin() , newh.end());
        sort(newv.begin() , newv.end());

        set<int>st;
        for(int i = 0 ; i < newh.size() ; i++)
        {
            for(int j =i+1 ; j<newh.size() ; j++)
            {
                st.insert(newh[j] - newh[i]);
            }
        }
        
        for(int i = 0 ; i < newv.size() ; i++)
        {
            for(int j =i+1 ; j<newv.size() ; j++)
            {
                int vgap = newv[j] - newv[i];
                if(st.count(vgap))
                {
                    maxside = max<long long>(maxside , vgap);
                }
            }
        }
        if(maxside == 0) return -1;
        else return (maxside * maxside) % mod;
    }
};