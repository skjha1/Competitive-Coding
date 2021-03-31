class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> temp(26,0);
        for(int i=0; s[i]!='\0'; i++){
            temp[s[i] - 97]++;
        }
        for(int i=0; s[i]!='\0'; i++){
            if(temp[s[i]-97] == 1) return i;
        }
        return -1;
    }
};
