#include "stdafx.h"
#include "Goal.h"


Goal::Goal()
{
	relevance = 0.0f;
}

Goal::Goal(float r, string name_)
{
	if ((r >= 0) && (r <= 1))
		relevance = r;

	name = name_;
}

Goal::Goal(float r, NPC_Actor* t)
{
	if ((r >= 0) && (r<=1))
		relevance = r;
	target = t;
}

Goal::~Goal()
{
}

void Goal::SetGoal(Goal other)
{
	SetWSProperty(&other);
	relevance = other.relevance;
	target = other.target;
}

float Goal::CalculateRelevance()
{
	return relevance;
}

