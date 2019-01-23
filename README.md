# PIC16_SMART_WEATHER_STATION

## PicKit3 not found ...

If you are having this issue when you try to make and programm device, it mean
that your account doesn't have the right to access usb for PicKit3... Follow
those step:

Step #2:
Create a new group with name "microchip":

`sudo groupadd -g 200 microchip`

Step #3:
Create a new rules file with editor:

`sudo gedit /etc/udev/rules.d/26-microchip.rules`

Step #4:
Copy this text to opened file:

`#Read/write access to Microchip devices
ATTR{idVendor}=="04d8", OWNER:="root", GROUP:="microchip", MODE:="0660"`

Save and close the file.

Step #5:Add yourself to group:

`sudo adduser YOUR_ACCOUNT_NAME microchip`

If you don't now your account name, you can get it with this command:
`whoami`

Step #6:
Reboot your computer:
`sudo reboot`

## Problem with compilation with MPLAX 5 and XC16 2.00
I get this error when it is using xc8 rather than xc8-cc.  (That's xc8.exe, xc8-cc.exe for Windows users)
Go to Tools->Options->Embedded->Build Tools and look at the Compiler and Assembler settings for XC8 (v2.00).  If they are for xc8, change them to xc8-cc.  (You might try clicking the "Remove" button for XC8 (v2.00) and then clicking the "Scan for Build Tools" to see if it will come up with xc8-cc on its own.  If not, make the changes manually.)

You may have to change the Standard setting in the Project->XC8 Global Options box to C90 and back to c99 to see the effect of the new setting when you re-compile.  (Maybe even exit the IDE and restart.)

Bottom line: Once I got it to use xc8-cc, things went smoothly.

## Problem with VDD not found
Go to File > Project Properties
Choose PicKit3 then in the Combox select Power then tick the "Power target circuit from PicKit3" and choose 3,375 V

# Component

[BLE module HM10 CC2541](BLE_Module.md)
