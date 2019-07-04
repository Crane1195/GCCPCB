# DISCLAIMER
This is only guaranteed to work on my GCCPCB. It should be usable on any Arduino Leonardo, Micro, or Pro Micro, and probably on other 32u4 based boards as well, but do so at your own risk. I have similar code here: https://github.com/Crane1195/DIYB0XX/tree/master/code if you are making a DIY using any other Arduino.


# Credits

This code currently utilizes Nicohood's Nintendo library : https://github.com/NicoHood/Nintendo

MHeironimus' Arduino Joystick Library : https://github.com/MHeironimus/ArduinoJoystickLibrary

dmadison's Nintendo Extension Controller Library : https://github.com/dmadison/NintendoExtensionCtrl

taker for suggestions regarding modifiers in the Smash Ultimate profile.

As of July 4th 2019 : I rewrote the entire program to increase efficiency, increase readability, to make adding new profiles easier, to improve the Smash Ultimate mode, and to add Nunchuk functionality.

I plan on implementing the Wii Classic Controller and NES/SNES mini controllers, and automatic mode switching depending on if you plug into a Gamecube/Wii, Gamecube to USB adapter, or PC.

# Using my GCCPCB code

The GCCPCB supports PC and Gamecube control.

* To launch in Gamecube mode, just plug the controller in.
* To launch in PC mode, hold C-Down while plugging in.

If you would like to swap these:

Change line 74 from `device currentDevice = GC;` to `device currentDevice = PC;`

Change line 134 from `currentDevice = PC;` to `currentDevice = GC;`

If you would like to change the button from C-Down to something else:

Change line 132 from `if (digitalRead(CDOWN) == LOW` to `if (digitalRead(???) == LOW` where ??? is your choice. See the lines above 101 for the buttons names.

## Game profiles

 The GCCPCB supports Melee, Ultimate, and PM. In addition to holding C-Down (or not), two of these modes require a button input on plug in.

 *  To launch in Melee mode, just plug in normally.
 *  To launch in Smash4/Ultimate mode, hold B while plugging in.
 *  To launch in Project M mode, hold X while plugging in.

 For example, if you are playing PM on Dolphin with default settings, you would hold C-Down and X while plugging in. Melee on console, hold nothing. Ultimate on console, hold B. Melee on Dolphin, hold C-Down. Et cetera.

 If you want to change the default mode, or the button inputs for the others, you can.

 Line 73 determines the profile when nothing is held. `game currentGame = Melee;`

 Line 145 determines the profile when B is held. `game currentGame = Ultimate;`

 Line 150 determines the profile when X is held. `game currentGame = PM;`

 Line 143 determines the button to hold for the second profile `if (digitalRead(B) == LOW)`

 Line 148 determines the button to hold for the third profile `if (digitalRead(X) == LOW)`

 Change these if you would prefer different settings.

## SOCD (Simultaneous Opposite Cardinal Directions)

You can choose your SOCD method for each game profile.

To do so, change the value to the right of the equal sign on line 73 for the mode that starts with no input, 146 for the mode that starts with B in my case, and 151 for the mode that starts with X in my case to Neutral, TwoIP, or TwoIPNoReactivate. I do not advise changing these though, as the default settings are the most fair.

Here is a rundown of what each SOCD method means:

#### 2ip works like this:
* Press left. Character moves left.
* While still pressing left, press right. Character moves right.
* While still pressing left, stop pressing right. Character moves left again.

#### 2ip with no reactivation (The method the B0XX uses) works like this:
* Press left. Character moves left.
* While still pressing left, press right. Character moves right.
* While still pressing left, stop pressing right. Character will not move.

#### Neutral works like this:
* Press left. Character moves left.
* While still pressing left, press right. Character stops moving.
* While still pressing left, stop pressing right. Character moves left again.

# Installing My GCCPCB Code

The code I run on my GCCPCB's currently utilizes Nicohood's Nintendo library found here :

https://github.com/NicoHood/Nintendo

and MHeironimus' Arduino Joystick Library found here :

https://github.com/MHeironimus/ArduinoJoystickLibrary

and dmadison's Nintendo Extension Controller Library found here :

https://github.com/dmadison/NintendoExtensionCtrl

Press Clone or download, and press Download ZIP on both of these repos. The Nintendo library and the Extension controller library are in the form they need to be in, but the joystick library is not.

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

Navigate to where you have the GCCPCB-XX folder, and double click one, then repeat the process for the others. You will only need to install these libraries and the Arduino IDE once. For future updates, you will just have to download the new code, and upload it using the method below.

![image](https://i.imgur.com/Bc7xqCz.png)

In this menu, change the board to be Arduino/Genuino Micro.

![image](https://i.imgur.com/IPdVq6B.png)

Before plugging in the GCCPCB, look and see what Ports are there. On this machine, there were none, but on my other machine, I had a couple already.

![image](https://i.imgur.com/GjqfGvJ.png)

Plug in the board via USB, and check this menu again, you should see another COM port show up. For both of my computers, it will also say "Arduino/Genuino Micro", but it is possible it will not. What should always happen though, is a port should show up when you plug in the board, and should disappear when you unplug the board (make sure you close the menu and reopen it to refresh the list). This port is the port for the GCCPCB. Select it.

![image](https://i.imgur.com/u16W9HK.png)

If you are not using a Brook Board, you are ready to upload to the board. Click this button to do so.

![image](https://i.imgur.com/CY3OeIv.png)

This section of the IDE will say Compiling Sketch, then Uploading, then Done Uploading. When it says Done Uploading, the board is ready to use, and can be unplugged.

![image](https://i.imgur.com/8f7lK0G.png)

If you are using a Brook Board, and are not using the default layout shown here (Brook A corresponds to the B screw terminal on my board, etc), you will have to edit the pinout in the code.

![image](https://i.imgur.com/2Sreh0V.png)

This chart details which Arduino pin corresponds to which GCCPCB screw terminal which corresponds to what Brook Board input. Insert the button wires of the buttons you want to use for the Brook board into the terminal that matches the input.

![image](https://i.imgur.com/SL0nwQw.png)

Look for these lines. Their line numbers may not be the same, but it is near the top of the file. These values are the Arduino pins that correspond to the screw terminals on the board.

For an example: Lets say you want your Brook RB/LB to be in the traditional fighting game location, with an 8 button layout. What you would do, is plug your LB button into the screw terminal for A, and the RB button into the screw terminal for C-L. Then, you would plug your Gamecube controller A/C-L buttons into E1/E2 (Extra 1 and Extra 2). You would then change these numbers in the code.

```
const int A = XX      : XX would now be 11
const int CLEFT = XX  : XX would now be 10
const int EXTRA1 = XX : XX would now be 15
const int EXTRA2 = XX : XX would now be 9
```
If you have any problems with this, or need assistance setting up the button mapping, feel free to message me on Discord @Crane#1195 .

## Contact
If you have any questions or need any assistance in this process, feel free to message me on Discord @Crane#1195
