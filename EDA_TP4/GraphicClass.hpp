#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <memory>
#include "Worm.h"
using namespace std;

#define MAXBITS 15
class GraphicClass {
public:

	//GraphicClass constructor.
	GraphicClass(unsigned int width_, unsigned int height_);

	void draw(const unique_ptr<Worm>& whichWorm);

	bool createBitmaps(void);

	bool loadBitmaps(void);

	bool createDisplay(void);

	ALLEGRO_DISPLAY*& getDisplay(void);

	void drawBackground(void);

	~GraphicClass();

private:

	ALLEGRO_BITMAP* moveBitmaps[MAXBITS];
	ALLEGRO_BITMAP* jumpBitmaps[MAXBITS];
	ALLEGRO_BITMAP* background;
	ALLEGRO_DISPLAY* display;
	unsigned int width, height;
};
