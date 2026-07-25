// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int start = 0;
        int end = 0;
        //pehle he reverse kardiya hai string ko ki hume aage bs vapis reverse krne pe output mil jae 
        reverse(s.begin() , s.end());
        //tabtak chalna hai jabtak hum last of the string ko cross nhi kar jaate
        while(i < n)
        {
            //agar spaces mile to pointer ko aage badha do 
            while(i < n && s[i] == ' ')
            {
                i++;
            }
            if(i == n) break;
            //yha pr aae ho -> matlab spaces khatam ho chuki hongi reversed string ki
            while(i < n && s[i] != ' ')
            {
                s[end] = s[i];
                end++;
                i++;
            }
            //yha pr aae ho -> matlab string ka ek word ko flip kardiya hai
            //ab usko original state me le aao reverse karke 
            reverse(s.begin() + start , s.begin() + end);
            //ab space add krni hai uske baad
            s[end] = ' ';
            end++;

            //yha pr ab new start deni hogi kyuki new word aayega string ka so ->
            start = end;
            i++;
        }
    s.resize(end - 1);
    return s;
    }
};