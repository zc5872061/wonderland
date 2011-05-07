/*
 * StringHelper.h
 *
 *  Created on: 2011-02-26
 *      Author: Artur
 */

#ifndef STRINGHELPER_H_
#define STRINGHELPER_H_

#include <string>
#include <vector>

// All string methods here should be named like in python and work like in python
namespace StringHelper
{

    std::string strip(const std::string& text, const std::string& stripChar = " ");
    void tokenize(const std::string& source, std::vector<std::string>& result, const std::string& tokens = " ");
    std::vector<std::string> tokenize(const std::string& source, const std::string& tokens = " ");

}

#endif /* STRINGHELPER_H_ */
