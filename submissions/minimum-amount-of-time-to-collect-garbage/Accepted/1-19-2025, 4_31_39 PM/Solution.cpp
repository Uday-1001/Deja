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

          // har ghar pe jaake dekho  
        for(int i=0; i<garbage.size() ;i++){

            string currentHouse = garbage[i];
               // jo bhi ghar gye ho vha kaun se type ka garbage hai 
            for(int j=0 ; j< currentHouse.length(); j++){

                char garbagetype = currentHouse[j];
                
                if(garbagetype == 'P')
                {
                    pickP++;
                    // yha tak to truck aaya he hoga to ise store krlo jisse travel time nikal ske 
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
        // sabka travel time alag alag calculated
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
        // total travel and pick time he total time hai !
        int traveltime = travelP + travelM + travelG;
        int picktime = pickG + pickM + pickP ;

        int totaltime = traveltime + picktime ;
        return totaltime;
        
    } 
};