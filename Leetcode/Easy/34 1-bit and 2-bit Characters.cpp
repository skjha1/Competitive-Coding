// problem : https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Solution : https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/1157774/explained-with-pen-paper-easy-clean-sol
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i=0;
        while (i<len-1){
            if (bits[i]==0) i++;
            else if (bits[i]==1) i+=2;
        }
        if (i==len-1)
            return true;
        else
            return false;
    }
};
