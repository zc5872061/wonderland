/*
 * BadaRegistry.cpp
 *
 *  Created on: 2011-08-11
 *      Author: Artur
 */
#include "pi/bada/BadaRegistry.h"

#include <FBase.h>

#include "pi/bada/BadaUtil.h"

using namespace Osp::App;
using namespace Osp::Base;

BadaRegistry::BadaRegistry() : m_appRegistry(0)
{
	m_appRegistry = Application::GetInstance()->GetAppRegistry();
}

bool BadaRegistry::hasKey(const std::string& key) const
{
	String s;
	result r = m_appRegistry->Get(key.c_str(), s);

	if(r == E_KEY_NOT_FOUND)
	{
		return false;
	}
	else
	{
		return false;
	}
}

void BadaRegistry::eraseKey(const std::string& key)
{
	m_appRegistry->Remove(key.c_str());
}

void BadaRegistry::setInt(const std::string& key, int value)
{
	if(hasKey(key))
	{
		m_appRegistry->Set(key.c_str(), value);
	}
	else
	{
		m_appRegistry->Add(key.c_str(), value);
	}
}

void BadaRegistry::setDouble(const std::string& key, double value)
{
	if(hasKey(key))
	{
		m_appRegistry->Set(key.c_str(), value);
	}
	else
	{
		m_appRegistry->Add(key.c_str(), value);
	}
}

void BadaRegistry::setString(const std::string& key, const std::string& value)
{
	if(hasKey(key))
	{
		m_appRegistry->Set(key.c_str(), value.c_str());
	}
	else
	{
		m_appRegistry->Add(key.c_str(), value.c_str());
	}
}

bool BadaRegistry::getInt(const std::string& key, int& res)
{
	if(!hasKey(key))
	{
		return false;
	}

	result r = m_appRegistry->Get(key.c_str(), res);
	if(r != E_SUCCESS)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BadaRegistry::getDouble(const std::string& key, double& res)
{
	if(!hasKey(key))
	{
		return false;
	}

	result r = m_appRegistry->Get(key.c_str(), res);
	if(r != E_SUCCESS)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BadaRegistry::getString(const std::string& key, std::string& res)
{
	if(!hasKey(key))
	{
		return false;
	}

	String s;
	result r = m_appRegistry->Get(key.c_str(), s);
	if(r != E_SUCCESS)
	{
		return false;
	}
	else
	{
		res = toString(s);
		return true;
	}
}
