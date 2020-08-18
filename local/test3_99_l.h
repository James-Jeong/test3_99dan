#ifndef __TEST3_99_H__
#define __TEST3_99_H__

//////////////////////////////////////
// definition & macro for test3_99_t
//////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/** 성공 여부 */
#define CAL_SUCCESS 1
/** 실패 여부 */
#define CAL_FAIL 0
/** default value to calculate */
#define DEFAULT_INT INT_MAX
/** default value to calculate */
#define MAX_NCAL 10
/** default width to print */
#define MAX_NWIDTH 5
/** default height to print */
#define MAX_NHEIGHT 10

/**@brief test3_99_t struct */
typedef struct test3_99_s test3_99_t;
struct test3_99_s{
	int val;		/**< dan number to calculate */
};

//////////////////////////////////////
// function for test3_99_t
//////////////////////////////////////
test3_99_t* test3_99_create();
int test3_99_init( test3_99_t *cal);
void test3_99_final( test3_99_t *cal);
void test3_99_destroy( test3_99_t **cal);

void test3_99_display( test3_99_t *cal);
void test3_99_clear( test3_99_t *cal);

#endif // __TEST3_99_H__

