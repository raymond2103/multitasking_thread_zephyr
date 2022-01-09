/**
 * @file common.h
 * @author Raymond Sebastian (raymondsebastian2112@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COMMON_H
#define COMMON_H

/**
 * Signal Buffer Struct, to be used by thread 1 to send.
 */
typedef struct {
    bool message_from_thread_1;

    /* Variable to send the timmer valuefor debbing */
    uint64_t timmer_count;
} signal_buffer_t;

#endif /* COMMON_H */