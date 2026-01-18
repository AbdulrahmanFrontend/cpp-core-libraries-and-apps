#pragma once
#include <iostream>
using namespace std;
template <typename T>
class clsDynamicArray {
protected:
	int _Size = 0;
	T* _TempArray;
public:
	T* OriginalArray;
	clsDynamicArray(int Size = 0) {
		if (Size < 0)
			Size = 0;
		_Size = Size;
		OriginalArray = new T[_Size];
	};
	~clsDynamicArray() {
		delete[] OriginalArray;
	};
	bool SetItem(int Index, T NewValue) {
		if (Index >= _Size || Index < 0)
			return false;
		OriginalArray[Index] = NewValue;
		return true;
	};
	int Size() {
		return _Size;
	};
	void Resize(int NewSize) {
		if (NewSize < 0)
			NewSize = 0;
		_TempArray = new T[NewSize];
		for (int i = 0; i < NewSize; i++)
			_TempArray[i] = OriginalArray[i];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		_Size = NewSize;
	};
	T GetItem(int Index) {
		return OriginalArray[Index];
	};
	void Reverse() {
		_TempArray = new T[_Size];
		int TempSize = _Size - 1;
		for (int i = 0; i < _Size; i++) {
			_TempArray[i] = OriginalArray[TempSize];
			TempSize--;
		};
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	};
	bool DeleteItemAt(int Index) {
		if (Index >= _Size || Index < 0)
			return false;
		_Size--;
		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++)
			_TempArray[i] = OriginalArray[i];
		for (int i = Index + 1; i < _Size + 1; i++)
			_TempArray[i - 1] = OriginalArray[i];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	};
	bool DeleteItem(T Value) {
		return DeleteItemAt(Find(Value));
	};
	void DeleteFirstItem() {
		DeleteItemAt(0);
	};
	void DeleteLastItem() {
		DeleteItemAt(_Size - 1);
	};
	int Find(T Value) {
		for (int i = 0; i < _Size; i++)
			if (OriginalArray[i] == Value)
				return i;
		return -1;
	};
	bool InsertAt(int Index, T NewValue) {
		if (Index > _Size || Index < 0)
			return false;
		_Size++;
		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++)
			_TempArray[i] = OriginalArray[i];
		_TempArray[Index] = NewValue;
		for (int i = Index + 1; i < _Size; i++)
			_TempArray[i] = OriginalArray[i - 1];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	};
	bool InsertAtBeginning(T NewValue) {
		return InsertAt(0, NewValue);
	};
	bool InsertBefore(int Index, T NewValue) {
		if (Index < 1)
			return InsertAt(0, NewValue);
		return InsertAt(Index - 1, NewValue);
	};
	bool InsertAfter(int Index, T NewValue) {
		if (Index >= _Size)
			return InsertAt(_Size - 1, NewValue);
		return InsertAt(Index + 1, NewValue);
	};
	bool InsertAtEnd(T NewValue) {
		return InsertAt(_Size, NewValue);
	};
	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	};
	bool IsEmpty() {
		return !Size();
	};
	void PrintList() {
		for (int i = 0; i < _Size; i++)
			cout << " " << OriginalArray[i];
		cout << ".\n";
	};
};