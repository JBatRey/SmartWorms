#pragma once
#include "EventClass.h"
#include "TimeClass.h"
#include "GraphicClass.hpp"
#include "Worm.h"
#include <memory>
#include <vector>
using namespace std;

//Maximum allowed number of worms.
#define MAXWORMS 2

//Default values for width, height, FPS and display creation.
/**************************************************/
#define defaultDisplay true
#define defaultWidth 1920
#define defaultHeight 900
#define defaultFPS 50.0
/**************************************************/
class Simulation {
public:

	//Simulation constructor.
	Simulation(unsigned int width_ = defaultWidth, unsigned int height_ = defaultHeight, double FPS_ = defaultFPS,
		int wormCount_ = MAXWORMS);

	unique_ptr<GraphicClass> getGraphicControl(void);
	shared_ptr<TimeClass> getTimeControl(void);
	shared_ptr<EventClass> getEventControl(void);

	void setDefaultKeys(void);

	bool initializeAll(void);

	bool setSimulation(bool displayCreation = defaultDisplay);

	bool startMoving(int keyCode);

	void stopMoving(int keyCode);

	void refresh(void);

	bool dispatch(void);

	bool initializeWorms(void);

	~Simulation();

private:

	//Datos miembro de Simulation.
	unique_ptr<GraphicClass> graphicControl;
	shared_ptr<TimeClass> timeControl;
	shared_ptr<EventClass> eventControl;

	vector<Worm> wormVector;

	int wormCount;

	unsigned int width, height;
	double FPS;
};
