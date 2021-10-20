#pragma once
#ifndef AGENT_POURSUIVEUR_H
#define AGENT_POURSUIVEUR_H

#include "SteeringBehaviors.h"
#include "Vehicle.h"
#include "2D/Vector2D.h"
#include <vector>
#include <list>
#include <string>

class GameWorld;
class SteeringBehavior;

class AgentPoursuiveur: public Vehicle
{
protected:
	bool m_bHumanControlChange = false;
	Vector2D m_vOffset;
	Vehicle* m_vLeader;
	Vehicle* m_vTarget;
	int m_iNbreAgent;
	int m_id;
public:
	AgentPoursuiveur(GameWorld* world,
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
		int count);
	//~AgentPoursuiveur();
	//updates the vehicle's position and orientation
	void Update(double time_elapsed);
};

#endif
