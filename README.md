# System-event-handler
The idea of this application is to catch the "three-finger salute" aka CTRL+ALT+DEL signal and perform some actions- display GUI component to execute to access LDAP (and other functionalities). 

When the CTRL+ALT+DEL is pressed and a non-maskable interupt (NMI) is sent to the CPU, as Windows opens the full-screen UI. If we can catch the NMI signal, we can display an overlay button in the corner with some padding. 

[x] Implement signal handler that catches Standard signals for Linux system
[x] Implement mock signal sender for Linux system
[ ] Test compatibility in Windows System
[ ] Find proper system code for CTRL+ALT+DEL
[ ] Implement event handler for found system code

## base-event-handler

Usage: `base-event-handler`

### Description
Event handler that creates asynchronous signal handlers to catch specefic signals and print messages to shell.
The signals that are currently catching are:
* SIGALAM
* SIGUSR1
* SIGINT

All the signals are found on [Linux Man7 page.](https://www.man7.org/linux/man-pages/man7/signal.7.html)


## sendsig 

Usage: ` sendsig  <signal type> <pid> `

### Description
The sendsig command can be utilized to send different signal codes to any assigned PID. You can 

Linux supports the following signals. 
[ ] This program should be im

The options are as follows: 

 * -i : SIGINT
 * -u : SIGUSR1
