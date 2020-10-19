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
### Next Blog Post
2020-10-19 <font color="63C0EC"><b>P10_00_00 NotMildewPls</b></font>
A while back I got into growing edible plants indoors inside of a miniature greenhouse. My last harvest had a pretty bad mildew problem that cause the house to smell pretty bad due to over watering with that Raindrop Bob <a href="https://kionokitse.wordpress.com/raindrop-bob/">project</a> and a lack of good airflow. This time I decided to get a small DC oscillating fan that I'm hoping will be able to clear out the excess humidity in the greenhouse. 
<img class="aligncenter size-full" src="https://kionokitse.files.wordpress.com/2020/10/p10_00c001.png" alt="p10_00_00c001">
I went with an oscillating fan because I didn't want to to have issue with too much wind hitting the plants at the same spot. Since the greenhouse is pretty small I don't need this fan to be on all the time. I could get a dedicated timer to manage this fan but I thought it could be simple to create an ATtiny85 based controller since I would basically only need to control the 4.75V DC power going to the fan. That means of course that I will have the inverter continuously running but I think that is a tradeoff that I'm willing to accept.
<font color="63C0EC">Category:</font> Gardening
<font color="63C0EC">Tags:</font> ATtiny85, Arduino, Domotics, Engineering, Gardening, Home Automation, P10_00_00, Plants, Software
<a href="https://kionokitse.wordpress.com/notmildewpls/">Project Page</a> 



