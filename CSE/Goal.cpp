#include "stdafx.h"
#include "Goal.h"


Goal::Goal()
{
	Relevance = 0.0f;
}

Goal::Goal(float r)
{
	if ((r >= 0) && (r <= 1))
		Relevance = r;
}

Goal::Goal(float r, NPC_Actor* t)
{
	if ((r >= 0) && (r<=1))
		Relevance = r;
	target = t;
}

Goal::~Goal()
{
}

void Goal::SetGoal(Goal other)
{
	SetWSProperty(&other);
	Relevance = other.Relevance;
	target = other.target;
}

float Goal::CalculateRelevance()
{
	return Relevance;
}

