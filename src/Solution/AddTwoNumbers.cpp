#include "stdafx.h"
#include "Solution.h"

void Solution::SolveAddTwoNumbers() {
	ListNode *l1 = nullptr;
	ListNode *l1Position = nullptr;
	ListNode *newNode = new ListNode(2);
	l1 = newNode;
	l1Position = newNode;

	newNode = new ListNode(4);
	l1Position->next = newNode;
	l1Position = newNode;

	newNode = new ListNode(3);
	l1Position->next = newNode;
	l1Position = newNode;

	ListNode *l2 = nullptr;
	ListNode *l2Position = nullptr;
	newNode = new ListNode(5);
	l2 = newNode;
	l2Position = newNode;

	newNode = new ListNode(6);
	l2Position->next = newNode;
	l2Position = newNode;

	newNode = new ListNode(4);
	l2Position->next = newNode;
	l2Position = newNode;

	ListNode *result = addTwoNumbers(l1, l2);
	while (!result) {
		cout << result->val << ",";
	}
}

Solution::ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	int sum = 0;
	int carry = 0;
	ListNode *result = nullptr;
	ListNode *resultPosition = nullptr;
	while (l1 != nullptr && l2 != nullptr) {
		sum = l1->val + l2->val + carry;
		carry = sum / 10;

		l1 = l1->next;
		l2 = l2->next;

		ListNode *newNode = new ListNode(sum % 10);
		if (nullptr == result) {
			result = newNode;
		}
		if (nullptr == resultPosition) {
			resultPosition = newNode;
		}
		else {
			resultPosition->next = newNode;
			resultPosition = resultPosition->next;
		}
	}

	while (l1 != nullptr) {
		sum = l1->val + carry;
		carry = sum / 10;

		l1 = l1->next;

		ListNode *newNode = new ListNode(sum % 10);
		if (nullptr == result) {
			result = newNode;
		}
		if (nullptr == resultPosition) {
			resultPosition = newNode;
		}
		else {
			resultPosition->next = newNode;
			resultPosition = resultPosition->next;
		}
	}

	while (l2 != nullptr) {
		sum = l2->val + carry;
		carry = sum / 10;

		l2 = l2->next;

		ListNode *newNode = new ListNode(sum % 10);
		if (nullptr == result) {
			result = newNode;
		}
		if (nullptr == resultPosition) {
			resultPosition = newNode;
		}
		else {
			resultPosition->next = newNode;
			resultPosition = resultPosition->next;
		}
	}

	if (0 != carry) {
		ListNode *newNode = new ListNode(carry % 10);
		if (nullptr == result) {
			result = newNode;
		}
		if (nullptr == resultPosition) {
			resultPosition = newNode;
		}
		else {
			resultPosition->next = newNode;
			resultPosition = resultPosition->next;
		}
	}

	return result;
}