/*	dynArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
	int i;
	
	/* Create a new underlying array */
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);
	
	/* copy elements to new data array */
	for(i = 0; i < v->size; i++)
		newData[i] = v->data[i];
	
	/* Delete the old underlying array */
	freeDynArr(v);
	/* update capacity and size and data */
	v->data = newData;
	v->capacity = newCap;
	v->size = i;
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_dynArrSetCapacity(v, 2 * v->capacity);
	
	v->data[v->size] = val;
	v->size++;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/
TYPE getDynArr(DynArr *v, int pos)
{
	assert(pos < v->size);
	assert(pos >= 0);
	
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	assert(pos < v->size);
	
	v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	TYPE  temp;
	
	assert(i < v->size);
	assert(j < v->size);
	
	temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	int i;

	for(i = idx; i < v->size-1; ++i)
		v->data[i] = v->data[i+1];

	if(idx >= 0 && idx < v->size)
		--v->size;
}

/*	Copy elements from a dynamic array to another dynamic array
	
	param: 	source	pointer to the source dynamic array
	param:	destination		pointer to the destination dynamic array
	pre:	s is not null and s is not empty
	post:	destination is initialized
	post: 	the elements from source are copied to destination
*/
void copyDynArr(DynArr *source, DynArr *destination)
{
  	int i;
	assert(source->size > 0);
	initDynArr(destination, source->capacity);
	/* copy elements to destination array */
	for(i = 0; i < source->size; i++)
		destination->data[i] = source->data[i];
	
	destination->size = source->size;
}

/* ************************************************************************
	Heap-based Priority Queue Implementation
************************************************************************ */

/* internal function prototypes */
int _smallerIndexHeap(DynArr *heap, int i, int j);
void _adjustHeap(DynArr *heap, int max, int pos);

/*	Get the index of the smaller node between two nodes in a heap
	
	param: 	heap	pointer to the heap
	param:	i	index of one node
	param:	j	index of other node
	pre:	i < size and j < size
	ret:	the index of the smaller node
*/
int _smallerIndexHeap(DynArr *heap, int i, int j)
{
  	assert(i < sizeDynArr(heap));
  	assert(j < sizeDynArr(heap));
  	if (compare(getDynArr(heap, i), getDynArr(heap, j)) == -1)
		return i;
  	else
		return j;
}

/*	Get the first node, which has the max priority (i.e., min value), 
        from the heap
	
	param: 	heap	pointer to the heap
	pre:	heap is not empty
	ret:	value of first node
*/
TYPE getMinHeap(DynArr *heap)
{
  	/* FIXME */
  	TYPE temp;
	temp = heap->data[0];
  	return temp;
}

/*	Add a node to the heap
	
	param: 	heap	pointer to the heap
	param: 	node	node to be added to the heap
	pre:	heap is not null
	post:	node is added to the heap
*/
void addHeap(DynArr *heap, TYPE node) {
  	/* FIXME */
	if (heap->size >= heap->capacity)
		_dynArrSetCapacity(heap, 2 * heap->capacity);
	int position = heap->size;
	int index = (position - 1) / 2 ;
	TYPE parentVal;
	if (position >= 0) {
		parentVal = heap->data[index];
	}
	while (position > 0 && compare(node, parentVal) < 0) {
		heap->data[position] = parentVal;
		position = index;
		index = (position - 1) / 2;
		if (index>=0) {
			parentVal = heap->data[index];
		}
	}
	heap->data[position] = node;
	heap->size++;
}

/*	Adjust heap to maintain heap property
	
	param: 	heap	pointer to the heap
	param: 	max		max index of the heap nodes in the dynamic array
	param: 	pos		position index where the adjustment starts
	pre:	none
	post:	heap property is maintained for nodes from index pos to index max
*/
void _adjustHeap(DynArr *heap, int max, int pos)
{
  	/* FIXME */
	int leftIdx = pos * 2 + 1;
	int rightIdx = pos * 2 + 2; 
	if(rightIdx < max){
		int smallIdx = _minIdx(heap, leftIdx, rightIdx);
		if(compare(heap->data[smallIdx], heap->data[pos]) < 0) {
			swapDynArr(heap, pos, smallIdx);
			_adjustHeap(heap, smallIdx, max);
		}
	}
	else if(leftIdx < max){
		if(compare(heap->data[leftIdx], heap->data[pos]) < 0) {
			swapDynArr(heap, pos, leftIdx);
			_adjustHeap(heap, leftIdx, max);
		}
	}
}

int _minIdx(struct DynArr *da, int i, int j) { /*New function*/
	/* Return index of the smaller element */
	if (compare(da->data[i], da->data[j]) < 0)
	return i;
	return j;
}

/*	Remove the first node, which has the max priority (i.e., min value), 
        from the heap
	
	param: 	heap	pointer to the heap
	pre:	heap is not empty
	post:	the first node is removed from the heap
*/
void removeMinHeap(DynArr *heap)
{
  	/* FIXME */
	/*int i;
	for (i = 0; i < heap->size; i++) {
		heap[i] = heap[i+1];
	}
	heap->size--;*/

	if(heap->size) {/*Copy the last element*/
		heap->data[0] = heap->data[heap->size-1];
	}
	heap->size--; /* update size */
	/*_adjustHeap(heap, 0, heap->size-1);*/ /*this line caused a seg fault if I remove when there's only 1 item left*/
}