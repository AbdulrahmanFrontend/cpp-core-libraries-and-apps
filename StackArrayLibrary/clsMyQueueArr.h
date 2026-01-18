#pragma once
#include "clsDynamicArray.h"
template <typename T>
class clsMyQueueArr {
	clsDynamicArray<T>_MyArray;
public:
	void push(T Item) {
		_MyArray.InsertAtEnd(Item);
	};
	void pop() {
		_MyArray.DeleteFirstItem();
	};
	int Size() {
		return _MyArray.Size();
	};
	T front() {
		return _MyArray.GetItem(0);
	};
	T back() {
		return _MyArray.GetItem(Size() - 1);
	};
	bool IsEmpty() {
		return _MyArray.IsEmpty();
	};
	void Print() {
		_MyArray.PrintList();
	};
	T GetItem(int Index) {
		return _MyArray.GetItem(Index);
	};
	void Reverse() {
		_MyArray.Reverse();
	};
	void UpdateItem(int Index, T NewValue) {
		_MyArray.SetItem(Index, NewValue);
	};
	void InsertAfter(int Index, T NewValue) {
		_MyArray.InsertAfter(Index, NewValue);
	};
	void InsertAtFront(T NewValue) {
		_MyArray.InsertAtBeginning(NewValue);
	};
	void InsertAtBack(T NewValue) {
		_MyArray.InsertAtEnd(NewValue);
	};
	void Clear() {
		_MyArray.Clear();
	};
};