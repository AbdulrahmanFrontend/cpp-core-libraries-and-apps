#pragma once
#include "clsDblLinkedList.h"
template <typename T>
class clsMyQueue {
	clsDblLinkedList<T>_MyList;
public:
	void push(T Item) {
		_MyList.InsertAtEnd(Item);
	};
	void pop() {
		_MyList.DeleteFirstNode();
	};
	int Size() {
		return _MyList.Size();
	};
	T front() {
		return _MyList.GetItem(0);
	};
	T back() {
		return _MyList.GetItem(Size() - 1);
	};
	bool IsEmpty() {
		return _MyList.IsEmpty();
	};
	void Print() {
		_MyList.PrintList();
	};
	T GetItem(int Index) {
		return _MyList.GetItem(Index);
	};
	void Reverse() {
		_MyList.Reverse();
	};
	void UpdateItem(int Index, T NewValue) {
		_MyList.UpdateItem(Index, NewValue);
	};
	void InsertAfter(int Index, T NewValue) {
		_MyList.InsertAfter(Index, NewValue);
	};
	void InsertAtFront(T NewValue) {
		_MyList.InsertAtBeginning(NewValue);
	};
	void InsertAtBack(T NewValue) {
		_MyList.InsertAtEnd(NewValue);
	};
	void Clear() {
		_MyList.Clear();
	};
};