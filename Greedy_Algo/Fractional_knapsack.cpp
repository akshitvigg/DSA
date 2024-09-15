class Solution {
public:
    // Custom comparator to sort by number of units per box in descending order
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort the boxes by the number of units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int totalUnits = 0;

        // Iterate through the sorted boxes
        for (int i = 0; i < boxTypes.size(); i++) {
            int boxCount = boxTypes[i][0];   // Number of boxes of this type
            int unitsPerBox = boxTypes[i][1]; // Units per box of this type
            
            // Take as many boxes as the truck can carry
            if (truckSize >= boxCount) {
                totalUnits += boxCount * unitsPerBox;
                truckSize -= boxCount;
            } else {
                // Take only the boxes that fit if there's not enough space
                totalUnits += truckSize * unitsPerBox;
                break;  // Truck is full, no need to continue
            }
        }

        return totalUnits;
    }
};
