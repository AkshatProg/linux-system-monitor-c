# Linux System Monitor in C

## Project Overview

Linux System Monitor is a command-line application written in C that reads and displays system information using the Linux Proc Filesystem.

The project collects and processes information such as CPU details, memory statistics, and system uptime by reading virtual files provided by the Linux kernel.

This project was built to strengthen my understanding of:

* C Programming
* Linux File Handling
* String Parsing
* Linux Proc Filesystem
* Embedded Linux Fundamentals

---

## Features

### CPU Information

Reads CPU model information from:

```text
/proc/cpuinfo
```

Displays the processor model available on the system.

### Memory Information

Reads memory statistics from:

```text
/proc/meminfo
```

Displays:

* Total Memory
* Free Memory
* Used Memory

### System Uptime

Reads uptime information from:

```text
/proc/uptime
```

Displays uptime in:

* Hours
* Minutes

---

## Linux Interfaces Used

| File          | Purpose           |
| ------------- | ----------------- |
| /proc/cpuinfo | CPU Information   |
| /proc/meminfo | Memory Statistics |
| /proc/uptime  | System Uptime     |

---

## Concepts Learned

### C Programming

* Functions
* Variables and Data Types
* Program Structure

### File Handling

* fopen()
* fclose()
* fgets()
* fscanf()

### String Handling

* strncmp()
* sscanf()

### Linux

* Proc Filesystem
* Reading System Information
* Parsing Kernel-Provided Data

### Git & GitHub

* Repository Creation
* Version Control
* Commit and Push Workflow

---

## Sample Output


```text
=====================================
      Linux System Monitor v1
=====================================

CPU Information
-----------------------------
AMD Ryzen 5 7235HS

Memory Information
-----------------------------
Total Memory : 11806.21 MB
Free Memory  : 10521.53 MB
Used Memory  : 1284.69 MB

System Uptime
-----------------------------
0 hours 58 minutes

=====================================
```

---

## Build and Run

Compile:

```bash
gcc monitor.c -o monitor
```

Run:

```bash
./monitor
```

---

## Future Improvements

* CPU Usage Monitoring
* Memory Usage Percentage
* Real-Time Refresh Mode
* Disk Usage Statistics
* Process Monitoring

---

## Author

Akshat Sinha

GitHub:
https://github.com/AkshatProg
