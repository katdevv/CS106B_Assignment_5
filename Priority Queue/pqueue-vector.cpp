/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	data = new Vector<string>;
}

VectorPriorityQueue::~VectorPriorityQueue() {
	delete data;
}

int VectorPriorityQueue::size() {
	return data->size();
}

bool VectorPriorityQueue::isEmpty() {
	return data->isEmpty();
}

void VectorPriorityQueue::enqueue(string value) {
	// Best case O(1)
	// Worst case O(n)
	// Average O(1)
	data->add(value);
}

string VectorPriorityQueue::peek() {
	// O(n)
	if (data->isEmpty()) {
		error("Priority Queue is empty");
	}

	// Find the smallest string
	string res = (*data)[0];
	for (int i = 1; i < data->size(); i++) {
		if ((*data)[i] < res) {
			res = (*data)[i];
		}
	}
	
	return res;
}

string VectorPriorityQueue::dequeueMin() {
	// O(n)
	if (data->isEmpty()) {
		error("Priority Queue is empty");
	}

	// Find the smallest string
	int index = 0;
	string res = (*data)[index];
	
	for (int i = 1; i < data->size(); i++) {
		if ((*data)[i] < res) {
			res = (*data)[i];
			index = i;
		}
	}

	// Remove it
	data->remove(index);
	
	return res;
}

