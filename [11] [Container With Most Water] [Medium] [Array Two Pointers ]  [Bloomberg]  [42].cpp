/*
Question# + Difficulty + Topic + Company + Similar_Question
[11] [Container With Most Water] [Medium] [Array Two Pointers ] 
[Bloomberg] 
[42].cpp
*/

class Solution {
public:
   int maxArea(vector<int>& height) {
    int water = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
};
