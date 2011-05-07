/*
 * iOSFile.h
 *
 *  Created on: 2011-03-20
 *      Author: Artur Mazurek
 */

#include "iOSFile.h"

#include <cstdio>

#include "StringHelper.h"

#define LINE_END "\r\n"
#define OS_SEP "/"

#define BUFSIZE 512
static char gReadBuffer[BUFSIZE];

iOSFile::iOSFile(const std::string& filename, const std::string& mode)
{
    // Ok, as of now just split the file in the position of last dot
    assert(filename.find_last_of(".") != std::string::npos);
    // and, since bundles don't support directories everything needs to be stripped
    // after last os.sep
    
    std::string name = filename.substr(0, filename.find_last_of("."));
    
    size_t sepPosition = name.find_last_of(OS_SEP);
    if(sepPosition != std::string::npos)
    {
        name = name.substr(name.find_last_of(OS_SEP) + 1);
    }
    
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    
    NSString *objFilename = [NSString stringWithCString:name.c_str() encoding:[NSString defaultCStringEncoding]];
    NSString *objExtension = [NSString stringWithCString:extension.c_str() encoding:[NSString defaultCStringEncoding]];
    NSString *dataFilePath = [[NSBundle mainBundle] pathForResource:objFilename ofType:objExtension];
    
    m_f.open([dataFilePath cStringUsingEncoding:[NSString defaultCStringEncoding]], std::ios_base::in);
    assert(m_f.good());
}

iOSFile::~iOSFile()
{
    
}

std::string iOSFile::readLine()
{
    m_f.getline(gReadBuffer, BUFSIZE);
    std::string result(gReadBuffer);
    return StringHelper::strip(result, "\r\n");
}

std::string iOSFile::read() //reads whole file
{
    std::string result;
    while(!eof())
    {
        m_f.getline(gReadBuffer, BUFSIZE);
        std::string line(gReadBuffer);
        result += line;
        result += LINE_END;
    }
    return result;
}

bool iOSFile::eof()
{
    return m_f.eof();
}