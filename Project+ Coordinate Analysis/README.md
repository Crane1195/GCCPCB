# Project+ Coordinate Analysis, and How the B0XX layout Can Function Within P+
## Forward

This document and these graphics were made to apply what is said and shown in the B0XX Melee Instruction Manual to Project+. The graphics shown here replicate the ones present in that manual, as does the order of them. Because of this, I highly recommend reading this alongside the matching section in the Melee manual. Each graphic will have the manuals section number beside it to aid in this.

Here is a link to the Melee Manual :

https://drive.google.com/file/d/19N_qIS5ummLIFJF-00w72lxOuE3tHMqX/view

There are two reasons why I had to make these graphics.
- The coordinate axes' range in Melee is -80 to 80, where in P+ the range is -100 to 100.
- Actions have different zones in P+ compared to Melee.

Since the range is -100 to 100, the proportion that is commonly used in Melee to express analog values will now conveniently align with how many pixels away from neutral the coordinate is.

## Testing Methodology

All the values in this document were acquired using Project+ v1.05b Netplay Hotfix [FM Edition]. The values selected for the B0XX also work as intended in PM Netplay v4, and on PM 3.6 on console, so I have no reason to believe the coordinate field has changed between any of these versions. If you happen to know any changes between the versions, feel free to let me know.

<br><h3 align="center"> 3. The Coordinate Plane </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/1%20-%20The%20Coordinate%20Plane.png)

The dead zone for P+'s coordinate field is slightly smaller than in Melee. Melee's dead zone is 22/80 (27.5%), where P+'s is 27/100 (27%).

<br><h3 align="center"> 3.1. Tilt and Smash </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/2%20-%20Tilt%20and%20Smash.png)

Notable differences are that P+'s tilt zone is square as apposed to Melee's rectangular zone, P+'s X-Tilt region is narrower, and P+'s Y-Tilt region is wider.

<br><h3 align="center"> 3.2. 50° Line </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/3%20-%2050%20degree%20line.png)

Just like in Melee, P+ abides by the 50° line rule. Coordinates above the 50 degree line perform up tilt/smash, and coordinates below the line perform angled forward tilt/smash.

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/4%20-%2050%20Degree%20and%20Tilt%20and%20Smash.png)

Here is the previous graphic but with the tilt zone overlaid.

<br><h3 align="center"> 3.3. Special Moves </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/6%20-%20Grounded%20Special%20Moves.png)

These zones are slightly different compared to Melee, but not by much.

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/7%20-%20Airborne%20Special%20Moves.png)

As with Melee, the zones change when airborne.

<br><h3 align="center"> 3.4. Out-of-Shield Options </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/8%20-%20Out-of-Shield%20Options.png)

There are slight differences here compared to Melee for roll, tap jump, and spot dodge, but the biggest difference is the zone for shield drop. It is barely wider at 4/100 (4%) compared to Melee's 3/80 (3.75%). What is more important though, is that it extends to the edges of the field. This means that the exact diagonal, (0.70, -0.70), is a coordinate that can shield drop.

<br><h3 align="center"> N/A Tap Jump and Crouch </h3>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/5%20-%20Tap%20Jump%20Crouch.png)

This is not a visual in the Melee Manual, but I want to bring it up before discussing modifiers, as it is important. In PM, when in the zone I marked "Buffer without Tap Jump", you can then transition to the Tap Jump zone without actually tap jumping. Any coordinate below .34 on the Y axis when transitioning to any coordinate above .68 on the Y axis will tap jump. If anyone has a better term then "Buffer without Tap Jump" to describe this, let me know and I will update the visual.

I also show the coordinates that are associated with crouching. These three zones will be heavily influencing the coordinates I chose for the B0XX modifiers.

<br><h2 align="center"> 4. Analog Stick Behavior </h2>
<h3 align="center"> 4.1 Un-Modified Inputs </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/9%20-%20Un-Modified%20Inputs.png)

These coordinates are the same as in Melee.

<br><h2 align="center"> 5. Modifier Buttons </h2>
<h3 align="center"> 5.1 Modifier X(1) </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/10%20-%20Modifier%20X%20part%201.png)

<p align="center">
  <br>
  <i>Horizontals:</i> X .70
  <br>
  <i>Verticals:</i> Y .60
  <br>
  <i>Quadrants:</i> X .70 Y .34
  <br>
</p>

- ModX + Horizontal : The fastest walk speed, and you do not fall off ledges or platforms at this speed. Allows for F tilts.
- ModX + Vertical : The pixel above crouch. It is one of 15 pixels that allow down special without falling through platforms. Allows for up tilts without tap jumping.
- ModX + Diagonal : The steepest angle that will not tap jump upon transitioning into the tap jump region. Allows for angled F tilts, and the 26 degree Firefox angle.

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/11%20-%20Down%20Special%20and%20Drop%20Through%20Platform.png)

This image shows the region in which down special will not drop you through a platform. It is 15/100 pixels (15%) as opposed to the 11/80 pixels (13.75%) in Melee. Whether or not one of these 15 coordinates is allowed is up for debate. The Melee mode's coordinate as of patch 2.0 is no longer within these 11 pixels, so perhaps the PM mode should match. 

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/12%20-%20Modifier%20X%20part%202.png)

This image shows the "Buffer without Tap Jump" zone, which forces us to have a steeper angle than Melee's 21.3 (this angle for Firefox will be shown later).

<br><h3 align="center"> 5.2 Modifier Y(2) </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/13%20-%20Modifier%20Y%20part%201.png)

<p align="center">
  <br>
  <i>Horizontals:</i> X .28
  <br>
  <i>Verticals:</i> Y .34
  <br>
  <i>Quadrants:</i> X .28 Y .58
  <br>
</p>

- ModY + Horizontal : The slowest walk speed. Allows for F tilts.
- ModY + Vertical : The point just inside the "Buffer without Tap Jump" zone I showed earlier. Allows for Up tilts without tap jumping. This value could be anywhere from .34 to .67 depending on whether it should be neutral/vertical special, whether or not it should crouch, and whether or not it should drop through platforms. This is up for debate. 
- ModY + Diagonal : The point that has the closest angle to the ModX + diagonal coordinate that was forced by the tap jump zones. Allows for Up tilts and turnaround Up tilts without tap jumping.

Since disabling tap jump is an option in the controller settings, I made it so none of the modifier coordinates can tap jump. This makes modifier Y much stronger than in Melee.

<br><h2 align="center"> 6. Additional Functionality </h2>
<h3 align="center"> 6.2 Firefox and Extended Up-B Angles </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/15%20-%20Firefox%20and%20Extended%20Up%20B%20Angles.png)

We are limited to making our diagonal + modifier angles at 26° and 64° to prevent tap jumping. This doesn't end up being an issue though for firefox angles since it is actually almost the same angle as ModX/Y + Diagonal + C-Left in Melee. Because of this, what I did was make ModX/Y + Diagonal + C-Down do the steepest allowed angles of 21.3° and 68.7°, and then kept the other angles the same. Just like with the B0XX Melee mode, all the angles are as evenly distributed as possible. The angles and inputs are as follows:

<p style="margin-left: 36.5%">
  <br>21.30° : ModX + Diagonal + C-Down
  <br>26.04° : ModX + Diagonal
  <br>30.78° : ModX + Diagonal + C-Left
  <br>35.52° : ModX + Diagonal + C-Up
  <br>40.26° : ModX + Diagonal + C-Right
  <br>45.00° : Diagonal
  <br>49.74° : ModY + Diagonal + C-Right
  <br>54.48° : ModY + Diagonal + C-Up
  <br>59.22° : ModY + Diagonal + C-Left
  <br>63.96° : ModY + Diagonal
  <br>68.70° : ModY + Diagonal + C-Down
</p>

Like in Melee, holding down L will give a coordinate that has the maximum magnitude closest to the angle.

<br><h2 align="center"> 7. Shield </h2>
<h3 align="center"> 7.1 Automatic Shield Tilt </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/16%20-%20Automatic%20Shield%20Tilt.png)

This works just like how it does in Melee, except that the quadrant coordinates are different.

<br><h3 align="center"> 7.2 Manual Shield Tilt </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/17%20-%20Manual%20Shield%20Tilt.png)

This has been nerfed in the Melee mode since the Melee manual was made. I currently have it set to be the middle of the shield tilt range, but this is subject to change.

<br><h2 align="center"> 8. Airdodge </h2>
<h3 align="center"> 8.1 Wavedash </h3><br>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/18%20-%20Wavedash.png)

Once again, this works like it does in Melee mode.

## Questions, Corrections, Contact, Conclusion
This page will stay up to date with the latest B0XX PM patch, and will eventually probably be replaced by the B0XX PM Instruction Manual.

Have any questions about my findings or graphics, or spot any mistakes? Feel free to PM me on Discord @Crane#1195, or ask me in my [GCCPCB discord](discord.gg/P2BxMVY), or in the [B0XX discord](discord.gg/6wcEaDU).
