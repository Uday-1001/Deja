// https://leetcode.com/problems/letter-tile-possibilities

class Solution {
public:

    set<string> st;

    void subset(string& str, int i, string out){
        // base case
        if(i >= str.length()){
            st.insert(out);
            return;
        }
        // 1 case hum solve karenge
        // exclude
        subset(str, i+1, out);
        // include
        out.push_back(str[i]);
        subset(str, i+1, out);
    }  

    void permutation(string& str, int i){
        // base case
        if(i >= str.length()-1){
            subset(str, 0, "");
            return;
        }
        // 1 case hum karenge
        for(int j = i; j<str.length(); j++){
            swap(str[j], str[i]);
            permutation(str, i+1);
            swap(str[j], str[i]);
        }
    }

    int numTilePossibilities(string tiles) {
        permutation(tiles, 0);
        return st.size()-1;
    }
};