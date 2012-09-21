#ifndef STEROETRODE_PLOT_H_
#define STEROETRODE_PLOT_H_

#if defined(__linux__)
	#include <GL/glut.h>
#else
	#include <GLUT/glut.h>
#endif
#include <list>
#include <math.h>

#include "WaveAxes.h"
#include "ProjectionAxes.h"
#include "BaseUIElement.h"
#include "PlotUtils.h"
#include "SimpleKeyEvent.h"


class StereotrodePlot : public BaseUIElement{
	
	bool enabled;	
    
    bool limitsChanged;

    static const int MAX_N_CHAN = 4;
    static const int nChannel = 2;
    static const int nWaveAx = 2;
    static const int nProjAx = 1;
    double limits[MAX_N_CHAN][2];

    WaveAxes wAxes[nWaveAx];
    ProjectionAxes pAxes[nProjAx];
    
    
    
    // void zoomAxes(int n, bool xdim, int zoomval);
    // void zoomProjection (int n, bool xdim, int zoomval);
    // void zoomWaveform (int n, bool xdim, int zoomval);
    
    // void panAxes(int n, bool xdim, int panval);
    // void panProjection (int n, bool xdim, int panval);
    // void panWaveform(int n, bool xdim, int panval);
    
    void initLimits();
    void setLimitsOnAxes();
    void updateAxesPositions();

	
public:
	StereotrodePlot();
	StereotrodePlot(int x, int y,int w,int h);
	virtual ~StereotrodePlot();

	void initAxes();
	void redraw();

	void setEnabled(bool enabled);
	bool getEnabled();
	void setPosition(int,int,double,double);
    
	void getPreferredDimensions(double*, double*);

	int getNumberOfAxes();
    
    void mouseDown(int x, int y);
    
    void mouseDragX(int dx, bool shift, bool ctr);
    void mouseDragY(int dy, bool shift, bool ctr);

    bool processKeyEvent(SimpleKeyEvent k);

    void processSpikeObject(SpikeObject s);

    void clear();
    void zoom(int, bool);
    void pan(int, bool);
};



#endif
