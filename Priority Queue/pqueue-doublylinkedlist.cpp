/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = nullptr;
	queueSize = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	while (head != nullptr) {
		Cell* tmp = head;
		head = head->next;
		delete tmp;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	return queueSize;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return queueSize == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	// O(1)
	Cell* newCell = new Cell;
	newCell->value = value;

	// Inset new cell at the begining
	newCell->next = head;
	newCell->prev = nullptr;
	

	if (head != nullptr) {
		head->prev = newCell;
	}

	head = newCell;
	queueSize++;
}

string DoublyLinkedListPriorityQueue::peek() {
	// O(n)
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	Cell* min = head;
	Cell* iterator = head;

	while(iterator != nullptr) {
		if (iterator->value < min->value) {
			min = iterator;
		}
		iterator = iterator->next;
	}
	
	return min->value;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	// O(n)
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	// Find minimal
	Cell* min = head;
	Cell* iterator = head;

	while (iterator != nullptr) {
		if (iterator->value < min->value) {
			min = iterator;
		}
		iterator = iterator->next;
	}

	if (min == head) {
		// Removing the first cell
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
	}
	else {
		// Removing middle or last cell
		min->prev->next = min->next;

		if (min->next != nullptr) {
			min->next->prev = min->prev;
		}
	}

	string res = min->value;

	delete min;

	queueSize--;
	
	return res;
}

