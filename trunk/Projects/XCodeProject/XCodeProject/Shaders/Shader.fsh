//
//  Shader.fsh
//  XCodeProject
//
//  Created by Artur Mazurek on 11-05-07.
//  Copyright 2011 none. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
