# Security-System Using Arduino

The security system is used to monitor a door or window and would determine, whether the door/window is closed or opened by using laser sensor. In order to alter the states, a pin must be entered using a number pad. Additionally, there is a display which shows the current state of the door/window.

1.FUNCTIONAL REQUIREMENTS

1.1	Summary of Functions
The Security System requires a embedded system based solution for a program whose primary functions are to:  
•	Monitor a door or window  
•	Determine the opened/closed state of the system  
•	Take necessary steps in both opened/closed state  

1.2	Functional Requirements  
In order to accomplish the above articulated needs, the Security System requires the following functionality:  

1.2.1 Status Management  
  •	Indication of the current state of the door/window  
  •	Ability to switch between states “open” and “closed”  

1.2.2 Alarm System Management  
  •	Indication of the current state of the alarm system   
  •	Ability to control the alarm system by using passwords  
  •	Make alarm sound while someone trying to break into the door/window in “closed” state  
 

2.NON-FUNCTIONAL REQUIREMENTS

2.1 System Security  
  •	The embedded system hardware design should fulfil the needs of system safety    
  •	Use of sustainable hardware components   
  •	Safe power supply for the system  
  •	Safe operation in components and wire connection  

2.2 The software programming should fulfil the need of system safety  
  •	Data encryption when using password function  
  •	Reliable coding to ensure the functionality of the system  

2.3 System Complexity  
  •	Reducing of the total number of wires/components when possible  
  •	Optimization of the system by using different components  


3.DETAILED EXPLANATION OF THE DESIGN

•	Keypad & LCD1602: used for entering password in order to change between “opened” and “closed” states  
•	Speaker: make alarm sound when moving objects passing through under “opened” state  
•	Light sensor & Laser emmitter: detect moving objects passing through   


4.HARDWARE REQUIREMENTS 	  

•	LCD Display   
•	Number keypad   
•	Breadboard  
•	Arduino Uno  
• Speaker  
•	Wires  
•	Light sensor  
•	Laser emitter   
•	Resistor

