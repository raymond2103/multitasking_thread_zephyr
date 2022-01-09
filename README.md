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