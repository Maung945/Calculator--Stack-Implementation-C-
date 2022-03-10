template <typename T>
class SNode {
private:
	T elem;
	SNode<T>* next;
	explicit SNode();
	template <typename T> friend class SList;
};

template <typename T>
SNode<T>::SNode() : elem(), next(NULL) {}

