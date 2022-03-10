#include <iostream>
#include "SNode.h"
using namespace std;
template <typename T>
class SList {
private:
	SNode<T>* head;
	template <typename T> friend class LinkedStack;

public:
	SList();
	~SList();
	bool empty() const;
	T front() const;
	void addFront(T);
	void removeFront();
	void print();
};

template <typename T>
SList<T>::SList() : head(NULL) {}

template <typename T>
SList<T>::~SList() {
	while (!empty())
		removeFront();
}

template <typename T>
bool SList<T>::empty() const {
	return head == NULL;
}

template <typename T>
T SList<T>::front() const {
	return head->elem;
}

template <typename T>
void SList<T>::addFront(T e) {
	SNode<T>* np = new SNode<T>();
	np->elem = e;
	np->next = head;
	head = np;
}

template <typename T>
void SList<T>::removeFront() {
	SNode<T>* temp = head;
	head = temp->next;
	delete temp;
}

template <typename T>
void SList<T>::print() {
	for (SNode<T>* temp = head; temp != NULL; temp = temp->next) {
		if (temp != head) {
			cout << " -> ";
		}
		cout << temp->elem;
	}
	cout << "  [Stack: LIFO- Last In First Out]" << endl;
}
