#pragma once
#include "clsMyQueue.h"
template <class T>
class  clsMyStack : public clsMyQueue <T> {
public:
	void push(T Item) {
		clsMyQueue <T>::InsertAtFront(Item);
	};
	T Top() {
		return clsMyQueue <T>::front();
	};
	T Bottom() {
		return clsMyQueue <T>::back();
	};
};