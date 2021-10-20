#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Vehicle.h"


class Leader : public Vehicle 
{

protected:

	bool m_bHumanControlChange = false;
	double      vitesse_humain = 50.0f;

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

