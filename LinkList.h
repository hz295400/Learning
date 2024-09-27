#pragma once


struct DListNode
{
	int key, val;
	DListNode* pre = nullptr;
	DListNode* next = nullptr;
	DListNode() : key(0), val(0), pre(nullptr), next(nullptr) {};
	DListNode(int key = 0, int val = 0, DListNode* pre = nullptr, DListNode* next = nullptr)
		: key(0), val(val), pre(pre), next(next) {};
};

class ListNode
{
public:
	ListNode() {};
	ListNode(int nVal) :nVal(nVal) {};
	~ListNode() {};

	ListNode* pre();
	ListNode* next();
private:
	ListNode* preNode{ nullptr };
	ListNode* nextNode{ nullptr };
	int nVal{ 0 };
};