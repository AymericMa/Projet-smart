# BLE serial communication
| AT Command                                      | Send                         | Receive                        | Parameter                                                                                                                                                           |
|-------------------------------------------------|------------------------------|--------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Test                                            | AT                           | OK OK+LOST                     | None                                                                                                                                                                |
| Query Adress                                    | AT+ADDR?                     | OK+GET:[Para]                  | Para:0~1 0:100 ms 1:1285 ms                                                                                                                                         |
| Battery info                                    | AT+BATT?                     | OK+BATT:[Para]                 | Para:000~100                                                                                                                                                        |
| Set baudrate                                    | AT+BAUD? AT+BAUD[para1]      | OK+Get:[para1]                 | Para1: Baud rate No. 0---------9600 1---------19200  2---------38400 3---------57600 4---------115200 Default: 0(9600)                                              |
| Parity                                          | AT+PARI? Set: AT+PARI[para1] | OK+Get:[para1]                 | Para1: 0,1,2 0:None 1:EVEN 2:ODD Default: 0 (None)                                                                                                                  |
| Mode                                            | AT+MODE? AT+MODE[para1]      |  OK+Get:[para1] OK+Set:[para1] | Para1: 0, 1, 2 0: Transmission Mode 1: Remote Control Mode 2: 0 Mode + 1 Mode Default: 0                                                                            |
| Rename                                          | AT+NAME？ AT+NAME[para1]     | OK+NAME[para1] OK+Set[para1]   | Para1: module name, Max length is 12. Default: HMSoft                                                                                                               |
| Restore setup Factory                           | AT+RENEW                     | OK+RENEW                       | None                                                                                                                                                                |
| RESET                                           | AT+RESET                     | OK+RESET                       | None                                                                                                                                                                |
| Set master or slave                             | AT+ROLE? AT+ROLE[para1]      | OK+ROLE:[para1] OK+Set:[para1] | Para1: M, S M: Master  S: Slaver Default: S                                                                                                                         |
| Clear Last Connected device                     | AT+CLEAR                     | OK+CLEAR                       | None                                                                                                                                                                |
| Help                                            | AT+HELP?                     | Help Information               | None                                                                                                                                                                |
| Set module work type                            | AT+IMME? AT+IMME[para1]      | OK+IMME:[para1] OK+Set:[para1] | Para1: 0, 1 0: When module is powered on, only respond the AT Command, don’t do anything. until AT + WORK is received 1: When power on, work immediately Default: 1 |
| Work immediately                                | AT+WORK                      | OK+WORK                        | None (Use when AT+IMME1 is setup)                                                                                                                                   |
| Set module connect remote device timeout value  | AT+TCON? AT+TCON[para1]      | OK+TCON:[para1] OK+Set:[para1] |                                                                                                                                                                     |
| Switch Remote Control Mode to Transmission Mode | AT+START                     | OK+START                       | None                                                                                                                                                                |
| Set Module Power                                | AT+POWE?  AT+ POWE [para1]   | OK+Get:[para1] OK+Set:[para1]  | Para: 0 ~ 3 0: -23dbm 1: -6dbm 2: 0dbm 3: 6dbm Default: 2                                                                                                           |

# BLE connection to module
First find the BLE module :
`bluetoothctl`
`scan on`
`connect D0:FF:50:74:14:B3`

Then open a link to rfcomm in another terminal:
`scan on`
`sudo rfcomm bind 0 D0:FF:50:74:14:B3`

To test use :
`ls /dev/rfcomm0`

When you have finish:
`rfcomm release 0`

Go to bluetooth terminal:

`disconnect`
`quit`
