#include "local/test3_99dan_l.h"

/**
 * @fn void main()
 * @brief test3_99dan_t 모듈 구동을 위한 main 프로그램, 구구단 계산 프로그램
 * @return none
 */
void main(){
	int dan_number = 0;
	test3_99dan_input_dan_number( &dan_number);
	test3_99dan_display_99dan_result( dan_number);
}

