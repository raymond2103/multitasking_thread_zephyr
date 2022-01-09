/**
 * @file thread_1.c
 * @author Raymond Sebastian (raymondsebastian2112@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <zephyr.h>
#include <sys/byteorder.h>
#include <device.h>
#include "thread_1.h"
#include "../THREAD_2/thread_2.h"
#include "../common.h"
#include "../default_config.h"

/* Thread id of thread 1 */
k_tid_t thread_1_id;

/* Thread struct */
static struct k_thread thread_1_obj;

/* Setting the priority of thread 1 */
#define THREAD_1_PRIORITY 2

/* Size of stack area used by the thread */
#define THREAD_1_STACKSIZE 512
K_THREAD_STACK_DEFINE(THREAD_1_STACK_AREA, THREAD_1_STACKSIZE);



/**
 * Thread 1 entry function
 */
void
thread_1_entry(void *arg1, void *arg2, void *arg3)
{
    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

	uint8_t delay_period = MIN_DELAY_PERIOD;

    /* Buffer for transmitting the data on message queue */
    signal_buffer_t send_msg;
    
    /* Starting the thread after 1sec delay */
    k_sleep(K_SECONDS(1));

    while (1) {

        /* Printing the msg to be shown */
        printk("thread 1");

        /* Keeping gap between each msg in the conole */
        printk("\n");

        /* Signalling a msg to thread 2 */
        send_msg.message_from_thread_1 = true;
        k_msgq_put(&thread_2_msgq, &send_msg, K_NO_WAIT);

        /* Calculating the time delay for next msg to be printed */
        if(delay_period >= MAX_DELAY_PERIOD){
			/* Resetting the delay period */
			delay_period = MIN_DELAY_PERIOD;
		} else {
			/* Incrementing the delay period */
			delay_period += DELAY_INCREMENT_PERIOD;
		}

        /* Delay to wait for next execution */
		k_sleep(K_SECONDS(delay_period));
    }
}

/**
 * Start Thread 1
 */
void
start_thread_1(void)
{
    /* Creating a peripheral thread & running it without any delay */
    thread_1_id = k_thread_create(&thread_1_obj, THREAD_1_STACK_AREA, K_THREAD_STACK_SIZEOF(THREAD_1_STACK_AREA), thread_1_entry, NULL, NULL, NULL, THREAD_1_PRIORITY, K_ESSENTIAL,K_NO_WAIT);

    k_thread_name_set(thread_1_id, "THREAD 1");
}
