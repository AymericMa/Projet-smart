# Home assistant
## Install home assistant
* Download the Hassbian image
* Use Etcher to flash the image to your SD card. We recommend at least a 32 GB SD card to avoid running out of space.
* Ensure your Raspberry Pi has wired access to the internet for the entire process or configure your wireless network settings before proceeding to step 4.
If you don't have a box like you can do this:
plug you raspbbery pi, log in with `pi` and `raspberry` as credential.

Then type `sudo rasp-config`, choose Network manager and select Wifi then enter your SSID (for me it's `iPhone`) and the password

`reboot` and you should be connect.

Then do the classic command to update your pi:

`sudo apt-get update` `sudo apt-get upgrade`

Then update home assistant and Hassbian with this:

`sudo hassbian-config upgrade homeassistant`
`sudo hassbian-config upgrade hassbian`

If it fail retry the command then `reboot`

## Connect to homeassistant

In the terminal of Raspberry Pi type `ifconfig` and if you are in wifi you sould find an IP like : 172.20.10.12

Go on your computer connected to the same wifi and in a navigator type http://172.20.10.11:8123

Then create your acccount on homeassistant and here we go.

## Configuration file of home assistant

Go to `cd /home/homeassistant/.homeassistant/` to find conf files
### Seek BLE modules with configuration.yaml

## Connect with ssh to home assistant
