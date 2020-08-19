#include "local/test3_99dan_l.h"

/**
 * @fn void main()
 * @brief test3_99dan_t 모듈 구동을 위한 main 프로그램, 구구단 계산 프로그램
 * 단수를 입력받아서 해당 단수까지 구구단을 출력한다.
 * 1부터 10까지의 곱을 계산해서 가로로 최대 다섯개의 구구단까지 출력한다.
 * @return 설정하지 않음
 */
void main(){
	int rv = CAL_FAIL;
	int dan_number = DEFAULT_INT;

	rv = test3_99dan_input_dan_number( &dan_number);
	if( rv < CAL_SUCCESS){
		printf("\t| ! Input dan number error\n");
		return ;
	}

	test3_99dan_display_99dan_result( dan_number);
}

