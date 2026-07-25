// https://leetcode.com/problems/fruits-into-baskets-ii

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0;
        for(int i =0 ; i<fruits.size(); i++)
        {
            for(int j =0 ; j<baskets.size(); j++)
            {
                if(baskets[j] > 0)
                {
                    if(fruits[i] <= baskets[j])
                    {
                        baskets[j] = 0;
                        placed++;
                        break;
                    }
                }
            }     
        }
    return (baskets.size() - placed) ;
    }
};