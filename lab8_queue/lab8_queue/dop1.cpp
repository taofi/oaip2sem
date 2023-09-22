#include "stdafx.h"

void SortPush(queue*& begin, queue*& end, char sim){
	queue* pv = new queue;
	queue* tmp = begin;
	pv->data = sim;
	pv->next = NULL;
	if (begin == nullptr)
		begin = end = pv;
	else
	{
		if (begin->data > sim)
		{
			pv->next = begin;
			begin = pv;
		}
		else {
			while (tmp->next != NULL && tmp->next->data < sim)
				tmp = tmp->next;
			if (tmp->next == NULL)
				push(begin, end, sim);
			else {
				pv->next = tmp->next;
				tmp->next = pv;
			}
		}
	}
	
}