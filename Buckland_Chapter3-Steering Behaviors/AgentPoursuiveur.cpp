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
	m_vLeader = leader;
	m_vTarget = target;
	m_vOffset = offset;
	m_iNbreAgent = count;
	m_id = id; 
	
	Steering()->OffsetPursuitOn(m_vTarget, m_vOffset);//Must also use flocking to get distance between poursuiveur and change algorithm
	Steering()->WallAvoidanceOn();
	//SetScale(Vector2D(5, 5));
}

// --------------------------------dtor-----------------------------------
//------------------------------------------------------------------------
AgentPoursuiveur::~AgentPoursuiveur()
{
	//delete m_pSteering;//Must find what needs to be deleted
	//delete m_pHeadingSmoother;
}

//----------------------------- Update -----------------------------------
//------------------------------------------------------------------------
void AgentPoursuiveur::Update(double time_elapsed)
{
	//m_pSteering->OffsetPursuitOn(m_vTarget, m_vOffset);
	Vehicle::Update(time_elapsed);
}