//
//  shared_ptr.h
//  BadBalls2
//
//  Created by Artur Mazurek on 11-04-02.
//  Copyright 2011 none. All rights reserved.
//
#ifndef _SHARED_PTR_H_
#define _SHARED_PTR_H_

// Just a convienience file to include boost::shared_ptr on systems that support it and 
// our own pointer (once it exists) if not supported

#if defined (IOS)
#include "boost/shared_ptr.hpp"
using boost::shared_ptr;
#elif defined (SHP)
#include "boost/shared_ptr.hpp"
using boost::shared_ptr;
#else
#error // add shared_ptr location to build
#endif

#endif // _SHARED_PTR_H_
