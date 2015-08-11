#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, const char * argv[]) {
    int * const items = (int *) malloc(sizeof(int) * 6);
    int * const itemsReverse = (int *) malloc(sizeof(int) * 6);

    for (int i=0, j = 5; i<6 && j >= 0; i ++, j --) {
    	items[i] = i;
    	itemsReverse[i] = j;
    }

    int* const index = (int *) malloc(sizeof(int));
    *index = -1;


    SearchResult response = Search(items, 6, 1, 3, LessThan, index);
    if(response == FoundLess && *index == 2) {
    	printf("pass\n");
    }
    else {
    	printf("%d, %d\n", response, *index);
    }
    response = Search(itemsReverse, 6, 0, 3, LessThan, index);
	if(response == FoundLess && *index == 3) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


    response = Search(items, 6, 1, 0, LessThan, index);
    if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
    response = Search(itemsReverse, 6, 0, 0, LessThan, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


    response = Search(items, 6, 1, 3, LessThanEquals, index);
    if(response == FoundExact && *index == 3) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
    response = Search(itemsReverse, 6, 0, 3, LessThanEquals, index);
	if(response == FoundExact && *index == 2) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 100, LessThanEquals, index);
    if(response == FoundLess && *index == 5) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 100, LessThanEquals, index);
    if(response == FoundLess && *index == 0) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 100, Equals, index);
    if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
    response = Search(itemsReverse, 6, 0, 100, Equals, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 5, Equals, index);
    if(response == FoundExact && *index == 5) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
    response = Search(itemsReverse, 6, 0, 5, Equals, index);
	if(response == FoundExact && *index == 0) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


    response = Search(items, 6, 1, 10, Equals, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 10, Equals, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 10, GreaterThan, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 10, GreaterThan, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 5, GreaterThan, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 5, GreaterThan, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 2, GreaterThan, index);
	if(response == FoundGreater && *index == 3) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 2, GreaterThan, index);
	if(response == FoundGreater && *index == 2) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 2, GreaterThanEquals, index);
	if(response == FoundExact && *index == 2) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 2, GreaterThanEquals, index);
	if(response == FoundExact && *index == 3) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, -1, GreaterThanEquals, index);
	if(response == FoundGreater && *index == 0) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, -1, GreaterThanEquals, index);
	if(response == FoundGreater && *index == 5) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 6, GreaterThanEquals, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 6, GreaterThanEquals, index);
	if(response == NotFound && *index == -1) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}


	response = Search(items, 6, 1, 5, GreaterThanEquals, index);
	if(response == FoundExact && *index == 5) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
	response = Search(itemsReverse, 6, 0, 5, GreaterThanEquals, index);
	if(response == FoundExact && *index == 0) {
		printf("pass\n");
	}
	else {
		printf("%d, %d\n", response, *index);
	}
}
