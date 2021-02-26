// Given a vector of box types, where each box type consists
// of the number of boxes of that type and number of units per box,
// and a maximum capacity in terms of boxes (not units), compute how many 
// units can fit at most.
// O(nlogn)time, constant space.

using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        size_t box_type_count = boxTypes.size();
        int max_units = 0;
        int box_count = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& first, const vector<int>& second) {
            return (first[1] > second[1]);
        });
        
        for (auto p : boxTypes) {
            for (auto q : p) {
                cout << q << " "; 
            }
            cout << endl;
        }
        
        for (int current_type = 0; current_type < box_type_count; current_type++) {
            int num_of_current_boxes = boxTypes[current_type][0];
            while (num_of_current_boxes-- > 0 && box_count < truckSize) {
                max_units += boxTypes[current_type][1];
                box_count++;
            }
        }
        return max_units;
    }
};