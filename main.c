#include "local/test3_99dan_l.h"

/**
 * @fn void main()
 * @brief test3_99dan_t 모듈 구동을 위한 main 프로그램, 구구단 계산 프로그램
 * 가로로 출력하는 단의 갯수(최대 5개)를 지정해서 출력한다.
 * 1단부터 10단까지 출력한다.
 * @return 설정하지 않음
 */
void main(){
	int rv = CAL_FAIL;
	int width_number = DEFAULT_INT;

	rv = test3_99dan_input_width_number( &width_number);
	if( rv < CAL_SUCCESS){
		printf("\t| ! Input dan number error\n");
		return ;
	}

	test3_99dan_display_99dan_result( width_number);
}

