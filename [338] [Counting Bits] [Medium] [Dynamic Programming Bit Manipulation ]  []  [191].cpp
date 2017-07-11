
/*
Question# + Difficulty + Topic + Company + Similar_Question
[338] [Counting Bits] [Medium] [Dynamic Programming Bit Manipulation ] 
[] 
[191].cpp
*/

/* C++ Intuitive*/
public int[] countBits(int num) {
    int result[] = new int[num + 1];
    int offset = 1;
    for (int index = 1; index < num + 1; ++index){
        if (offset * 2 == index){
            offset *= 2;
        }
        result[index] = result[index - offset] + 1;
    }
    return result;
}


/* C++ Using tricks */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ans[i] = ans[i&(i-1)] + 1;
        return ans;
    }
};
