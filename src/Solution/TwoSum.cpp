#include "stdafx.h"
#include "Solution.h"
#include <map>

vector<int> Solution::twoSum(vector<int>& nums, int target) {
	multimap<int, int> sequenceMap;
	for (int i = 0; i < nums.size(); ++i) {
		sequenceMap.insert(make_pair(nums[i], i));
	}
	sort(nums.begin(), nums.end());
	int i = 0;
	int j = nums.size() - 1;
	bool found = false;
	do {
		int t = nums[i] + nums[j];
		if (t == target) {
			found = true;
			break;
		}
		else {
			if (t > target) {
				--j;
			}
			else {
				++i;
			}
		}
	} while (j >= 0 && j < nums.size() && i >= 0 && i < nums.size());
	if (found) {
		multimap<int, int>::iterator itOfI = sequenceMap.end();
		multimap<int, int>::iterator itOfJ = sequenceMap.end();
		if (nums[i] == nums[j]) {
			int k = nums[i];
			itOfI = sequenceMap.lower_bound(k);
			if (itOfI != sequenceMap.end()) {
				itOfJ = itOfI;
				++itOfJ;
			}
		}
		else {
			itOfI = sequenceMap.find(nums[i]);
			itOfJ = sequenceMap.find(nums[j]);
		}
		if (itOfI != sequenceMap.end() && itOfJ != sequenceMap.end()) {
			nums = { itOfI->second, itOfJ->second };
		}
	}
	else {
		nums.clear();
	}
	return nums;
}