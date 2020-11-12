int dequeue(struct Queue* Q) {
	if (Q->front == nullptr){
		return 0;
	}
	int frontVal=Q->front;

	Q->front = Q->front->next; //get value from front

	if(Q->front == nullptr){
		Q->back = nullptr;
	}
	return frontVal;
}