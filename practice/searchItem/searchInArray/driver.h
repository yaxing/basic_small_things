/*
 * driver.h
 *
 *  Created on: Aug 9, 2015
 *      Author: yaxing
 */

#ifndef DRIVER_H_
#define DRIVER_H_

typedef enum {

    LessThan = 0,

    LessThanEquals = 1,

    Equals = 2,

    GreaterThanEquals = 3,

    GreaterThan = 4

} SearchType;



typedef enum {

    NotFound,

    FoundExact,

    FoundGreater,

    FoundLess

} SearchResult;

#endif /* DRIVER_H_ */
