//
//  pi_iOS.cpp
//  BadBalls2
//
//  Created by Artur Mazurek on 11-04-06.
//  Copyright 2011 none. All rights reserved.
//

#include "pi_iOS.h"

namespace Constants
{
    static std::string g_rootPath;
    
    // Returns root path as specified in the pi.h file. However as of now it is used only by 
    // FreeType because bitmaps and files are handled by name and extension. This is because I don't know
    // Cocoa and have no idea how to do it better and since it's not very mission-critical I just
    // want to keep calm and carry on.
    std::string getRootPath()
    {
        if(g_rootPath.size() == 0)
        {
            CFBundleRef mainBundle;
            mainBundle = CFBundleGetMainBundle();		
            CFURLRef    seagullURL;
            seagullURL = CFBundleCopyResourcesDirectoryURL(mainBundle);	
            UInt8 szResDir[200];
            CFURLGetFileSystemRepresentation(seagullURL, false, szResDir, 200);
            // this is to get the home directory, but to find resources we should use the 
            // bundle functions
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
            NSString *homeDir = [paths objectAtIndex:0];
            const char* szUser;
            
            szUser = [homeDir UTF8String];
            
            CFRelease(seagullURL);
            
            std::string result((char*)szResDir);
            g_rootPath = result + "/";
        }
        return g_rootPath;
    }
    
    // It looks like in iOS everything lands in the .app directory anyway
    std::string getMaterialsDir()
    {
        return "";
    }
    
    std::string getFontsDir()
    {
        return "";
    }
    
    std::string getUiDataPath()
    {
        return "";
    }
    
    std::string getModelsDir()
    {
        return "";
    }
    
    std::string getBitmapsDir()
    {
        return "";
    }
    
    int getDpi()
    {
        return 326; // taken from wikipedia
    }
}