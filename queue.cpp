#include <iostream>
#include <queue>
#include "queue.h"

using namespace std;

struct Queue* make_queue() {
    Queue* Q = new Queue();
    Q->front = nullptr;
    Q->back = nullptr;
    return Q;
}
int front(struct Queue* Q){
	if (Q->front == nullptr){
		return 0;
	}
	return Q->front->value;
}

char empty(struct Queue* Q){
	return Q->front == nullptr;
}

void enqueue(struct Queue* Q, int x){
    Node* newNode = new Node();
    newNode->value = x;
    newNode->next == nullptr;
    if (Q->front == nullptr){
    	Q->front = newNode;
    	Q->back = newNode;
    } else{
    	Q->back->next = newNode;
    	Q->back = newNode;
    }
}

int dequeue(struct Queue* Q) {
	if (Q->front == nullptr){
		return 0;
	}
	Q->front = Q->front->next; //get value from front
	if(Q->front == nullptr){
		Q->back = nullptr;
	}
return 0;
}

int main(){
	char empty(Queue* Q);
}
