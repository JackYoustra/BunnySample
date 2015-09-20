#pragma once
template <class T>
class LinkedList{
private:
	class Node{
	public:
		Node* next;
		T data;
		Node();
		Node(T data);
		Node(const Node &source); // copy constructor
	};

	Node* head;
	Node* tail;
	int size;
public:
	void append(T data);
	void prepend(T data);
	T get(int index);
	T remove(int index); // returns the data removed, zero-based index
	int getSize();

	LinkedList();
	~LinkedList();
};