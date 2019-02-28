# 3-OmniWheels-Rover-Platform
Summer research 2018-2019. Rover platform development for autonomous and multi agent system.

## Why am I doing this project?
```
Project Description:

Autonomous systems and multi-agent systems are broadly researched and applied in both academic and commercial fields. 
To test these systems and evaluate the performance, Unmanned Ground Vehicles (UGV) are commonly used as the experimental platform because it is easy to be operated and with fewer restrictions. 
UGVs is capable of being used for a variety of researches and applications, such as robotic systems, formation control algorithms and commercialise applications. 
However, most of the commercial products are limited by the diversity of motion types and the accuracy of movements while are used for academic experiments.  
Therefore, to research on developing new and improving existing autonomous systems, a suitable UGV platform is demanded, which should provide various freedom of movement being commanded by the system and detecting environmental data accurately.

This summer, we are introducing a project to develop a physical UGV platform for research purposes. 
The platform will be with three degrees of freedom, which means it is free to change position as surge (motion along y-axis), sway (motion along x-axis) and yaw (rotation on z-axis). 
The platform will also be implemented with sensors, which can detect information for navigation and feedback control. 
It will also be interfaced with popular modelling software tools, such as Matlab, Simulink and Labview.

on behalf of

Hong Gunn Chew
```

## Hardware setup:
1. Raspberry Pi for GUI, computer vision, communication with host computer.
2. Arduino Nano for sensors and integration.
3. Shield for driving motors.
4. Each omniwheel has 1 IMU sensor on it to detect the speed.

## Demonstration:
### Video of rover running:
https://www.youtube.com/watch?v=FaH9vIkFXlA
### Onboard GUI:
![alt text](https://github.com/vitsensei/3-OmniWheels-Rover-Platform/blob/master/images/Onboard%20GUI.png)
### Host computer GUI:
![alt text](https://github.com/vitsensei/3-OmniWheels-Rover-Platform/blob/master/images/GUI_host.png)
### Video of onboard GUI working with host computer GUI:
https://www.youtube.com/watch?v=7Ckd2ylmhWI
## Research paper that the rover's dynamic module based on:
https://www.researchgate.net/publication/256089847_Dynamical_Models_for_Omni-directional_Robots_with_3_and_4_Wheels

## My notes and comments:
1. All the files you need to replicate the platform should be in this GitHub master branch. Don't worry about the other branch beside the master. In each of those master branch, there is a readme file, it should help you to understand those files better.

2. The Protoneer Shield has the same architecture with the Arduino Nano. HOWEVER, the board is made for CNC machine, it does not mean for what we are using it for. **We need to use I2C communication on the board. You can find A4/SDA labeled on the board, A5/SCL is the Probe pin, you can also find it near the 12-36V terminal block.** Also, you have to use an USBtinyISP to upload any code to the Protoneer Shield.
Here is the protoneer shield: https://wiki.protoneer.co.nz/Raspberry_Pi_CNC
The protoneer use GRBL standard layout, which can be found here: https://github.com/grbl/grbl/wiki/Connecting-Grbl

3. The only reason I'm using another Nano plus the shield is because I found the shield is not fast enough to read the sensors (3 of them) AND driving 3 stepper motors AND do the calculation. The reason I'm not using RPI to get sensor data is because I want to use the library on Arduino, and also it helps with multi-tasking (i.e displaying real time data and sending data to host computer, it's a mess if you try to have RPI do anything that has to do with controlling the platform). Thus, RPI should only send the destination/command to the rover, and also do computer vision tasks (which I have not yet to include). That said, you are more than welcome to try.

4. The sensor data is very noisy, you have to run it through a Kalman Filter (or some other sort of filter). The one I'm using is not sensor fusion, future developers should make it sensor fusions. How? Idk.
Anyways, for those not very familiar with KF, here's the resource I learnt it from: 
  a. https://home.wlu.edu/~levys/kalman_tutorial/ (I learnt the theory here).
  b. https://scipy-cookbook.readthedocs.io/items/KalmanFiltering.html?highlight=kalman (I based my code here, it's in Python but I rewrite it in C, and make some modification).
  c. http://www.cs.unc.edu/~welch/media/pdf/kalman_intro.pdf (for those who are more math savy).
  
## Suggestion for future developers:
1. Redo the host computer GUI. Instead of using Matlab's, use Python instead and make an exact one like onboard GUI.
2. Look into how RPI and host computer are communicating and improve that.
3. Sensor fusion for better accuracy.

## If you have any question about:
1. Onboard GUI: Yiwei Sun
Email: a1673590@student.adelaide.edu.au

2. Host computer GUI: Azizul Hakim
Email: a1722261@student.adelaide.edu.au

3. Anything not GUI-related: Anh Tran, which is me. 
Email address: a1713568@student.adelaide.edu.au OR tranluuvietanh@gmail.com
