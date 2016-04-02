# Makefile
#
# Makefile for the Arduino USBJosystick project
#
# Author: Mike McCauley (mikem@airspayce.com)
# Copyright (C) 2011 Mike McCauley
# $Id: Makefile,v 1.2 2012/01/19 00:09:54 mikem Exp mikem $

PROJNAME = USBJoystick
# Dont forget to also change the version at the top of USBJoystick.h:
DISTFILE = $(PROJNAME)-1.2.zip

all:	doxygen dist upload

doxygen: 
	doxygen project.cfg

ci:
	(cd ..;ci -l `cat $(PROJNAME)/MANIFEST`)

dist:	
	(cd ..; zip $(PROJNAME)/$(DISTFILE) `cat $(PROJNAME)/MANIFEST`)

upload:
	rsync -avz $(DISTFILE) doc/ www.airspayce.com:public_html/mikem/arduino/$(PROJNAME)
