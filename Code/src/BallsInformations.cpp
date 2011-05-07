/*
 * BallsInformations.cpp
 *
 *  Created on: 2011-01-07
 *      Author: artur.m
 */

#include "BallsInformations.h"

#include "Board.h"

const std::string BallsInformations::TYPE("BallsInformations");

shared_ptr<BallsInformations> BallsInformations::spawn(const Vector& direction, float size, const Vector& position)
{
    return Actor::initialize(new BallsInformations(direction, size, position));
}

BallsInformations::BallsInformations(const Vector& direction, float size, const Vector& position) :
    Actor(position)
{
    setHidden(true);
	ignoreTrace(true);
	preparePositions(size, direction);
}

BallsInformations::~BallsInformations()
{

}

void BallsInformations::preparePositions(float size, const Vector& direction)
{
	float stepWidth = size / Board::CREATING_COUNT;
	Vector d = direction.getNormalized();
	for(int i = 0; i < Board::CREATING_COUNT; ++i)
	{
		m_locations.push_back(getPosition() + d * stepWidth * i);
	}
}

BallsInformations::LocationsContainer BallsInformations::getLocations() const
{
	return m_locations;
}

std::string BallsInformations::getType() const
{
	return TYPE;
}
