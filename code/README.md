# Which to use?
* If you are using a GCCPCB 1.0, download the latest GCCPCB-vX.Y.ino release here https://github.com/Crane1195/GCCPCB/releases

* If you are using a GCCPCB 2.0, download the latest GCCPCB2-vX.Y.ino release here https://github.com/Crane1195/GCCPCB/releases

* If you are using a native USB Arduino like the Arduino Micro, download the latest NativeUSB-vX.Y.ino release here https://github.com/Crane1195/DIYB0XX/releases

* If you are using a non native USB Arduino like the Mega2560 or Nano, download the latest DIYB0XX-vX.Y.ino release here https://github.com/Crane1195/DIYB0XX/releases

* If you are using a Smashbox, download the latest DIYSmashB0XX-vX.Y.ino release here (this is the same as DIYB0XX-vX.Y.ino but it has the Smashbox pinout already filled in) https://github.com/Crane1195/DIYB0XX/releases


# Credits

This code currently utilizes Nicohood's Nintendo library : https://github.com/NicoHood/Nintendo

MHeironimus' Arduino Joystick Library : https://github.com/MHeironimus/ArduinoJoystickLibrary

dmadison's Nintendo Extension Controller Library : https://github.com/dmadison/NintendoExtensionCtrl

taker for suggestions regarding modifiers in the Smash Ultimate profile.

# Using my GCCPCB code

The GCCPCB supports PC and Gamecube control.

* To launch in Gamecube mode, just plug the controller in.
* To launch in PC mode, hold C-Down while plugging in.

## Nunchuk

The GCCPCB 1.0 supports the Nunchuk over the Nintendo extension controller port. To use a Nunchuk, plug it into the port before plugging in the controller. Currently I have confirmed it works in Melee on GC/Wii, Ultimate on Switch, and in PC mode. Some games will not work such as Mario Kart Double Dash on GC/Wii due to what I assume is a faster polling rate than the GCCPCB can support while using the Nunchuk library. 

## Game profiles

The GCCPCB supports Melee, Ultimate, and PM. In addition to holding C-Down (or not), two of these modes require a button input on plug in.

*  To launch in Melee mode, just plug in normally.
*  To launch in Smash4/Ultimate mode, hold B while plugging in.
*  To launch in Project M mode, hold X while plugging in.

For example, if you are playing PM on Dolphin with default settings, you would hold C-Down and X while plugging in. Melee on console, hold nothing. Ultimate on console, hold B. Melee on Dolphin, hold C-Down. Et cetera.

If you want to change the default mode, or the button inputs for the others, you can.

## SOCD (Simultaneous Opposite Cardinal Directions)

You can choose your SOCD method for each game profile, though I wouldn't change the Melee one for legality reasons.

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

## DPAD toggle button/switch
Normally the DPAD is enabled by holding Mod1 and Mod2 and pressing C-Up/down/left/right. If instead you would rather have a switch or a button do this, you can do so by attaching a button or switch to a free screw terminal. Let me know if you want help setting that up.
