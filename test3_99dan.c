#include "local/test3_99dan_l.h"
//////////////////////////////////////
// static function for test3_99dan_t
//////////////////////////////////////
static int test3_99dan_input_number( int *val);

//////////////////////////////////////
// local function for test3_99dan_t
//////////////////////////////////////
/**
 * @fn int test3_99dan_input_dan_number()
 * @brief 구구단 숫자를 입력받는 함수
 * @param dan_number 입력받을 단수
 * @return 입력 성공 여부
 */
int test3_99dan_input_dan_number( int *dan_number){
	/** return value to check error for val */
	int rv = CAL_FAIL;

	while( 1){
		if(( *dan_number == DEFAULT_INT) && ( rv == CAL_FAIL)){
			printf("\t| @ Enter 99dan number\t: ");
			rv = test3_99dan_input_number( dan_number);
			if( rv < CAL_SUCCESS) continue;
		}
		if(( *dan_number != DEFAULT_INT) && ( rv == CAL_SUCCESS)) break;
	}

	return rv;
}

/**
 * @fn void test3_99dan_display_99dan_result( int dan_number)
 * @brief 구구단을 계산해서 결과를 출력하는 함수, 정해진 단까지 출력한다.
 * @param dan_number 계산 및 출력될 최대 구구단 단수
 * @return 설정하지 않음
 */
void test3_99dan_display_99dan_result( int dan_number){
	/** accumulative dan number to break loop & check current dan number */
	int accum_dan = 0;
	/** temporary width value to print until static width value */
	int width;
	/** temporary height value to print until static height value */
	int height;
	/** level value to define level, level is the area for printing 99dan by the static value of width & height */
	int level = ( dan_number / MAX_NWIDTH) + 1;
	/** current level value to check level */
	int cur_level;
	/** current 99dan number */
	int n99dan;

	printf("\n");
	for( cur_level = 1; cur_level <= level; cur_level++){ // manage level
		for( height = 1; height <= MAX_NHEIGHT; height++){ // manage height upto MAX_NHEIGHT
			for( width = 1; width <= MAX_NWIDTH; width++){ // manage width upto MAX_NWIDTH
				n99dan = width + accum_dan;
				printf("(%d) X (%d) = %d ", n99dan, height, ( n99dan * height)); // calculate & print 99dan
				if( n99dan >= dan_number) break;
				if( width != MAX_NWIDTH) printf("  \t\t| "); // print tab
			} printf("\n");
		} printf("\n");
		accum_dan += MAX_NWIDTH;
		if( accum_dan >= dan_number) break;
	}
}

/**
 * @fn static int test3_99dan_input_number( int *val)
 * @brief 구구단 숫자 입력 시 사용될 함수, scanf 사용
 * @param val value by scanf function
 * @return 입력 성공 여부
 */
static int test3_99dan_input_number( int *val){
	int rv = scanf( "%d", val);

	if( rv == CAL_FAIL){
		printf("\t| ! Wrong value, value is not integer!\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return rv;
	}
	else if( *val <= CAL_FAIL){
		printf("\t| ! Wrong value, value is not positive!\n");
		*val = DEFAULT_INT;
		return CAL_FAIL;
	}
	else if( *val >= DEFAULT_INT){
		printf("\t| ! Wrong value, value is over INT_MAX!\n");
		*val = DEFAULT_INT;
		return CAL_FAIL;
	}

	return rv;
}

