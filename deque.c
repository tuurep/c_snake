#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Code modified from:
// https://www.thecrazyprogrammer.com/2014/02/c-program-for-various-operations-on-a-dequeue-represented-using-a-circular-array.html
// By Neeraj Mishra
 
void initialize(deque *p) {
	p -> tail = -1;
	p -> head = -1;
}

int empty(deque *p) {
	if(p -> tail == -1)
		return 1;
	
	return 0;
}
 
int full(deque *p) {
	if((p -> tail +1) % MAX == p -> head)
		return 1;
	
	return 0;
}
 
void enqueue_tail(deque *p, int x) {
	if (empty(p)) {
		p -> tail = 0;
		p -> head = 0;
		p -> data[0] = x;
	} 
  else {
		p -> tail = (p -> tail + 1) % MAX;
		p -> data[p -> tail] = x;
	}
}
 
void enqueue_head(deque *p, int x) {
	if (empty(p)) {
    p -> tail = 0;
		p -> head = 0;
		p -> data[0] = x;
	}
	else {
		p -> head = (p -> head - 1 + MAX) % MAX;
		p -> data[p -> head] = x;
	}
}
 
int dequeue_head(deque *p) {
	int x;
	
	x = p -> data [p -> head];
	
	if (p -> tail == p -> head)	//delete the last element
		initialize(p);
	else
		p -> head = (p -> head + 1) % MAX;
	
	return x;
}
 
int dequeue_tail(deque *p) {
	int x;
	
	x = p -> data[p -> tail];
	
	if (p -> tail == p -> head)
		initialize(p);
	else
		p -> tail = (p -> tail - 1 + MAX) % MAX;
		
	return x;
}
 
void print(deque *p) {
	if (empty(p))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}
	
	int i;
	i = p -> head;
	
	while (i != p -> tail) {
		printf("\n%d", p -> data[i]);
		i = (i + 1) % MAX;
	}
	
	printf("\n%d\n", p -> data[p -> tail]);
}
