class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){
                v.push_back(s[i]);
            }
        }
        int j=v.size()-1;
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122){
                s[i]=v[j];
                j--;
            }
        }
        return s;
    }
};
