/*
Question# + Difficulty + Topic + Company + Similar_Question
[136] [Single Number] [Easy] [Hash Table Bit Manipulation] 
[Palantir Airbnb] 
[137 260 268 287 389].cpp
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};

/* XOR is Associative and Communicative
Associative A xor ( B xor C ) = ( A xor B ) xor C
Communicative A xor B = B xor A


And XOR same number will result in 0
*/
