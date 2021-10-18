#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Vehicle.h"


class Leader : public Vehicle 
{

protected:

	Vector2D GetVehiculeAcceleration();
	bool m_bHumanControlChange = false;

public:
	Leader(GameWorld* world,
		Vector2D position,
		double rotation,
		Vector2D velocity,
		double mass,
		double max_force,
		double max_speed,
		double max_turn_rate,
		double scale);


	void Update(double time_elapsed);
};

#endif

