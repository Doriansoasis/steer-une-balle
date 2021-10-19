#include "AgentPoursuiveur.h"

//------------------------------- ctor -----------------------------------
//------------------------------------------------------------------------
AgentPoursuiveur::AgentPoursuiveur(GameWorld* world,
	Vector2D position,
	double rotation,
	Vector2D velocity,
	double mass,
	double max_force,
	double max_speed,
	double max_turn_rate,
	double scale,
	Vehicle* leader,
	Vehicle* target,
	Vector2D offset,
	int id,
	int count): Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale) 
{
	m_pSteering->OffsetPursuitOn(leader, offset);//Must also use flocking to get distance between poursuiveur
	m_pSteering->WallAvoidanceOn();
	SetScale(Vector2D(10, 10));
}

// --------------------------------dtor-----------------------------------
//------------------------------------------------------------------------
AgentPoursuiveur::~AgentPoursuiveur()
{
	delete m_pSteering;//Must fint what needs to be deleted
	delete m_pHeadingSmoother;
}

//----------------------------- Update -----------------------------------
//------------------------------------------------------------------------
void AgentPoursuiveur::Update(double time_elapsed)
{
	/*if (m_bPaused) return;

	//create a smoother to smooth the framerate
	const int SampleRate = 10;
	static Smoother<double> FrameRateSmoother(SampleRate, 0.0);

	m_dAvFrameTime = FrameRateSmoother.Update(time_elapsed);


	//update the vehicles
	for (unsigned int a = 0; a < m_Vehicles.size(); ++a)
	{
		m_Vehicles[a]->Update(time_elapsed);
	}*/
}