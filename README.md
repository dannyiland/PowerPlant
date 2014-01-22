PowerPlant
==========

Watering my patio plants with a Solar Powered Arduino + Pump

I wrote this code the day beforeI left for an extended vacation. My wonderful neighbor refilled the 8L container every few days and watered the parts the soaker tube did not water well. 

![This photo was taken the day we got back!](http://i.imgur.com/HziK3qG.png)

Here's a Fritzing image of the circuit breadboarded out. The ? PCB is an INA219 breakout for monitoring the power consumption of the pump.

![The circuit](http://i.imgur.com/zYkL1aL.png)


This is a 10W solar panel with a small Sealed Lead Acid Battery.

The Arduino is powered from the solar panel's battery, through a 12V->5V regulator which provides 2 USB ports from a lead acid battery.


Components
=================

* Rectifier Diode 1N4001
* 12V aquarium Pump (Motor on diagram)
* Arduino
* Male + Female Power plugs for pump. Pass-through ports for power. I found a pump that takes's my SLA's unregulated 12V DC.
* TIP120	NPN-Power transistor to switch the pump on and off
* 4k Ω Resistor
* $2 RTC Module DS1302 from eBay
* INA219 for current monitoring.
