#ifndef FONTHELPER_H
#define FONTHELPER_H

#include "surface.h"

#include <string>
#include <vector>
#include <SDL_ttf.h>

#ifdef _WIN32
    typedef unsigned int uint;
#endif
using std::vector;
using std::string;

class FontHelper {
private:

	int height, halfHeight, fontSize;
	TTF_Font *font, *fontOutline;
	RGBAColor textColor, outlineColor;
	string fontName;

public:
	FontHelper(const string &fontName, int size, RGBAColor textColor = (RGBAColor){255,255,255}, RGBAColor outlineColor = (RGBAColor){5,5,5});
	~FontHelper();

	bool utf8Code(unsigned char c);

	void write(Surface *surface, const string &text, int x, int y, RGBAColor fgColor, RGBAColor bgColor);
	void write(Surface *surface, const string& text, int x, int y, const Uint8 align = HAlignLeft | VAlignTop);
	void write(Surface *surface, const string& text, int x, int y, const Uint8 align, RGBAColor fgColor, RGBAColor bgColor);

	void write(Surface *surface, vector<string> *text, int x, int y, const Uint8 align, RGBAColor fgColor, RGBAColor bgColor);
	void write(Surface *surface, vector<string> *text, int x, int y, const Uint8 align = HAlignLeft | VAlignTop);


	uint getLineWidth(const string &text);
	uint getTextWidth(const string &text);
	int getTextHeight(const string &text);
	uint getTextWidth(vector<string> *text);
	
	uint getHeight() { return height; };
	uint getHalfHeight() { return halfHeight; };

	void loadFont(const string &fontName, int fontSize);

	FontHelper *setSize(const int size);
	FontHelper *setColor(RGBAColor color);
	FontHelper *setOutlineColor(RGBAColor color);
};

#endif /* FONTHELPER_H */
