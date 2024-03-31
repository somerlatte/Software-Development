#include "queue.h"

struct Node {
  int key;
  Node* next;
};

Queue::Queue() {
	// TODO
	this->front_ = 0;
	this->back_ = 0;
}

void Queue::push(int k) {
  // TODO
	Node *aux = new Node;
    aux->key = k;
    aux->next = 0;
	if (this->count() == 0){
		this->front_ = aux;
	}
	else{
		this->back_->next = aux;
	}
	this->back_ = aux;
}

void Queue::pop() {
  // TODO
	if (this->count() == 0){
		throw EmptyException();
	}
	Node *aux = this->front_->next;
	delete this->front_;
	this->front_ = aux;
}

int Queue::front() const {
	//return 0; // TODO    
	if (this->count() == 0){
		throw EmptyException();
	}
	return this->front_->key;
}

int Queue::back() const {
	//return 0; // TODO
	if (this->count() == 0){
		throw EmptyException();
	}
	return this->back_->key;
}

int Queue::count() const {
	//return 0; // TODO
	int y = 0;
	Node *x = this->front_;
	while (x > 0){
	  y++;
	  x = x->next;
  }
	return y;
}