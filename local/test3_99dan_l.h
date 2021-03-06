#ifndef __TEST3_99DAN_H__
#define __TEST3_99DAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//////////////////////////////////////
// Definitions & Macros
//////////////////////////////////////

/** 성공 여부 */
#define SUCCESS 1
/** 실패 여부 */
#define FAIL 0
/** 숫자 정상 입력 확인 여부, 정상 입력 실패 시 해당 변수가 DEFAULT_INT 로 초기화됨 */
#define DEFAULT_INT INT_MAX
/** 구구단 진행 최대 단수 */
#define MAX_NCAL 10
/** 가로 출력 최대 개수 */
#define MAX_NWIDTH 5
/** 세로 출력 최대 개수 */
#define MAX_NHEIGHT 10

//////////////////////////////////////
// Functions
//////////////////////////////////////

void input_width_number( int *width_number);
void display_99dan_result( int width_number);

#endif // #ifndef __TEST3_99DAN_H__

