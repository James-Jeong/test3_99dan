#include "local/test3_99dan_l.h"

//////////////////////////////////////
// Static function
//////////////////////////////////////

static int input_number( int *val);

//////////////////////////////////////
// Local functions
//////////////////////////////////////

/**
 * @fn void test3_99dan_input_width_number()
 * @brief 가로로 출력하는 단의 개수를 입력받는 함수
 * @param width_number 입력받을 가로로 출력하는 단의 개수
 * @return 반환값 없음
 */
void test3_99dan_input_width_number( int *width_number){
	int return_value = CAL_FAIL;

	while( 1){
		if(( *width_number == DEFAULT_INT) && ( return_value == CAL_FAIL)){
			printf("\t| @ 가로 출력 개수 입력 (1~5)\t: ");
			return_value = input_number( width_number);
			if( return_value == CAL_FAIL) continue;
		}
		if(( *width_number != DEFAULT_INT) && ( return_value == CAL_SUCCESS)) break;
	}
}

/**
 * @fn void test3_99dan_display_99dan_result( int width_number)
 * @brief 구구단을 계산해서 결과를 출력하는 함수, 가로로 출력하는 단의 개수(최대 5개)에 따라 1단부터 10단까지 출력한다.
 * @param width_number 가로로 출력하는 단의 개수
 * @return 반환값 없음
 */
void test3_99dan_display_99dan_result( int width_number){
	/** 반복문 탈출을 위해 단수를 누적해서 기록하는 변수 */
	int accum_dan = 0;
	/** 구구단 출력을 위한 반복문의 임시 가로 개수 */
	int width = 1;
	/** 구구단 출력을 위한 반복문의 임시 세로 개수 */
	int height = 1;
	/** 출력 레벨, 구구단이 출력되는 가로 영역 */
	int level = ( MAX_NCAL / width_number) + 1;
	/** 현재 레벨을 확인하는 변수 */
	int cur_level = 1;
	/** 현재 단수 */
	int n99dan = 0;

	printf("\n");
	for( ; cur_level <= level; cur_level++){ // 레벨 관리
		for( height = 1; height <= MAX_NHEIGHT; height++){ // MAX_NHEIGHT 까지 반복
			for( width = 1; width <= width_number; width++){ // width_number (input) 까지 반복
				n99dan = width + accum_dan;
				printf("(%d) X (%d) = %d ", n99dan, height, ( n99dan * height));
				if( n99dan >= MAX_NCAL) break;
				if( width != width_number) printf("  \t| ");
			} printf("\n");
		} printf("\n");
		accum_dan += width_number;
		if( accum_dan >= MAX_NCAL) break;
	}
}

/**
 * @fn static int input_number( int *val)
 * @brief 숫자 입력 시 사용될 함수
 * @param val 입력받을 int형 정수 변수
 * @return 성공 시 CAL_SUCCESS, 실패 시 CAL_FAIL 을 반환
 */
static int input_number( int *val){
	int return_value = scanf( "%d", val);

	if( return_value == CAL_FAIL){
		printf("\t| ! 입력 실패, 정수가 아닌 문자열 입력.\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return return_value;
	}
	else if( *val <= CAL_FAIL){
		printf("\t| ! 입력 실패, 최소 가로 출력 개수(1) 미만\n");
		*val = DEFAULT_INT;
		return CAL_FAIL;
	}
	else if( *val > MAX_NWIDTH){
		printf("\t| ! 입력 실패, 최대 가로 출력 개수(5) 초과\n");
		*val = DEFAULT_INT;
		return CAL_FAIL;
	}

	return return_value;
}
