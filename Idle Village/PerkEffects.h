#pragma once
#include "Number.h"

class PerkEffects {
public:
	static Number getClickValue() { return clickValue; }
	static Number getfps() { return fps; }
	static Number getgps() { return gps; }
	

	static void updateValues(double x, int code) {
		if (code == 0) {
			clickUpdate(x);
		} else if (code == 1) {
			fpsUpdate(x);
		} else if (code == 2) {
			gpsUpdate(x);
		}
	}
	
protected:
	
	static Number clickValue;
	static Number fps;			//food per second
	static Number gps;			//gold per second

	static void clickUpdate(double x) { clickValue.changeByAmount(x); }
	static void fpsUpdate(double x) { fps.changeByAmount(x); }
	static void gpsUpdate(double x) { gps.changeByAmount(x); }
	
};