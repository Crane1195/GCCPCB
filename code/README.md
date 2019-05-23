# Installing My GCCPCB Code

The code I run on my GCCPCB's currently utilizes Nicohood's Nintendo library found here :

https://github.com/NicoHood/Nintendo

and MHeironimus' Arduino Joystick Library found here :

https://github.com/MHeironimus/ArduinoJoystickLibrary

Press Clone or download, and press Download ZIP on both of these repos. The Nintendo library is in the form it needs to be in, but the joystick library is not.

![image](https://i.imgur.com/qxkgcJC.png)

Extract the Joystick folder out of the ArduinoJoystickLibrary-master ZIP file, and then ZIP the Joystick folder. You should have a Joystick.zip file, that contains the Joystick folder, that contains a src folder, an examples folder, and a file named library.properties.

Download my repo as well, and extract the folder code/GCCPCB-XX (XX will depend on the version). Place the newly created Joystick.zip file, as well as the Nintendo-master.zip file in this folder

![image](https://i.imgur.com/GfxKsp1.png)

Your folder should look like this.

Another thing you will need is the Arduino IDE, which is found here : 

https://www.arduino.cc/en/Main/Software

![image](https://i.imgur.com/lZlK5E5.png)

After installing the Arduino IDE, open GCCPCB-XX.ino, and add the libraries using this menu option.

![image](https://i.imgur.com/S65sGQo.png)

Navigate to where you have the GCCPCB-XX folder, and double click one, then repeat the process for the other.

![image](https://i.imgur.com/Bc7xqCz.png)

In this menu, change the board to be Arduino/Genuino Micro.

![image](https://i.imgur.com/IPdVq6B.png)

Before plugging in the GCCPCB, look and see what Ports are there. On this machine, there were none, but on my other machine, I had a couple already.

![image](https://i.imgur.com/GjqfGvJ.png)

Plug in the board via USB, and check this menu again, you should see another COM port show up. For both of my computers, it will also say "Arduino/Genuino Micro", but it is possible it will not. What should always happen though, is a port should show up when you plug in the board, and should disappear when you unplug the board (make sure you close the menu and reopen it to refresh the list). This port is the port for the GCCPCB. Select it.

Finishing this soon.
