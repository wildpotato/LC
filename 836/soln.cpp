#include "../include.h"

/*
 *  If we draw two rectangles on a piece of paper and they have no overlap,
 *  we observe that one must be to the up/down/left/right of the other.
 *  Also, we need to check the cases when either of the rectangles is actually
 *  just a single line (degenerate) and not a rectangle.
 *  With the two key points in mind, we can proceed to implementing the logic.
 *
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool Rec1IsLine = (rec1[0] == rec1[2]) or (rec1[1] == rec1[3]);
        bool Rec2IsLine = (rec2[0] == rec2[2]) or (rec2[1] == rec2[3]);
        if (Rec1IsLine or Rec2IsLine) {
            return false;
        }
        bool Rec1AboveRec2 = rec1[1] >= rec2[3];
        bool Rec1BelowRec2 = rec1[3] <= rec2[1];
        bool Rec1ToRightOfRec2 = rec1[0] >= rec2[2];
        bool Rec1ToLeftOfRec2 = rec1[2] <= rec2[0];
        if (Rec1AboveRec2 or Rec1BelowRec2 or Rec1ToRightOfRec2 or Rec1ToLeftOfRec2) {
            return false;
        }
        return true;
   }
};

void test1() {
    vector<int> rec1 {0,0,2,2};
    vector<int> rec2 {1,1,3,3};
    Solution soln;
    assert(soln.isRectangleOverlap(rec1, rec2));
}

void test2() {
    vector<int> rec1 {0,0,1,1};
    vector<int> rec2 {1,0,2,1};
    Solution soln;
    assert(!soln.isRectangleOverlap(rec1, rec2));
}

void test3() {
    vector<int> rec1 {0,0,1,1};
    vector<int> rec2 {2,2,3,3};
    Solution soln;
    assert(!soln.isRectangleOverlap(rec1, rec2));
}

void test4() {
    vector<int> rec1 {7,8,13,15};
    vector<int> rec2 {10,8,12,20};
    Solution soln;
    assert(soln.isRectangleOverlap(rec1, rec2));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    cout << "Successful\n";
    return 0;
}
