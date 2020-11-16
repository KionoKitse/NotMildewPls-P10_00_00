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
 * 2020-10-25 Prototyped the build on perfboard
 * 2020-10-30 Testing prototype some issues with on/off time
 * 2020-10-31 Prototype not responding at all seems to reboot when fan gets turned on
 * 2020-11-01 Trying to get the ATtiny85 to turn the fan on/off on breadboard no luck
 * 2020-11-08 Got the TIP120 working well with the ATtiny85 no obvious changes
 * 2020-11-08 Couldn't write to the Perfboard ATtiny85 after removal I was able to
 * 2020-11-08 Wrapped up the project
### Next Blog Post
2020-10-21 <font color="63C0EC"><b>P10_00_00 Boxing up the project</b></font>
Last time I posted, I mentioned that for some reason I the microprocessor would reboot every time I try to power on the fan. I tested it out with all new components on a breadboard and still had no luck. As odd whatever would have it now it's working. The exact same set up but I just re-uploaded the blink sketch and it seems to be chugging along perfectly. I did take a peek at it with the oscilloscope but didn't see anything unusual. Just a small drop in voltage when the fan is switched on but nothing that would be low enough to effect the ATtiny85. Maybe the fact that we were Mercury Retrograde and now it's Mercury Retroshade might have been the fix. Anyway I decided to try to burn the flash again on the prototype but it didn't work. Some error about the ATtiny85 not responding correctly. At this point though, I'm out of time for this project. Some of my plants are not doing great without the fan being there to strengthen the stems. Faced with that reality, I decided to just hardwire the fan in with the lighting electronics. So the fan will turn on and stay on while the grow lights are on. It's not quite what I wanted but it works. I'm thinking that I'll let this project go for now. There are some other projects that I would really like to do and even have a bit of a time limit on them. I'm planning on coming back to this project at some point. I'll redo the prototype on the breadboard and verify that the software is good before rebuilding. Still no answers on what was causing the original error...
<font color="63C0EC">Category:</font> Gardening
<font color="63C0EC">Tags:</font> ATtiny85, Arduino, Domotics, Engineering, Gardening, Home Automation, P10_00_00, Plants, Software
<a href="https://kionokitse.wordpress.com/notmildewpls/">Project Page</a> 

