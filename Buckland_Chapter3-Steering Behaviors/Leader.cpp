#include "Leader.h"
#include "SteeringBehaviors.h"

class Vehicle;
class SteeringBehavior;

Leader::Leader(GameWorld* world,
	Vector2D position,
	double rotation,
	Vector2D velocity,
	double mass,
	double max_force,
	double max_speed,
	double max_turn_rate,
	double scale) : Vehicle(world, position, rotation, velocity, mass, max_force, max_speed, max_turn_rate, scale)
{
	Steering()->WanderOn();
	Steering()->WallAvoidanceOn();
	SetScale(Vector2D(10, 10));
}

void Leader::Update(double time_elapsed)
{
	if (m_bHumanControlChange != HumanControlled())
	{
		m_bHumanControlChange = HumanControlled();
		if (HumanControlled())
		{
			Steering()->WanderOff();
		}

		if (!HumanControlled())
		{
			Steering()->WanderOn();
		}
	}
	
	if (HumanControlled())
	{
		m_vVelocity = Vector2D(0.0f, 0.0f);

		if (GetKeyState('W') < 0)
		{
			m_vVelocity += Vector2D(0.0f, -30.0f);
		}
		if (GetKeyState('S') < 0)
		{
			m_vVelocity += Vector2D(0.0f, 30.0f);
		}
		if (GetKeyState('A') < 0)
		{
			m_vVelocity += Vector2D(-30.0f, 0.0f);
		}
		if (GetKeyState('D') < 0)
		{
			m_vVelocity += Vector2D(30.0f, 0.0f);
		}

	}

	Vehicle::Update(time_elapsed);
}