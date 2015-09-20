#include <string>
#include <iostream>
#include "LinkedList.h"

template<class T>
LinkedList<T>::Node::Node(){
	next = NULL;
	data = NULL;
}

template<class T>
LinkedList<T>::Node::Node(T item){
	next = NULL;
	data = item;
}

template<class T>
LinkedList<T>::Node::Node(const Node &source){
	next = (*source).next;
	data = (*source).data;
}

template<class T>
LinkedList<T>::LinkedList(){
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template<class T>
LinkedList<T>::~LinkedList(){
}

template<class T>
void LinkedList<T>::append(T item){
	size++;
	Node* newNode = new Node(item);
	if(head == NULL){ // empty list
		this->head = newNode;
		this->tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

template<class T>
void LinkedList<T>::prepend(T item){
	size++;
	Node* newNode = new Node(item);
	if(head == NULL){ // empty list
		this->head = newNode;
		this->tail = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
}

// you now own the returned object
template<class T>
T LinkedList<T>::get(int index){
	if(index > size || index < 0) return NULL; // out of bounds
	Node* currentNode = head;
	for(; index > 0; index--){
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

// you now own the returned object
template<class T>
T LinkedList<T>::remove(int index){
	if(index > size || index < 0) return NULL; // out of bounds
	
	size--;
	if(index == 0){ // head must change
		if(size == 1){ // only element in the list
			T residual = head->data;
			delete head;
			head = NULL;
			tail = NULL;
			return residual;
		}
		T residual = head->data;
		Node *nextHead = head->next;
		delete head;
		head = nextHead;
		return residual;
	}

	
	Node* removeTarget = head;
	Node* prevTarget = head;
	for(; index > 0; index--){
		prevTarget = removeTarget;
		removeTarget = removeTarget->next;
	}
	T residual = removeTarget->data;
	prevTarget->next = removeTarget->next;
	delete removeTarget;
	if(index == size){ // tail must change
		tail = prevTarget;
		return residual;
	}
}

template<class T>
int LinkedList<T>::getSize(){
	return this->size;
}

/* test client
void main(){
	LinkedList<std::string> nameList = LinkedList<std::string>();
	nameList.prepend("Jack");
	nameList.prepend("Emma");
	nameList.append("Konnor");
	nameList.append("Eugene");

	for(int i = 0; i < nameList.getSize(); i++){
		const std::string currentString = nameList.get(i);
		std::cout << currentString;
	}
	char c;
	std::cin >> c;
}
*/