#include "local/test3_99dan_l.h"
//////////////////////////////////////
// static function for test3_99dan_t
//////////////////////////////////////
static int test3_99dan_input_number( int *val);

//////////////////////////////////////
// local function for test3_99dan_t
//////////////////////////////////////
/**
 * @fn int test3_99dan_input_width_number()
 * @brief 가로로 출력하는 단의 개수를 입력받는 함수
 * @param width_number 입력받을 가로로 출력하는 단의 개수
 * @return 입력 성공 여부
 */
int test3_99dan_input_width_number( int *width_number){
	int rv = CAL_FAIL;

	while( 1){
		if(( *width_number == DEFAULT_INT) && ( rv == CAL_FAIL)){
			printf("\t| @ Enter 99dan width number (1~5)\t: ");
			rv = test3_99dan_input_number( width_number);
			if( rv < CAL_SUCCESS) continue;
		}
		if(( *width_number != DEFAULT_INT) && ( rv == CAL_SUCCESS)) break;
	}

	return rv;
}

/**
 * @fn void test3_99dan_display_99dan_result( int width_number)
 * @brief 구구단을 계산해서 결과를 출력하는 함수, 가로로 출력하는 단의 개수에 따라 1단부터 10단까지 출력한다.
 * @param width_number 가로로 출력하는 단의 개수
 * @return 설정하지 않음
 */
void test3_99dan_display_99dan_result( int width_number){
	/** accumulative dan number to break loop & check current dan number */
	int accum_dan = 0;
	/** temporary width value to print until static width value */
	int width;
	/** temporary height value to print until static height value */
	int height;
	/** level value to define level, level is the area for printing 99dan by the static value of width & height */
	int level = ( MAX_NCAL / width_number) + 1;
	/** current level value to check level */
	int cur_level;
	/** current 99dan number */
	int n99dan;

	printf("\n");
	for( cur_level = 1; cur_level <= level; cur_level++){ // manage level
		for( height = 1; height <= MAX_NHEIGHT; height++){ // manage height upto MAX_NHEIGHT
			for( width = 1; width <= width_number; width++){ // manage width upto width_number (input)
				n99dan = width + accum_dan;
				printf("(%d) X (%d) = %d ", n99dan, height, ( n99dan * height)); // calculate & print 99dan
				if( n99dan >= MAX_NCAL) break;
				if( width != width_number) printf("  \t| "); // print tab
			} printf("\n");
		} printf("\n");
		accum_dan += width_number;
		if( accum_dan >= MAX_NCAL) break;
	}
}

/**
 * @fn static int test3_99dan_input_number( int *val)
 * @brief 구구단 숫자 입력 시 사용될 함수, scanf 사용
 * @param val 입력받을 int형 정수 변수
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
	else if( *val > MAX_NWIDTH){
		printf("\t| ! Wrong value, value is over max width number(5)!\n");
		*val = DEFAULT_INT;
		return CAL_FAIL;
	}

	return rv;
}

