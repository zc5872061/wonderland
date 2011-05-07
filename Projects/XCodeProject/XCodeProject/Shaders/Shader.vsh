//
//  Shader.vsh
//  XCodeProject
//
//  Created by Artur Mazurek on 11-05-07.
//  Copyright 2011 none. All rights reserved.
//

attribute vec4 position;
attribute vec4 color;

varying vec4 colorVarying;

uniform float translate;

void main()
{
    gl_Position = position;
    gl_Position.y += sin(translate) / 2.0;

    colorVarying = color;
}
