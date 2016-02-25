#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    //Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

public:
    static void Solve();

    //array
private:
    //Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    //You may assume that each input would have exactly one solution.
    static vector<int> twoSum(vector<int>& nums, int target);
    static void SolveTwoSum();
    //There are two sorted arrays nums1 and nums2 of size m and n respectively.Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    static void SolveFindMedianSortedArrays();
    //list
private:
    //You are given two linked lists representing two non - negative numbers.
    //The digits are stored in reverse order and each of their nodes contain a single digit.
    //Add the two numbers and return it as a linked list.
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    static void SolveAddTwoNumbers();
};