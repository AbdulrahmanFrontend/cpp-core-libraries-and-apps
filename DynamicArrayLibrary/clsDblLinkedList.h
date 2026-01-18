#pragma once
#include <iostream>
using namespace std;
template <typename T>
class clsDblLinkedList {
protected:
	int _Size = 0;
public:
	class Node {
	public:
		T value;
		Node* next;
		Node* prev;
	};
	Node* head = NULL;
	void InsertAtBeginning(T Value) {
		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->next = head;
		NewNode->prev = NULL;
		if (head != NULL)
			head->prev = NewNode;
		head = NewNode;
		_Size++;
	};
	void InsertAfter(Node* Current, T Value) {
		if (Current == NULL)
			return;
		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->next = Current->next;
		if (Current->next != NULL)
			Current->next->prev = NewNode;
		Current->next = NewNode;
		NewNode->prev = Current;
		_Size++;
	};
	void InsertAtEnd(T Value) {
		Node* NewNode = new Node();
		NewNode->value = Value;
		NewNode->next = NULL;
		if (head == NULL) {
			NewNode->prev = NULL;
			head = NewNode;
		}
		else {
			Node* LastNode = head;
			while (LastNode->next != NULL)
				LastNode = LastNode->next;
			LastNode->next = NewNode;
			NewNode->prev = LastNode;
		};
		_Size++;
	};
	void DeleteNode(Node* NodeToDelete) {
		if (head == NULL || NodeToDelete == NULL)
			return;
		if (head == NodeToDelete)
			head = NodeToDelete->next;
		if (NodeToDelete->next != NULL)
			NodeToDelete->next->prev = NodeToDelete->prev;
		if (NodeToDelete->prev != NULL)
			NodeToDelete->prev->next = NodeToDelete->next;
		delete NodeToDelete;
		_Size--;
	};
	void DeleteFirstNode() {
		if (head == NULL)
			return;
		Node* Current = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delete Current;
		_Size--;
	};
	void DeleteLastNode() {
		if (head == NULL)
			return;
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		};
		Node* current = head;
		while (current->next->next != NULL)
			current = current->next;
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	};
	void Reverse() {
		if (head == NULL)
			return;
		Node* Current = head;
		Node* temp = NULL;
		while (Current != NULL) {
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;
			Current = Current->prev;
		};
		if (temp != NULL)
			head = temp->prev;
	};
	bool UpdateItem(int Index, T NewValue) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL)
			return false;
		ItemNode->value = NewValue;
		return true;
	};
	bool InsertAfter(int Index, T NewValue) {
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL)
			return false;
		InsertAfter(ItemNode, NewValue);
		return true;
	};
	Node* Find(T Value) {
		Node* Current = head;
		while (Current != NULL) {
			if (Current->value == Value)
				return Current;
			Current = Current->next;
		};
		delete Current;
		return NULL;
	};
	Node* GetNode(int Index) {
		int Counter = 0;
		if (Index > _Size - 1 || Index < 0)
			return NULL;
		Node* Current = head;
		while (Current != NULL && Current->next != NULL) {
			if (Counter == Index)
				break;
			Current = Current->next;
			Counter++;
		};
		return Current;
	};
	int GetItem(int Index) {
		Node* ItemNode = GetNode(Index);
		return ItemNode == NULL ? NULL : ItemNode->value;
	};
	int Size() {
		return _Size;
	};
	bool IsEmpty() {
		return !Size();
	};
	void Clear() {
		while (Size() > 0)
			DeleteFirstNode();
	};
	void PrintList() {
		Node* Current = head;
		while (Current != NULL) {
			cout << " " << Current->value;
			Current = Current->next;
		};
		delete Current;
		cout << ".\n";
	};
};