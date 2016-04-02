Simplest-Sound-Lightning-Trigger
================================

This is the simplest sound and lighting trigger for Arduino using only a piezo for sound and in case lightning, a photodiode.

The hardware consists of fairly large (an inch in diameter) piezo for sound sensor. How simple is it? Just connect one of the two terminal of piezo into A0 (or any other analog input, but you need to change code) and the other into ground. Someone has suggested a zener diode back to back, that is a good advice.

For lightning, use a photodiode. A BPW21R (yes expensive) sensor is used, I had to tune it down. Good tip is to find a photodiode with large sensing area. Simply connect the positive terminal of photodiode to A0 and the negative one to ground, that is.

A kit is available on eBay:

http://cgi.ebay.com/ws/eBayISAPI.dll?ViewItem&item=390543380949&ssPageName=STRK:MESE:IT

