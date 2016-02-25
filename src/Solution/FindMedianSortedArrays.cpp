#include "stdafx.h"
#include "Solution.h"
#include <unordered_map>

void Solution::SolveFindMedianSortedArrays() {
    vector<int> nums1 = { 1, 3, 5, 7, 9 };
    vector<int> nums2 = { 2, 4, 6, 8, 10 };
    cout << findMedianSortedArrays(nums1, nums2);
}

float getPosition(vector<int>& nums, float x) {
    int l = 0;
    int r = nums.size() - 1;
    int mid = 0;
    while (l < r && r - l > 1) {
        mid = nums[(r + l) / 2];
        if (x < mid) {
            r = (r + l) / 2;
        }
        else if (x > mid) {
            l = (r + l) / 2;
        }
        else {
            break;
        }
    }
    return (l + r) / 2.0f;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = 0;
    int r1 = nums1.size() - 1;
    float mid1 = 0;
    int l2 = 0;
    int r2 = nums2.size() - 1;
    float mid2 = 0;
    
    while (l1 < r1 || l2 < r2) {
        mid1 = (l1 + r1) / 2;
        float position = getPosition(nums2, nums1[(int)mid1]);
        float rminusl = nums1.size() - 1 - mid1 + nums2.size() - 1 - floor(position) - (mid1 + ceil(position));
        if (rminusl > 0) {
            l1 = ceil(mid1);
            l2 = ceil(position);
        }
        else if (rminusl < 0) {
            r1 = floor(mid1);
            r2 = floor(position);
        }
        else {
            break;
        }
    }

    if (l1 == r1) {
        return nums1[l1];
    }

    if (l2 == r2) {
        return nums2[l2];
    }
    
    return (max(nums1[l1], nums2[l2]) + min(nums1[r1], nums2[r2])) / 2.0f;
}