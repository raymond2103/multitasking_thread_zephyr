/**
 * @file thread_2.c
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
#include "thread_2.h"
#include "../THREAD_1/thread_1.h"
#include "../common.h"
#include "../default_config.h"

/* Thread id of thread 2 */
k_tid_t thread_2_id;

/* Thread struct */
static struct k_thread thread_2_obj;

/* Setting the priority of thread 2 */
#define THREAD_2_PRIORITY 1

/* Size of stack area used by the thread */
#define THREAD_2_STACKSIZE 512
K_THREAD_STACK_DEFINE(THREAD_2_STACK_AREA, THREAD_2_STACKSIZE);

/* Statically define and initialize a message queue */
#define THREAD_2_MAX_MSG_QUEUE 3
K_MSGQ_DEFINE(thread_2_msgq, sizeof(signal_buffer_t), THREAD_2_MAX_MSG_QUEUE, 1);



/**
 * Thread 2 entry function
 */
void
thread_2_entry(void *arg1, void *arg2, void *arg3)
{
    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    #if DEBUG_TIMMER || DEBUG_TIME_DIFFERENCE
    /* Variables for testing and debugging purpose only */
    uint64_t current_timmer_value = 0;
    #endif

    /* Buffer for transmitting the data on message queue */
    signal_buffer_t received_msg;

    while (1) {

        /* Waiting for a msg */
        k_msgq_get(&thread_2_msgq, &received_msg, K_FOREVER);

        /* Avoiding any unknown msg type being received(if any) */
        if (received_msg.message_from_thread_1 == true) {

            /* Delay to wait for next execution */
            k_sleep(K_SECONDS(DELAY_BETWEEN_EACH_THREAD_IN_SEC));

            /* Printing the msg to be shown */
            printk("thread 2");

            /* For debugging the time */
            #if DEBUG_TIMMER || DEBUG_TIME_DIFFERENCE
            current_timmer_value = (k_uptime_get()/1000);
            #endif

            #if DEBUG_TIMMER
            printk(": Timer count: %lld sec", current_timmer_value);
            #endif

            #if DEBUG_TIME_DIFFERENCE
            printk("(Time Difference from thread 1: %lld sec)", current_timmer_value - received_msg.timmer_count);
            #endif /* DEBUG_TIME_DIFFERENCE */

            /* Keeping gap between each msg in the conole */
            printk("\n\n");

        } else {
            /* Discard messages (if any) not received from thread 1 */
        }
    }
}

/**
 * Start Thread 2
 */
void
start_thread_2(void)
{
    /* Creating a peripheral thread & running it without any delay */
    thread_2_id = k_thread_create(&thread_2_obj, THREAD_2_STACK_AREA, K_THREAD_STACK_SIZEOF(THREAD_2_STACK_AREA), thread_2_entry, NULL, NULL, NULL, THREAD_2_PRIORITY, K_ESSENTIAL,K_NO_WAIT);

    k_thread_name_set(thread_2_id, "THREAD 2");
}
