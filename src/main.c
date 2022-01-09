/**
 * @file main.c
 * @author Raymond Sebastian (raymondsebastian2112@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <zephyr.h>

#include "THREAD_1/thread_1.h"
#include "THREAD_2/thread_2.h"

#include "common.h"

void
main(void)
{
    /* Starting the threads in main */

    /* Starting thread 1 */
    start_thread_1();

    /* Starting thread 2 */
    start_thread_2();
}
