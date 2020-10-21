### Description  
P10_00_00 NotMildewPls
Automating a miniature oscillating DC fan for periodic operation.
 * ATtiny85 control of percent of time spent on
 * Adjustable manual control percent of time on
 * Display of current settings via LED
 * Embedded simple design and interface
 * Low power usage with sleep mode
 * Persistent settings
### Notes to user
 * Project documented at https://kionokitse.wordpress.com/notmildewpls/
 * In development
### What's next
 * Test EEPROM writing 
 * Test sleep mode
### Notebook
 * Nothing yet
### Progress log 
 * 2020-10-18 Project started
 * 2020-10-18 Testing on the ATtiny85
 * 2020-10-18 Test button debounce
 * 2020-10-18 Test blink output
 * 2020-10-18 Create menu
 * 2020-10-19 Creating documentation
 * 2020-10-19 Having difficulty with switching the fan on or off
 * 2020-10-20 Got the fan to switch properly with the TIP120
### Next Blog Post
2020-10-21 <font color="63C0EC"><b>P10_00_00 Transistor troubles</b></font>
A couple of days back I ran into an unexpected issue that turned into a wonderful learning experience. For this project I want to use a microcontroller to turn on or turn of a DC fan. I know enough to know that one cannot power a motor directly through a microcontroller pin since the motor will likely require much more current than the microcontroller is capable of putting out. I also knew that a transistor or a relay would be the correct method for switching the load. What I didn't know was how much I didn't know about transistors. I'm finding out that there is quite a lot about electronics that I don't know about and would really like to know more due to the <a href="https://kionokitse.wordpress.com/solar-hydrobeacon/">Solar HydroBeacon</a> project. I think when I have more time I'd like to take a proper electronics course since that seems to be where most of my issues are coming from. Anyway back to that transistor issue. I thought I understood how transistors worked because I had used them for simple low power switching applications but clearly I didn't. For my project I have a fan running 4.75V DC with the power inverter limiting the current to 400mA. In my mind basically one needs to have a setup that is similar to the one below. 
<img class="aligncenter size-full wp-image-196 " src="https://kionokitse.files.wordpress.com/2020/10/p10_00_00c002.png" alt="p10_00_00c002">
Basically the microcontroller needs to be able to apply a positive voltage to the transistor base to turn on the NPN transistor. How much positive? Well according to this <a href="https://learn.sparkfun.com/tutorials/transistors/operation-modes">sparkfun tutorial</a> the voltage at the base need to be higher than the voltage at the collector and the emitter. I also knew that the transistor needed to be sized to handle the collector voltage and current. I chose to work with the 2N2222 transistor. This states that it is able to take a max voltage of 40V and a max current of 600mA. 4.75V at 400mA? This shouldn't be an issue. I didn't quite understand why someone would need a resistor at the base but I assumed it was to limit the current going into the transistor, mostly because one needn't waste current. For my tests I would just experiment with different resistors and see which resistor size worked going from the largest to the smallest. What I found was that none of my resistors really worked. at 100 ohms I got it to partially switch but I still needed to give the fan a push to get it going. So I tried switching with no resistor. This resulted in a lot of heat in the transistor but the fan not really kicking on either and eventually burning out the transistor. Keep in mind it's 4am and I'm probably not thinking very well but I decided that maybe my issue was not enough supply voltage or current. So I stepped it up to a 9V battery and did the same tests eventually getting that magic smoke by connecting 9V directly to the base without a limiting resistor and still not getting it to switch. By 6:40am, a pile of smoldering transistors, and feeling like I don't know anything I decided to call it quits for the night. At this point I was feeling pretty bad about things since there is clearly something I don't understand. A small transistor is probably the right tool for the job but I'm not applying it correctly. Anyway over my lunch break I read a bunch and watched a few tutorials and learned quite a bit more about transistors. Transparently transistors are current controlled switches and applying a bunch of volts is clearly the wrong thing to do. Additionally not having a base resistor is definitely not the right thing. I found this video to be a great explanation for how transistors work and how to actually use them. I'm going to embed it since I think anyone who wants to know how to use a transistor should watch this video.
[youtube https://www.youtube.com/watch?v=8DMZSxS-xVc&amp;w=560&amp;h=315]
Armed with a better understanding of transistors and switching inductive loads I came back to the project. My first step was to verify the resistance across the fan, 4 ohms. Then check the current passing through the fan when in operation, 400mA. Based on these measurements and a 4.75V input I came up with a base resistor of 475ohms. <a href="https://www.petervis.com/GCSE_Design_and_Technology_Electronic_Products/transistor_base_resistor_calculator/transistor_base_resistor_calculator.html">Here</a> is a good online calculator for determining the optimal base resistance. I wired it up and gave it a try. It wasn't much different than the original results since I had already tried this before but I noticed that my multimeter was measuring 60mA of current being drawn from the source. Additionally it seemed that the transistor was on since it was getting ever so slightly warm. Although a little disappointing this did indicate to me that I was on the right path. It seems that the transistor was only partially on. Maybe if I supply more current it will fully turn on. I experimented with a few resistors but still kept getting 60mA of current from the source. I don't remember if I check the current at the base but at some point I started rummaging around in my parts bin to see if I had some MOSFETS. If a BJT won't work maybe a MOSFET will. Although I didn't find any MOSFETS I did find a small stash of TIP120 NPN Darlington pair transistors. Basically a Darlington pair can be used just like a BJT but it has a significantly higher gain. After plugging these values in and calculating a new base resistor based on the gain I wired it all up again and gave it a shot. This time it worked! I'm still not sure if it would have worked with another regular BJT transistor but I feel pretty confident that the 2N2222 in the setup I had wouldn't have worked. There is still quite a lot that I need to learn about transistors but I definitely learned a few new things.
<font color="63C0EC">Category:</font> Gardening
<font color="63C0EC">Tags:</font> ATtiny85, Arduino, Domotics, Engineering, Gardening, Home Automation, P10_00_00, Plants, Software
<a href="https://kionokitse.wordpress.com/notmildewpls/">Project Page</a> 


