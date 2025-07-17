/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head = nullptr;
	queueSize = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	while (head != nullptr) {
		Cell* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int LinkedListPriorityQueue::size() {
	return queueSize;
}

bool LinkedListPriorityQueue::isEmpty() {
	return queueSize == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	// O(n)
	Cell* newCell = new Cell;
	newCell->value = value;
	newCell->next = nullptr;

	// If no cells have been added yet
	if (head == nullptr || value < head->value) {
		newCell->next = head;
		head = newCell;
	}
	else {
		// Search for a cell with a bigger value 
		Cell* prev = head;
		while (prev->next != nullptr && prev->next->value < value) {
			prev = prev->next;
		}
		// Inserting new cell 
		newCell->next = prev->next;
		prev->next = newCell;
	}
	
	queueSize++;
}

string LinkedListPriorityQueue::peek() {
	// O(1)
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	return head->value;
}

string LinkedListPriorityQueue::dequeueMin() {
	// O(1)
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	// Removing the first cell
	Cell* first = head;
	head = head->next;
	queueSize--;

	string res = first->value;
	delete first;

	return res;
}

