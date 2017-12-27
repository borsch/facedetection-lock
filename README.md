# Face Detection security app project - arduino lock

Face Detection security app consistі of 3 project: [Web project](https://github.com/borsch/facedetection-web), [Desktop app](https://github.com/borsch/facedetection-app), and this one

## Description
This part of project ask [web project](https://github.com/borsch/facedetection-web) whether person can enter or don't. If can than lock will be opened(LED start blink)

## Environment
Windows 7, Arduino IDE 1.8.5, NodeMCU V3 ESP8266 (CP2102)

## Installation
First of all we should install ESP8266 libraries into out Arduino IDE

In Arduino IDE: File -> Preferences -> Setting tab -> Additional Boards Manager URLs enter `https://github.com/esp8266/Arduino/releases/download/2.3.0/package_esp8266com_index.json` -> Click OK

In Arduino IDE: Tools -> Board -> Boards Manager -> In list search for `esp8266 by ESP8266 Community` -> Click to install it if it does not -> After install close the window

Open project in Arduino IDE. Before upload program to NodeMCU You should setup upload params. In Arduino IDE open Tools menu and set the following parameters:

&nbsp;&nbsp;&nbsp;`Board: NodeMCU 1.0(ESP-12E Module)` - if You can not find this value in the list, this means that you make something wrong during ESP8266 installation process

&nbsp;&nbsp;&nbsp;`CPU Frequency: 80MHz`

&nbsp;&nbsp;&nbsp;`Flash size: 4M(3M SPIFFS)`

&nbsp;&nbsp;&nbsp;`Upload speed: 115200`

&nbsp;&nbsp;&nbsp;`Port: (Select from list)` - This option will updated by IDE when You connect Your module via mini USB to PC

in the code manually set the WiFi network SSID and password. After this You can upload Your code to board.
Open `Tools -> Serial monitor` to see additional logs. Set baud speed to 115200 if You don't see any logs

**PS: installation process mostly duplicate [this tutorial](http://zlitos.com/publ/ehlektronika/arduino_i_t_p/nodemcu_upravlenie_4_rele_iz_prilozhenija_android_po_wifi/12-1-0-27)**

Connect LED: 

&nbsp;&nbsp;&nbsp;`-` on LED to `GND` on NodeMCU 

&nbsp;&nbsp;&nbsp;`+` on LED to `D1` on NodeMCU (actually this is GPIO5 in the code. `pinMode(5, OUTPUT)`)

For more info about NodeMCU pins looks [here](https://iotbytes.wordpress.com/nodemcu-pinout/)
