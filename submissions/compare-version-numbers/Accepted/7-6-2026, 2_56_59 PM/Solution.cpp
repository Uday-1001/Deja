// https://leetcode.com/problems/compare-version-numbers

class Solution {
public:
    int VersionComparison(string version1 , string version2)
    {
        int index_of_dot1 = version1.find('.');
        int index_of_dot2 = version2.find('.');

        string before_dot1, before_dot2;
        string after_dot1, after_dot2;

        if(index_of_dot1 == string::npos)
        {
            before_dot1 = version1;
            after_dot1 = "";
        }
        else
        {
            before_dot1 = version1.substr(0, index_of_dot1);
            after_dot1 = version1.substr(index_of_dot1 + 1);
        }

        if(index_of_dot2 == string::npos)
        {
            before_dot2 = version2;
            after_dot2 = "";
        }
        else
        {
            before_dot2 = version2.substr(0, index_of_dot2);
            after_dot2 = version2.substr(index_of_dot2 + 1);
        }

        int version_pref1 = stoi(before_dot1);
        int version_pref2 = stoi(before_dot2);

        if(version_pref1 > version_pref2) return 1;
        else if(version_pref1 < version_pref2) return -1;
        else
        {
            if(after_dot1.empty()) after_dot1 = "0";
            if(after_dot2.empty()) after_dot2 = "0";

            if(after_dot1 == "0" && after_dot2 == "0") return 0;

            return VersionComparison(after_dot1, after_dot2);
        }
    }

    int compareVersion(string version1, string version2) {
        return VersionComparison(version1, version2);
    }
};