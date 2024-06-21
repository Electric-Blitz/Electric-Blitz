#ifndef _COLORS_H_
#define _COLORS_H_
#pragma once

class Colors
{
private:
	enum ColorOptions
	{
		Pink = 1,	//0D
		Red = 2,	//04
		Purple = 3,	//05
		LgtBlue = 4,//09
		Yellow = 5,	//0E
		Orange = 6,	//0C
		DrkBlue = 7,//01
		Green = 8,	//0A
		Default = 9	//07
	};
	ColorOptions color;
	void SetColor(ColorOptions color);

public:
	void ColorChange();
};

#endif
