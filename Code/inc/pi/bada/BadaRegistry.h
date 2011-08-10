/*
 * BadaRegistry.h
 *
 *  Created on: 2011-08-10
 *      Author: Artur
 */

#ifndef BADAREGISTRY_H_
#define BADAREGISTRY_H_

#include "GameRegistry.h"

class BadaRegistry : public GameRegistry
{
public:
	virtual bool hasKey(const std::string& key) const {return false;}
	virtual void eraseKey(const std::string& key) {}

	virtual void setInt(const std::string& key, int value) {}
	virtual void setDouble(const std::string& key, double value) {}
	virtual void setString(const std::string& key, const std::string& value) {}

	// Only if these functions return true the result is defined
	virtual bool getInt(const std::string& key, int& result) {return false;}
	virtual bool getDouble(const std::string& key, double& result) {return false;}
	virtual bool getString(const std::string& key, std::string& result) {return false;}
};

#endif /* BADAREGISTRY_H_ */
