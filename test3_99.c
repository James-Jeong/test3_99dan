#include "local/test3_99_l.h"
//////////////////////////////////////
// static function for test3_99_t
//////////////////////////////////////
static void test3_99_get_value( test3_99_t *cal);
static int test3_99_input_data( int *val);

//////////////////////////////////////
// local function for test3_99_t
//////////////////////////////////////
/**
 * @fn test3_99_t* test3_99_create()
 * @brief function to create test3_99_t struct object
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return test3_99_t struct object
 */
test3_99_t* test3_99_create(){
	int rv = CAL_FAIL;

	test3_99_t *cal = ( test3_99_t*)malloc( sizeof( test3_99_t));
	if( cal == NULL){
		printf("\t| ! Fail to allocate test3_99_t.\n");
		return NULL;
	}

	rv = test3_99_init( cal); if( rv < CAL_SUCCESS){
		printf("\t| ! Fail to initialize test3_99_t.\n");
		return NULL;
	}

	return cal;
}

/**
 * @fn int test3_99_init( test3_99_t *cal)
 * @brief function to initialize test3_99_t struct object
 * @param cal test3_99_t struct object to initialize
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return success
 */
int test3_99_init( test3_99_t *cal){
	if( cal != NULL){
		memset( cal, 0, sizeof( test3_99_t));
		test3_99_get_value( cal);
	}
	else return CAL_FAIL;
	return CAL_SUCCESS;
}

/**
 * @fn void test3_99_final( test3_99_t *cal)
 * @brief function to finalize test3_99_t struct object, destroy memory of member objects
 * @param cal test3_99_t struct object to finalize
 * @return void
 */
void test3_99_final( test3_99_t *cal){
	test3_99_clear( cal);
}

/**
 * @fn void test3_99_destroy( test3_99_t **cal)
 * @brief function to detroy memory of test3_99_t struct object
 * @param cal test3_99_t struct object to destroy
 * @return void
 */
void test3_99_destroy( test3_99_t **cal){
	test3_99_final( *cal);
	free( *cal);
	*cal = NULL;
}

/**
 * @fn void test3_99_clear( test3_99_t *cal)
 * @brief function to clear data of test3_99_t struct object
 * @param cal test3_99_t struct object to clear
 * @return void
 */
void test3_99_clear( test3_99_t *cal){
	if( cal != NULL) memset( cal, 0, sizeof( test3_99_t));
}

/**
 * @fn void test3_99_display( test3_99_t *cal)
 * @brief function to print 99dan result of test3_99_t struct object
 * @param cal test3_99_t struct object to print
 * @return void
 */
void test3_99_display( test3_99_t *cal){
	if( cal == NULL) return ;

	int print_count = 0;
	int accum_height_count = 0;
	int cur_height_count = 1;
	int space_idx;
	int i, j, x, y;

	for( x = 0; x < MAX_NWIDTH; x++){
		for( y = 0; y < MAX_NWIDTH; y++){
			for( space_idx = 0; space_idx < cur_height_count-1; space_idx++) printf("\t");
			for( i = cur_height_count; i <= MAX_NWIDTH; i++){
				for( j = 1; j <= i + accum_height_count; j++){
					printf("%d ", ( j * cur_height_count));
				}
				if( i == cal->val) break;
				printf("\t");
			}
			printf("\n");
			cur_height_count++;
			print_count++;
			if( print_count == cal->val) break;
		}
		printf("\n");
		accum_height_count += cur_height_count - 1;
		cur_height_count = 1;
		if( print_count == cal->val) break;
	}
	printf("print_count : %d\n", print_count); 
}

static void test3_99_get_value( test3_99_t *cal){
	/** return value to check error for val */
	int rv_val = CAL_FAIL;
	cal->val = DEFAULT_INT;

	while( 1){
		if(( cal->val == DEFAULT_INT) && ( rv_val == CAL_FAIL)){
			printf("\t| @ Enter 99dan value\t: ");
			rv_val = test3_99_input_data( &cal->val);
			if( rv_val < CAL_SUCCESS) continue;
		}

		if(( cal->val != DEFAULT_INT) && ( rv_val == CAL_SUCCESS)) break;
	}
}

static int test3_99_input_data( int *val){
	int rv = scanf( "%d", val);
	if( rv == CAL_FAIL){
		printf("\t| ! Wrong value, value is not integer!\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return rv;
	}
	return rv;
}

