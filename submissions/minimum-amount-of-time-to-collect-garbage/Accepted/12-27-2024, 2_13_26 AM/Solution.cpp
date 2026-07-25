// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //initializing the components of the program
        int pickP=0;
        int travelP=0;
        int lasthouseP=0;

        int pickM=0;
        int travelM=0;
        int lasthouseM=0;

        int pickG=0;
        int travelG=0;
        int lasthouseG=0;

        for(int i=0; i<garbage.size() ;i++){

            string currentHouse = garbage[i];

            for(int j=0 ; j< currentHouse.length(); j++){

                char garbagetype = currentHouse[j];
                if(garbagetype == 'P')
                {
                    pickP++;
                    lasthouseP = i;
                }
                if(garbagetype == 'M')
                {
                    pickM++;
                    lasthouseM = i;
                }
                if(garbagetype == 'G')
                {
                    pickG++;
                    lasthouseG = i;
                }
            }
        }
        for(int i=0 ; i<lasthouseP ; i++)
        {
            travelP += travel[i];
        }
         for(int i=0 ; i<lasthouseM ; i++)
        {
            travelM += travel[i];
        }
         for(int i=0 ; i<lasthouseG ; i++)
        {
            travelG += travel[i];
        }
        int traveltime = travelP + travelM + travelG;
        int picktime = pickG + pickM + pickP ;

        int totaltime = traveltime + picktime ;
        return totaltime;
        
    } 
};