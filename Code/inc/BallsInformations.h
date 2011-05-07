/*
 * BallsInformations.h
 *
 *  Created on: 2011-01-07
 *      Author: artur.m
 */

#ifndef BALLSINFORMATIONS_H_
#define BALLSINFORMATIONS_H_

#include "Actor.h"

#include "pi.h"
#include "Vector.h"
#include "shared_ptr.h"

#include <string>
#include <vector>

class BallsInformations : public Actor
{
public:
	static const std::string TYPE;

	typedef const std::vector<Vector>& LocationsContainer;

	static shared_ptr<BallsInformations> spawn(const Vector& direction, float size, const Vector& position);
	virtual ~BallsInformations();

	LocationsContainer getLocations() const;

	virtual std::string getType() const;

private:
    BallsInformations(const Vector& direction, float size, const Vector& position);
    
	void preparePositions(float size, const Vector& direction);
    
private:
	std::vector<Vector>	m_locations;
};

#endif /* BALLSINFORMATIONS_H_ */
