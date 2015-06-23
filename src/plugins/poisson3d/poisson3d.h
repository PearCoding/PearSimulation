#pragma once

#include "sims/isimulation.h"
#include "renderer/camera.h"

#include "actors/emptyactor.h"
#include "actors/grid.h"

#include "renderer/material.h"
#include "renderer/environment.h"

class ActorInteractor;
class Poisson3D : public ISimulation
{
public:
	Poisson3D();
	~Poisson3D();
	
	QString name() const
	{
		return "Poisson 3D";
	}

	int flags() const
	{
		return SF_None;
	}

	IInteractor* interactor();

	virtual void draw(Renderer *);
	virtual void resizeResources(int w, int h);
	virtual void initResources();
	virtual void cleanResources();

private:
	Camera mCamera;

	EmptyActor mRootActor;
	Grid mGrid;

	FloatDataGrid mDataGrid;
	StandardGradient mGradient;

	Material mMaterial;
	Material mContourMaterial;
	Environment mEnvironment;

	ActorInteractor* mInteractor;
};
