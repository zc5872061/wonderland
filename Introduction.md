# // No longer developed #

I decided to no longer develop this project. Sorry for everyone interested in it but anyway it was in a very early stage, so no very useful. The main reason is that there are already better solutions usually already working.

I suggest trying this one - http://www.cocos2d-x.org/ - works for android, bada, iOS. Many tutorials on web.

My blog is here - http://hashcarrot.com

# Introduction #

Wonderland is intended to be a cross-platform 3D engine that is scripted by Lua.

# Details #

As of now it is in a very early stage on development:
  * Compiles and runs on iOS, compiles on bada
  * Uses OpenGL ES 2.0 for rendering the scene
  * Uses Freetype to render fonts (doesn't work on bada yet)
  * Uses an offline python script to convert Collada model files into its own format very similar to .ini
  * Includes simple UI widgets - namely buttons and labels.
  * Written in portable C++
  * Uses simple interfaces for non-portable code like threading

What is planned to be included in it:
  * Lua scripting
  * Bullet physics engine
  * Freetype rendering of text (already working on iOS)
  * Android release