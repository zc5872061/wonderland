/*
 * iOSFile.h
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */
#ifndef _IOS_FILE_H_
#define _IOS_FILE_H_

#include "GameFile.h"

#include <vector>
#include <fstream>

class iOSFile : public GameFile
{
public:
    iOSFile(const std::string& filename, const std::string& mode = "r");
    ~iOSFile();
    
    std::string readLine();
    std::string read(); //reads whole file
	bool eof();
    
private:
    std::fstream m_f;
};

#endif // _IOS_FILE_H_