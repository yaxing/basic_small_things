/*
 * search.h
 *
 *  Created on: Aug 9, 2015
 *      Author: yaxing
 */

#include "driver.h"
#include <stdbool.h>

#ifndef SEARCH_H_
#define SEARCH_H_

/*
 * found
 *
 * --------
 *
 * compare target and comparable values and return true only in following cases:
 *  - type < 2 (LessThan or LessThanEquals) && target < comparable: true
 *  - type > 2 (GreaterThan or GreaterThanEquals) && target > comparable: true
 *  - type == 2 && target == comparable: true
 * returns: true if matches, else false
 */
bool found(const SearchType type, int target, int comparable) {
	if(
			((type == LessThan || type == LessThanEquals) && target < comparable)
			|| ((type == GreaterThan || type == GreaterThanEquals) && target > comparable)
			|| (type == Equals && target == comparable)) {
		return true;
	}
	return false;
}

/*
 * iterateAndFind
 *
 * --------
 *
 * iterate through items from index=0 and try to find:
 *   - findLessThan == true: the very first item which item < key
 *   - findLessThan == false: the very first item which item > key
 *
 * returns: -1 if not found, otherwise the index of found item
 */
int iterateAndFind(const int * const items, const int n_items, const int key, const SearchType type) {
	for(int i = 0; i < n_items; i ++) {
		if(found(type, items[i], key)) {
			return i;
		}
	}
	return -1;
}

/*
 * iterateAndFindReverse
 *
 * --------
 *
 * iterate through items from index=n_items - 1 to 0 and try to find:
 *   - findLessThan == true: the very first item which item < key
 *   - findLessThan == false: the very first item which item > key
 *
 * returns: found item index, -1 if not found, otherwise the index of found item
 */
int iterateAndFindReverse(const int * const items, const int n_items, const int key, const SearchType type) {
	for(int i = n_items - 1; i >= 0; i --) {
		if(found(type, items[i], key)) {
			return i;
		}
	}
	return -1;
}

/*
 * findOnOrderAndType
 *
 * --------
 *
 * this method calls
 *   - iterateAndFindReverse
 *   - iterateAndFind
 * to search key based on different types
 *
 *
 * return: found item index, -1 if not found, otherwise the index of found item
 */
int findOnOrderAndType(const int * const items, const int n_items, const int key, const int ascending, const SearchType type) {
	int foundIndex = -1;
	if(type == LessThan || type == LessThanEquals || type == Equals) {
		foundIndex = ascending != 0 ? iterateAndFindReverse(items, n_items, key, type) : iterateAndFind(items, n_items, key, type);
	}
	else {
		// GreaterThan & GreaterThanEquals
		foundIndex = ascending != 0 ? iterateAndFind(items, n_items, key, type) : iterateAndFindReverse(items, n_items, key, type);
	}
	return foundIndex;
}

/*
 * isExactMatch
 *
 * --------
 *
 * compare items[targetIndex] with key, return if they are the same.
 * handles targetIndex range limits
 *
 * returns:
 * 		- false if targetIndex < 0 or targetIndex >= n_items
 * 		- false if items[targetIndex] != key
 * 		- true if items[targetIndex] == key
 */
bool isExactMatch(const int * const items, const int n_items, const int key, const int targetIndex) {
	if(targetIndex >= n_items || targetIndex < 0) {
		return false;
	}
	return items[targetIndex] == key;
}

SearchResult Search(

                    const int * const items,

                    const int n_items,

                    const int ascending,

                    const int key,

                    const SearchType type,

                    int* const index)

{
	*index = -1;
	*index = findOnOrderAndType(items, n_items, key, ascending, type);

	if(ascending != 0
			&& ((type == LessThanEquals && isExactMatch(items, n_items, key, *index + 1))
					||
					(type == GreaterThanEquals && isExactMatch(items, n_items, key, *index == -1 ? n_items - 1 : *index - 1)))) {
		*index += type == LessThanEquals ? 1 : -1;
		if(*index < 0) {
			*index = n_items - 1;
		}
		return FoundExact;
	}
	else if(ascending == 0
			&& ((type == LessThanEquals && isExactMatch(items, n_items, key, *index == -1 ? n_items - 1 : *index - 1))
					||
					(type == GreaterThanEquals && isExactMatch(items, n_items, key, *index + 1)))) {
		*index += type == LessThanEquals ? -1 : 1;
		return FoundExact;
	}

	if(*index < 0) {
		return NotFound;
	}

	switch(type) {
	case Equals:
		return FoundExact;
	case LessThan:
		return FoundLess;
	case LessThanEquals:
		return FoundLess;
	case GreaterThan:
		return FoundGreater;
	case GreaterThanEquals:
		return FoundGreater;
	}

    return NotFound;
}

#endif /* SEARCH_H_ */
