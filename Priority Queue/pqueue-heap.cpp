/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

HeapPriorityQueue::HeapPriorityQueue() {
	// Actual size of the queue
	queueSize = 0;
	// Length of the array
	capacity = 1;
	// Dummy value
	data = new string[capacity];
	data[0] = "";
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] data;
}

int HeapPriorityQueue::size() {
	return queueSize;
}

bool HeapPriorityQueue::isEmpty() {
	return queueSize == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (capacity - 1 == queueSize) {
		// Create a bigger array
		int newSize = capacity * 2;
		string* tmpData = new string[newSize];

		// Copy elements 
		for (int i = 0; i < capacity; i++) {
			tmpData[i] = data[i];
		}

		// Delete and update values
		delete[] data;
		data = tmpData;
		capacity = newSize;
	}

	// Add new value at the end
	queueSize++;
	data[queueSize] = value;
	
	// Bubble up
	int bubbleIndex = queueSize;
	while (bubbleIndex > 1 && data[bubbleIndex] < data[bubbleIndex / 2]) {
		swap(data[bubbleIndex], data[bubbleIndex / 2]);
		bubbleIndex /= 2;
	}
}

string HeapPriorityQueue::peek() {
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	return data[1];
}

string HeapPriorityQueue::dequeueMin() {
	if (queueSize == 0) {
		error("Priority Queue is empty");
	}

	// Swap top with bottom
	string res = data[1];
	data[1] = data[queueSize];
	data[queueSize] = "";

	// Change queueSize and capacity
	if (queueSize < capacity / 4 && capacity > 2) {
		// Create a smaller array
		int newSize = capacity / 2;
		string* tmpData = new string[newSize];

		// Copy elements 
		for (int i = 0; i < newSize; i++) {
			tmpData[i] = data[i];
		}

		// Delete and update values
		delete[] data;
		data = tmpData;
		capacity = newSize;
	}

	queueSize--;

	// Bubble down
	int bubbleIndex = 1;

	while (true) {
		int left = bubbleIndex * 2;
		int right = bubbleIndex * 2 + 1;
		int currMin = bubbleIndex;
		
		// Find the smallest child
		if (left <= queueSize && data[left] < data[currMin]) {
			currMin = left;
		}
		if (right <= queueSize && data[right] < data[currMin]) {
			currMin = right;
		}

		// If there are no smaller children
		if (currMin == bubbleIndex) break;

		swap(data[bubbleIndex], data[currMin]);
		bubbleIndex = currMin;
	}
	
	return res;
}

