class Solution {
public:
    int si(string str)
    {
        int temp = 0;
        for (int i = 0; i < str.length(); i++) {
    
            // Since ASCII value of character from '0'
            // to '9' are contiguous. So if we subtract
            // '0' from ASCII value of a digit, we get 
            // the integer value of the digit.
            temp = temp * 10 + (str[i] - '0');
        }
        return temp;
    }
    int compareVersion(string version1, string version2) {
        int a = 0, b = 0;
        int i = 0, j = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        while(i < n1 || j < n2) {
            while(i < n1 && version1[i] != '.') {
                a = 10 * a + (int(version1[i]) - 48);
                i++;
            }
            while(j < n2 && version2[j] != '.') {
                b = 10 * b + (int(version2[j]) - 48);
                j++;
            }
            if(a < b) return -1;
            else if(a > b) return 1;
            a = 0, b = 0;
            i++;
            j++;
        }
        return a;
    }
};
