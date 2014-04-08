/*
 * ColorLamp.h
 *
 * Copyright (c) 2011

 * Remco Magielse & Serge Offermans

 * Intelligent Lighting Institute (ILI), TU/e.
 *
 * All rights reserved. LAST UPDATE: 13-08-2012
*/

#ifndef RGB_h
#define RGB_h

#include "LED.h"

/* Constants to determine the colorFadeType */
static const uint8_t HSB_FADE 			= 0;
static const uint8_t RGB_FADE 			= 1;

/** The ColorLamp class is used to manage RGB LEDs with 3 channels (R,G and B) **/
class ColorLamp:public LED
{
  public:
	ColorLamp();
	ColorLamp( uint32_t channelRed, uint32_t channelGreen, uint32_t channelBlue, bool autoWrite = true, bool commonAnode = false, uint32_t x = 0, uint32_t y = 0 );
    ~ColorLamp();

	void setChannel( uint32_t channelRed, uint32_t channelGreen = 0, uint32_t channelBlue = 0);

	void update();

	void rgbTo( uint32_t r, uint32_t g, uint32_t b, uint32_t duration = DEFAULT_DURATION);
	void hsbTo( uint32_t h, uint32_t s, uint32_t b, uint32_t duration = DEFAULT_DURATION, bool shortcutThroughZero = true);

	void hueTo( uint32_t hTo,  		uint32_t duration = DEFAULT_DURATION, bool shortcutThroughZero = true);
	void saturationTo( uint32_t sTo, uint32_t duration = DEFAULT_DURATION);

	void setRGB( uint32_t r, uint32_t g, uint32_t b, bool stopAnimation = true );
	void setHSB( uint32_t h, uint32_t s, uint32_t b, bool stopAnimation = true );

	void setHue( uint32_t h , bool stopAnimation = true);
	void setSaturation( uint32_t s , bool stopAnimation = true);

	/* Implemented, but not yet functioning properly. Conversion through HSB goes wrong
	void redTo(uint8_t r,  	uint32_t duration = DEFAULT_DURATION);
	void greenTo(uint8_t g, uint32_t duration = DEFAULT_DURATION);
	void blueTo(uint8_t b,  uint32_t duration = DEFAULT_DURATION);

	void setRed(uint8_t r, bool stopAnimation = true);
	void setGreen(uint8_t g, bool stopAnimation = true);
	void setBlue(uint8_t b, bool stopAnimation = true);
	*/

	void setAnimationType( uint8_t animType = LINEAR, bool easeIn = true, bool easeOut = true );
	void setColorFadeType( uint8_t animType = HSB_FADE );
	void setCommonAnode( bool commonAnode = true);

	uint32_t getRed();
	uint32_t getGreen();
	uint32_t getBlue();

	uint32_t getHue();
	uint32_t getTargetHue();
	uint32_t getSaturation();
	uint32_t getTargetSaturation();
	uint32_t getBrightness();

    uint32_t getChannelRed();
	uint32_t getChannelGreen();
	uint32_t getChannelBlue();

	bool isAnimating();
	bool isAnimating(uint8_t param);

  private:
	/** hueAnim is the object that is used to manage the hue animations **/
	Animation * hueAnim;

	/** saturationAnim is the object that is used to manage the saturation animations **/
	Animation * saturationAnim;

	uint8_t _colorFadeType; // CURRENTLY UNUSED

	uint32_t _channelRed;
	uint32_t _channelGreen;
    uint32_t _channelBlue;

	uint32_t * rgbToHsb ( uint32_t r, uint32_t g, uint32_t b, uint32_t hsv[3] );
	uint32_t * hsbToRgb ( uint32_t h, uint32_t s, uint32_t b, uint32_t rgb[3] );

	uint32_t _red;
	uint32_t _green;
	uint32_t _blue;

	uint32_t _hue;
	uint32_t _saturation;
	uint32_t _brightness;

	bool _commonAnode;
};

#endif


