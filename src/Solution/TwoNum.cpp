#include "stdafx.h"
#include "Solution.h"
#include <unordered_map>

void Solution::SolveTwoSum() {
	//vector<int> sum = { 0, 4, 3, 0 };
	vector<int> sum = { 3, 2, 4 };
	vector<int> nums = twoSum(sum, 6);
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i];
	}
	cout << endl;
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
	vector<int> result;
	unordered_map<int, int> checkedNums;
	for (int i = 0; i < nums.size(); ++i) {
		if (checkedNums.find(target - nums[i]) != checkedNums.end()) {
			result.push_back(checkedNums[target - nums[i]]);
			result.push_back(i);
			break;
		}
		checkedNums[nums[i]] = i;
	}
	return result;
}