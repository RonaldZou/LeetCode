#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	static void Solve() {
		//vector<int> sum = { 0, 4, 3, 0 };
		vector<int> sum = { 3, 2, 4 };
		vector<int> nums = twoSum(sum, 6);
		for (int i = 0; i < nums.size(); ++i) {
			cout << nums[i];
		}
		cout << endl;
	}
private:
	//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
	//You may assume that each input would have exactly one solution.
	static vector<int> twoSum(vector<int>& nums, int target);
};