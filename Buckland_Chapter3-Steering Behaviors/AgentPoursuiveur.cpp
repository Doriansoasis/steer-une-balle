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
	Steering()->OffsetPursuitOn(target, offset);//Must also use flocking to get distance between poursuiveur
	Steering()->WallAvoidanceOn();
	Steering()->ObstacleAvoidanceOn();
	SetScale(Vector2D(2*scale, 2*scale));
	m_vLeader = leader;
	m_vTarget = target;
	m_vOffset = offset;
	m_iNbreAgent = count;
	m_id = id;

}

void AgentPoursuiveur::Update(double time_elapsed)
{
	if (m_bHumanControlChange != HumanControlled())
	{
		m_bHumanControlChange = HumanControlled();
		if (HumanControlled())
		{
			double radius = 70.0f;
			double calculatedAngle = (TwoPi/ m_iNbreAgent)* m_id;
			double xOffset = radius * cos(calculatedAngle);
			double yOffset = radius * sin(calculatedAngle);
			Steering()->OffsetPursuitOn(m_vLeader, Vector2D(xOffset, yOffset));
		}
		else
		{
			Steering()->OffsetPursuitOn(m_vTarget, m_vOffset);
		}
	}
	Vehicle::Update(time_elapsed);
}

