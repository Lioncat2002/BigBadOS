#pragma once
#include "../machine/cgascr.h"
#include <cstdint>

class DirectDraw{
private:
	FB_Screen screen;
public:
	DirectDraw()=default;
	DirectDraw(DirectDraw &copy) = delete; // prevent copying
	DirectDraw& operator=(const DirectDraw&) = delete; // prevent assignment
	void init(MultibootInfo *mbi){
		screen.init(mbi);
	}

	void put_pixel(int x,int y, uint32_t color);
	void fill_rect(int x,int y, uint32_t color);
};