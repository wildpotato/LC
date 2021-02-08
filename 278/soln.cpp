#include "../include.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		int low = 1;
		int high = n;
		while (low < high) {
			int mid = low + (high - low) / 2;
			// mid MAY or MAY NOT be the first bad version, so set high = mid
			if (isBadVersion(mid)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
    }
};