/*
 * GameRegistry.h
 *
 *  Created on: 2011-08-10
 *      Author: Artur
 */

#ifndef GAMEREGISTRY_H_
#define GAMEREGISTRY_H_

#include <string>

#include "shared_ptr.h"

class GameRegistry
{
public:
	static shared_ptr<GameRegistry> createRegistry();
	virtual ~GameRegistry() {}

	virtual bool hasKey(const std::string& key) const = 0;
	virtual void eraseKey(const std::string& key) = 0;

	// Yes, could have overloaded, but experience shows that in classes like this
	// it would cause annoying compiler errors like ambigous in some cases.
	// Just remind yourself all the problems when trying to call pow.
	//
	// Yes, this will cause Copy-Pastes, but these are simple copy-pastes that will never
	// ever be maintained and it makes using the registry easier in the long time.
	virtual void setInt(const std::string& key, int value) = 0;
	virtual void setDouble(const std::string& key, double value) = 0;
	virtual void setString(const std::string& key, const std::string& value) = 0;

	// Only if these functions return true the result is defined
	virtual bool getInt(const std::string& key, int& result) = 0;
	virtual bool getDouble(const std::string& key, double& result) = 0;
	virtual bool getString(const std::string& key, std::string& result) = 0;

	// These are not abstract because they use what we already have
	// Will return the def value if anything fails
	virtual int getIntDef(const std::string& key, int def);
	virtual double getDoubleDef(const std::string& key, double def);
	virtual std::string getStringDef(const std::string& key, const std::string& def);
};

#endif /* GAMEREGISTRY_H_ */
