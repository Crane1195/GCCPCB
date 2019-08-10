# Project+ Coordinate Analysis, and How the B0XX Can Function Within P+
## Forward

This document and these graphics were made to apply what is said and shown in the B0XX Melee Instruction Manual to Project+. The graphics shown here replicate the ones present in that manual, as does the order of them. Because of this, I highly recommend reading this alongside the coinciding second in the Melee manual. Each graphic will have the manuals section number beside it to aid in this. Here is a link to the Melee Manual :

https://drive.google.com/file/d/19N_qIS5ummLIFJF-00w72lxOuE3tHMqX/view

There are two reasons why I had to make these graphics and they are the differences between Melee and Project M's (now Project+) coordinate fields.
- The coordinate axes' range in Melee is -80 to 80, where in P+ the range is -100 to 100.
- Actions have different zones in P+ compared to Melee.

Since the range is -100 to 100, the proportion that is commonly used in Melee to express analog values will now conveniently align with how many pixels away from neutral the coordinate is.

### 3. The Coordinate Plain
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/1%20-%20The%20Coordinate%20Plane.png)
The dead zone for P+'s coordinate field is slightly larger than in Melee. Melee's dead zone is 44x44 pixels, where P+'s is 54x54.

### 3.1. Tilt and Smash
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/2%20-%20Tilt%20and%20Smash.png)
Notable differences are that P+'s tilt zone is square as apposed to Melee's rectangular zone, P+'s X-Tilt region is narrower, and P+'s Y-Tilt region is wider.

### 3.2. 50° Line
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/3%20-%2050%20degree%20line.png)
Just like in Melee, P+ abides by the 50° line rule. Coordinates above the 50 degree line perform up tilt/smash, and coordinates below the line perform angled forward tilt/smash.


![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/4%20-%2050%20Degree%20and%20Tilt%20and%20Smash.png)
Here is the previous graphic but with the tilt zone overlaid.

### 3.3. Special Moves
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/6%20-%20Grounded%20Special%20Moves.png)
These zones are slightly different compared to Melee, but not by much.
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/7%20-%20Airborne%20Special%20Moves.png)
As with Melee, the zones change when airborne.
### 3.4. Out-of-Shield Options
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/8%20-%20Out-of-Shield%20Options.png)
There are slight differences here compared to Melee for roll, tap jump, and spot dodge, but the biggest difference is the zone for shield drop. It is a pixel wider, and more importantly, it extends to the edges of the field. (0.70, -0.70), which is the exact diagonal, is a coordinate that can shield drop.
### N/A Tap Jump and Crouch
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/5%20-%20Tap%20Jump%20Crouch.png)
This is not a visual in the Melee Manual, but I want to bring it up before discussing modifiers, as it is important. In PM, when in the zone I marked "Buffer without Tap Jump", you can then transition to the Tap Jump zone without actually tap jumping. Any coordinate below .34 on the Y axis when transitioning to any coordinate above .68 on the Y axis will tap jump. If anyone has a better term then "Buffer without Tap Jump" to describe this, let me know and I will update the visual.

I also show the coordinates that are associated with crouching. These three zones will be heavily influencing the coordinates I chose for the B0XX modifiers.

## Analog Stick Behavior
### Un-Modified Inputs
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/9%20-%20Un-Modified%20Inputs.png)
These coordinates are the same as in Melee.
### Modifier X(1)
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/10%20-%20Modifier%20X%20part%201.png)

<p align="center">
  <br>
  <i>Horizontals:</i> X .70
  <br>
  <i>Verticals:</i> Y .60
  <br>
  <i>Quadrants:</i> X .70 Y .34
  <br><br>
</p>

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/10%20-%20Modifier%20X%20part%202.png)

### Modifier Y(2)
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/10%20-%20Modifier%20Y%20part%201.png)

![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/10%20-%20Modifier%20Y%20part%202.png)

### Firefox and Extended Up-B Angles
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/11%20-%20Firefox%20and%20Extended%20Up%20B%20Angles.png)

### Automatic Shield Tilt
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/12%20-%20Automatic%20Shield%20Tilt.png)

### Manual Shield Tilt
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/13%20-%20Manual%20Shield%20Tilt.png)

### Wavedash
![image](https://raw.githubusercontent.com/Crane1195/GCCPCB/master/Project%2B%20Coordinate%20Analysis/images/14%20-%20Wavedash.png)
