/**
 * @file thread_2.h
 * @author Raymond Sebastian (raymondsebastian2112@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef THREAD_2_H
#define THREAD_2_H

extern struct k_msgq thread_2_msgq;

/**
 * @brief Helper function to start thread 2
 *
 */
void start_thread_2(void);

#endif  /* THREAD_2_H */