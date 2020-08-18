#include "local/test3_99dan_l.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief test3_99dan_t 모듈 구동을 위한 main 프로그램
 * @return none
 * @param argc none
 * @param argv none
 */
int main( int argc, char **argv){
	test3_99dan_t *cal = test3_99dan_create();
	if( cal == NULL) return CAL_FAIL;
	test3_99dan_display( cal);
	test3_99dan_destroy( &cal);
}

