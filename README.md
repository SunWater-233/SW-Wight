# SW-Wight

# Introduction

SW-Wight is a GUI library based on the vex v5 system and V5 API. I only spend 3 days on this project, so there must be some shortages in this project somewhere. I’m glad  to hear your suggestions. (〃'▽'〃)

The SW-Wight contains 4 wights now. They are **button**, **buttonGroup**, **Graph**, **Panel**. And detailed api is directly written in the corresponding header files for you to check it out(*^▽^*).

# Install

The installation is actually pretty simple. Here is something  you need to do.

1. Copy the folder called **SWWight** in **include** folder. And paste it in the **include** folder of **your project**.
    
    ![屏幕截图 2024-06-20 144044](https://github.com/SunWater-233/SW-Wight/assets/109706896/d4b75cc5-624d-4895-b21c-e96656f485cf)

    
2. Copy the folder called **SWWight** in **src** folder. And paste it in the **src** folder of **your project**.
    
   ![屏幕截图 2024-06-20 144227](https://github.com/SunWater-233/SW-Wight/assets/109706896/fee113bf-8194-44dc-973d-dda0a0e2d1c3)

    
    And then it should looks like this ↓
    
    ![屏幕截图 2024-06-20 144900](https://github.com/SunWater-233/SW-Wight/assets/109706896/1e1c7bb4-dcb8-4943-abc8-3ed0805f05b3)

    
3. Change the ***makefile.***
    
    Add the code below into makeflie to make the wight be able to be compiled.
    
    ```makefile
    # some adjusetment here to complie the project
    SRC_C += $(wildcard src/*/*/*.cpp)
    SRC_C += $(wildcard src/*/*/*.c)
    ```
    
    And then the makefile should look like this ↓
    ![屏幕截图 2024-06-20 145808](https://github.com/SunWater-233/SW-Wight/assets/109706896/dc9e3d60-04f1-4bca-ace2-5aa607a82b35)

4. Add some code in the **main.cpp**
    
    code:
    
    ```cpp
    #include "SWWight/SWWight.h"
    ........
    void pre_auton(void) {
      // Initializing Robot Configuration. DO NOT REMOVE!
      vexcodeInit();
      logic_runner();
      render_runner();
      // All activities that occur before the competition starts
      // Example: clearing encoders, setting servo positions, ...
    }
    ........
    ```
    
    And then it should look like this ↓
    
    ![屏幕截图 2024-06-20 150323](https://github.com/SunWater-233/SW-Wight/assets/109706896/a906d086-a886-4903-a3aa-0c229c99598d)

    
5. Try to compile it. If the compiler does not report an error, congratulation! (￣▽￣)~*  You just successfully install SW-Wight to your project.(´･ᴗ･`) If something goes wrong, you could check  **robot-config.h** and **robot-config.cpp**.Your Brain should be declared there.

# DEMO Explanation

It’s recommended to write SW-Wight code in a file called **LogicAndRender.cpp** in the SWWight folder. Here is a screenshot of the demo I wrote. Of course, you can find it in this github project.
If you want to **enable** this demo, replace the **"LogicAndRender.cpp"** with this file. 

![屏幕截图 2024-06-20 163320](https://github.com/SunWater-233/SW-Wight/assets/109706896/a7e7db0a-6e16-4526-9cc5-453032d1eef9)
![屏幕截图 2024-06-20 163329](https://github.com/SunWater-233/SW-Wight/assets/109706896/9a7e3840-6645-463d-8c68-2d665cd8d053)


The picture below is a screenshot of the demo. You could see there are 3 wights in the photo.

 

| Name in the photo | Wight Type | Name in code |
| --- | --- | --- |
| A | panel | TestPanel |
| B | graph | TestGraph |
| C | button | TestButtonGroup |

| Name in the photo | Wight Type | Name in code |
| --- | --- | --- |
| C1 | button | TestButton |
| C2 | button | TestButton_1 |
| C3 | button | TestButton_2 |

![BrainEdited](https://github.com/SunWater-233/SW-Wight/assets/109706896/97d157a6-cbeb-42ac-a0d8-2bbcf2986a4f)


## Panel’s Functions

The Panel A records the present motor velocity(unit is pct).

## Graph's Functions

The Graph B records the present motor velocity(unit is rpm).

## Buttons’ Functions

If you press C1, the motor called *TestMotor*  will spin at 25% of power.

If you press C2 or C3, the buttons you selected will be selected.

If C2 is selected, *TestMotor*  will spin at 50% of power.

If C3 is selected, *TestMotor*  will spin at 75% of power.

If C2 and C3 are both selected, *TestMotor*  will spin at 100% of power.

However, if there is **no button pressed or selected**, the motor will stop.

# Something About SWWColor

Some of you might have found there is built-in colors in the SW-Wight.

In the **SWWTool.h**, a class called ***SWWHexColor*** includes these colors.

And I actually grab these colors from [🎨 Flat UI Palette v1 | Flat UI Colors 🎨 280 handpicked colors ready for COPY & PASTE](https://flatuicolors.com/palette/defo)
