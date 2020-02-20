#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Code modified from:
// https://www.thecrazyprogrammer.com/2014/02/c-program-for-various-operations-on-a-dequeue-represented-using-a-circular-array.html
// By Neeraj Mishra
 
void initialize(deque *p) {
	p->last = -1;
	p->first = -1;
}

int empty(deque *p) {
	if(p->last == -1)
		return 1;
	
	return 0;
}
 
int full(deque *p) {
	if((p->last + 1) % MAX_Q_SIZE == p->first)
		return 1;
	
	return 0;
}

int contains_coords(deque *p, int x, int y) {
  if (empty(p)) {
		return 0;
	}
	
	int i;
	i = p->first;
	
	while (i != p -> last) {
		if (p->data[i].x == x && p->data[i].y == y)
			return 1;
		i = (i + 1) % MAX_Q_SIZE;
	}
	if (p->data[p->last].x == x && p->data[p->last].y == y)
		return 1;

	return 0;
}

coords peek_head(deque *p) {
	coords c;
	
	c.x = p->data[p->first].x;
  c.y = p->data[p->first].y;

	return c;
}
 
void enqueue_tail(deque *p, coords c) {
	if (empty(p)) {
		p->last = 0;
		p->first = 0;
		p->data[0].x = c.x;
    p->data[0].y = c.y;
	} 
  else {
		p->last = (p->last + 1) % MAX_Q_SIZE;
		p->data[p->last].x = c.x;
    p->data[p->last].y = c.y;
	}
}
 
void enqueue_head(deque *p, coords c) {
	if (empty(p)) {
    p->last = 0;
		p->first = 0;
		p->data[0].x = c.x;
    p->data[0].y = c.y;
	}
	else {
		p->first = (p->first - 1 + MAX_Q_SIZE) % MAX_Q_SIZE;
		p->data[p->first].x = c.x;
    p->data[p->first].y = c.y;
	}
}
 
coords dequeue_head(deque *p) {
	coords c;
	
	c.x = p->data[p->first].x;
  c.y = p->data[p->first].y;
	
	if (p->last == p->first)	//delete the last element
		initialize(p);
	else
		p->first = (p->first + 1) % MAX_Q_SIZE;
	
	return c;
}
 
coords dequeue_tail(deque *p) {
	coords c;
	
	c.x = p->data[p->last].x;
  c.y = p->data[p->last].y;
	
	if (p->last == p->first)
		initialize(p);
	else
		p->last = (p->last - 1 + MAX_Q_SIZE) % MAX_Q_SIZE;
		
	return c;
}
 
void print(deque *p) {
	if (empty(p)) {
		printf("\n\rQueue is empty!!");
		exit(0);
	}
	
	int i;
	i = p->first;
	
	while (i != p -> last) {
		printf("\n\r(%d, %d)", p->data[i].x, p->data[i].y);
		i = (i + 1) % MAX_Q_SIZE;
	}
	
	printf("\n\r(%d, %d)\n\r", p->data[p->last].x, p->data[p->last].y);
}
