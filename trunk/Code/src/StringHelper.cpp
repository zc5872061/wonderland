/*
 * StringHelper.cpp
 *
 *  Created on: 2011-02-26
 *      Author: Artur
 */

#include "StringHelper.h"

namespace StringHelper
{
    
    std::string strip(const std::string& text, const std::string& stripChar)
    {
        if(text.length() == 0)
        {
            return "";
        }
        
        std::string result = text;
        
        int i = 0;
        while(stripChar.find(text[i]) != std::string::npos)
        {
            ++i;
            if(i == text.size())
            {
                return "";
            }
        }
        result = result.substr(i);
        
        i = static_cast<int>(result.size())-1;
        while(stripChar.find(result[i]) != std::string::npos)
        {
            --i;
            if(i < 0)
            {
                return "";
            }
        }
        result = result.substr(0, i+1); // +1 because while goes into the proper text
        
        return result;
    }
        
    void tokenize(const std::string& source, std::vector<std::string>& result, const std::string& tokens)
    {
        int tokenStart = -1;
        
        for(int i = 0; i < source.size(); ++i)
        {
            if(tokens.find(source[i]) != std::string::npos)
            {
                if(tokenStart == -1) continue;
                result.push_back(source.substr(tokenStart, i - tokenStart));
                tokenStart = -1;
            }
            else
            {
                if(tokenStart != -1) continue;
                tokenStart = i;
            }
        }
        
        if(tokenStart != -1)
        {
            result.push_back(source.substr(tokenStart));
        }
    }
    
    std::vector<std::string> tokenize(const std::string& source, const std::string& tokens)
    {
        std::vector<std::string> result;
        tokenize(source, result, tokens);
        return result;
    }
    
}
