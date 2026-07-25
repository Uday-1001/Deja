// https://leetcode.com/problems/count-collisions-on-a-road

class Solution {
public:
    int countCollisions(string directions) {
        int collide = 0;

        int i = 0;
        int j = directions.size()-1;
        
        if(directions.size() == 1) return 0;

        //skip the same direction cars
        if(directions.size() > 1)
        {
            while(directions[i] == 'L') i++;
            while(directions[j] == 'R') j--;   
        }

        for(int k = i ; k<=j ; k++)
        {
            if(directions[k] != 'S') collide ++;
            else continue;
        }

        return collide;        
    }
};