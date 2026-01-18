#include "clsDblLinkedList.h"
int main() {
    clsDblLinkedList<int>MyDblLinkedList;
    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);
    cout << "Linked List Content:";
    MyDblLinkedList.PrintList();
    MyDblLinkedList.InsertAfter(210, 500);
    cout << "\nAfter Insert:";
    MyDblLinkedList.PrintList();
    return 0;
};