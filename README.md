# multitasking_thread_zephyr

Sample Application for testing
##############################

********
Overview
********

A simple application to demonstrates multi-thread functionality.

* Create one thread on Zephyr that repeatedly prints "thread 1".
The time period between prints increments with steps of 1s and
overflows back to 1s after 10s.

* Create one more thread that prints "thread 2" one second after
"thread 1" print by getting a message from thread 1.





************
Requirements
************

* Linux environment(required) [Latest MAC OS doesn't support 32-bit arch]
* Firmware was developed,build and tested on Zephyr OS (v2.7.1)
* Clone the project to <$PATH_TO_ZEPHYR_PROJECT_DIRECTORY>/zephyr/samples/




************
Assumptions
************

* The code is being compiled on an Linux debian environment (at your end).
* The zephyr OS version is v2.7.1 and all the requirements are met as per the zephyr documentation.
* Assuming the application is placed in :zephyr_file:`/samples/multitasking_thread_zephyr` in the Zephyr tree.
* Assuming the terminal is directed to zephyr_projects.
Eg. cd <ZEPHYR_PATH>/


********************
Building and Running
********************

-> To build and run the code in native posix, run the command below..
Command: 
west build -p -b native_posix zephyr/samples/multithread_sample -t run


Output
******

*** Booting Zephyr OS build zephyr-v2.7.1  ***
thread 1
thread 2

thread 1
thread 2

thread 1
thread 2

thread 1
thread 2

thread 1
thread 2
:
:





To debug the timmer
*******************

Set the value of 'DEBUG_TIMMER' in default_config.h to 1 instead of 0.
This will help print the timmer clock from when the application is started.

Expected output after setting 'DEBUG_TIMMER' to 1
*************************************************

*** Booting Zephyr OS build zephyr-v2.7.1  ***
thread 1: Timer count: 1 sec
thread 2: Timer count: 2 sec

thread 1: Timer count: 3 sec
thread 2: Timer count: 4 sec

thread 1: Timer count: 6 sec
thread 2: Timer count: 7 sec

thread 1: Timer count: 10 sec
thread 2: Timer count: 11 sec

thread 1: Timer count: 15 sec
thread 2: Timer count: 16 sec
:
:






To debug the time difference and/or timmer count
************************************************

Set the value of 'DEBUG_TIME_DIFFERENCE' in default_config.h to 1 instead of 0.
This will help print the timmer clock from when the application is started.

Expected output after setting 'DEBUG_TIME_DIFFERENCE' to 1
**********************************************************

*** Booting Zephyr OS build zephyr-v2.7.1  ***
thread 1: Timer count: 1 sec(Time Difference: 1 sec)
thread 2: Timer count: 2 sec(Time Difference from thread 1: 1 sec)

thread 1: Timer count: 3 sec(Time Difference: 2 sec)
thread 2: Timer count: 4 sec(Time Difference from thread 1: 1 sec)

thread 1: Timer count: 6 sec(Time Difference: 3 sec)
thread 2: Timer count: 7 sec(Time Difference from thread 1: 1 sec)

thread 1: Timer count: 10 sec(Time Difference: 4 sec)
thread 2: Timer count: 11 sec(Time Difference from thread 1: 1 sec)

thread 1: Timer count: 15 sec(Time Difference: 5 sec)
thread 2: Timer count: 16 sec(Time Difference from thread 1: 1 sec)
:
:

