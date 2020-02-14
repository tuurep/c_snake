#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

#define MAX 30 // Should be width * height of stage in the end?

typedef struct deque {
	int data[MAX];
	int tail, head;
} deque;
 
void initialize(deque *p);
int empty(deque *p);
int full(deque *p);
void enqueue_tail(deque *p, int x);
void enqueue_head(deque *p, int x);
int dequeue_head(deque *p);
int dequeue_tail(deque *p);
void print(deque *p);

#endif