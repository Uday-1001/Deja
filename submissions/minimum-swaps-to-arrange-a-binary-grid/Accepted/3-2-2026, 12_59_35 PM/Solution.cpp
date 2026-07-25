// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid

class Solution {
public:
    int findOne(vector<int>& row) 
    {
        for (int i = row.size() - 1; i >= 0; i--) 
        {
            if (row[i] == 1) return i; 
        }
        return -1;  
    }

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int swaps = 0;
        vector<int> lastones;

        for(int i = 0 ; i < n ; i++)
        {
            int lastone = findOne(grid[i]);
            lastones.push_back(lastone);
        }

        for(int i = 0; i < n; i++)
        {
            bool found = false;

            for(int j = i; j < n; j++)
            {
                if(lastones[j] <= i)
                {
                    for(int k = j; k > i; k--)
                    {
                        swap(lastones[k], lastones[k - 1]);
                        swaps++;
                    }
                    found = true;
                    break;
                }
            }

            if(!found) return -1;
        }

        return swaps;
    }
};