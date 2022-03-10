#include <string>
#include "SList.h"

using namespace std;

template <typename T>
class LinkedStack {
private:
	SList<T> S;
	int n;

public:
	LinkedStack();
	T size() const;
	bool empty() const;
	const T top();
	void push(const T);
	void pop();
	void print();
};

template <typename T>
LinkedStack<T>::LinkedStack() : S(), n() {}

template <typename T>
T LinkedStack<T>::size() const {
	return n;
}

template <typename T>
bool LinkedStack<T>::empty() const {
	return n == 0;
}

template <typename T>
const T LinkedStack<T>::top() {
	return S.front();
}

template <typename T>
void LinkedStack<T>::push(T e) {
	++n;
	S.addFront(e);
}

template <typename T>
void LinkedStack<T>::pop() {
	--n;
	S.removeFront();
}

template <typename T>
void LinkedStack<T>::print() {
	S.print();
}

