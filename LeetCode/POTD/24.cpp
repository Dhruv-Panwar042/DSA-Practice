#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        // Return false if any non-overlapping condition is met
        if (rec2[2] <= rec1[0] || // rec2 is completely to the left
            rec2[0] >= rec1[2] || // rec2 is completely to the right
            rec2[3] <= rec1[1] || // rec2 is completely below
            rec2[1] >= rec1[3]) { // rec2 is completely above
            return false;
        }
        
        return true;
    }
};