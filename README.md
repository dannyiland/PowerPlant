PowerPlant
==========

Watering my patio plants with a Solar Powered Arduino + Pump

I wrote this code the day beforeI left for an extended vacation. My wonderful neighbor refilled the 8L container every few days and watered the parts the soaker tube did not water well. 

![This photo was taken the day we got back!](http://i.imgur.com/HziK3qG.png)

Here's a Fritzing image of the circuit breadboarded out. The ? PCB is an INA219 breakout for monitoring the power consumption of the pump.

![The circuit](http://i.imgur.com/zYkL1aL.png)


This is a [10W solar panel]("http://www.amazon.com/gp/product/B007YT5XCA/ref=as_li_ss_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B007YT5XCA&linkCode=as2&tag=12vdcs-20) with a small [12V 7Ah Sealed Lead Acid Battery](http://www.amazon.com/gp/product/B003GXP10W/ref=as_li_ss_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B003GXP10W&linkCode=as2&tag=12vdcs-20). The only other electrical components are a [insanely cheap 99 cent shipped eBay charge controller](http://www.ebay.com/itm/10A-Solar-Charge-Controller-Regulator-12V-24V-Autoswitch-100W-Solar-Panel-10A-/111262571836?pt=LH_DefaultDomain_0&hash=item19e7c41d3c) and some male/female [barrel plugs](http://www.amazon.com/gp/product/B002QWNZHU/ref=as_li_ss_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B002QWNZHU&linkCode=as2&tag=12vdcs-20).

Note: The above links to Amazon products are affiliate links. Any income earned will fund future open source automated gardening projects!

The Arduino is powered from the solar panel's battery, through an [automotive phone charger ](http://www.amazon.com/gp/product/B0088U4YAG/ref=as_li_ss_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=B0088U4YAG&linkCode=as2&tag=12vdcs-20). It takes 12-24V and has a pair of 2.1A 5V USB ports.


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
