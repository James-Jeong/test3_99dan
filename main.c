#include "local/test3_99dan_l.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief test3_99dan_t 모듈 구동을 위한 main 프로그램
 * @return none
 * @param argc none
 * @param argv none
 */
int main( int argc, char **argv){
	int dan_number = 0;
	test3_99dan_input_dan_number( &dan_number);
	test3_99dan_display_99dan_result( dan_number);
}

