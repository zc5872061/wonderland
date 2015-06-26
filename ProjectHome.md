# // No longer developed 2 #

Actually, after more than two years after starting this page (and almost two years after abandoning it) I decided to return to the idea of creating a framework that might work with multiple platforms. It's on github this time and can be found under this url: https://github.com/arturmazurek/wonderland.

More updates will be there. It won't be a continuation of this one (takes the name after it though!).

# // No longer developed #

I decided to no longer develop this project. Sorry for everyone interested in it but anyway it was in a very early stage, so no very useful. The main reason is that there are already better solutions usually already working.

I suggest trying this one (if you are looking for a 2D game) - http://www.cocos2d-x.org/ - works on iOS, android, and more. Many tutorials on web. If you are looking for a 3D game there aren't any very simple alternatives though. I suggest trying Unreal Engine (free for mobiles under some circumstances ) or Unity (couple hundred dollars per license - more popular on mobiles I think). There is also a 3D version of Cocos and Google to further rectify this advice :)

My blog is here - http://hashcarrot.com, and on http://42labs.net you can find my games and applications.

# Welcome to the Wonderland! #

Wonderland is a game engine intended to run on multiple mobile platforms like iOS, Android or bada. Right now it is in a very early stage of development so it's not very amazing but one day it will be a good tool to create mobile games.

# What is already done? #

Right now the framework (let's call it a framework at the moment) is able to:
  * Load model data from it's own, very simple, file format.
  * Render 3D objects as well as a 2D layer (UI) using OpenGL ES 2.
  * Parse it's own material (.ini actually) format and load shaders which are automatically populated with required data
  * A simple, and not yet very beautiful animation system.
  * Freetype font rendering for the UI. Unfinished - kerning information needs still to be added.

# What is planned in the nearest future? #

Besides the framework's code, there also a simple game's source files added to repository. The game is called BadBalls 2 and is a simple match-5 ball game. It's here to drive changes to the code and add stuff on as-needed basis so that everything is more or less usable. Once it's finished (and it's beta version is closer than further) more stuff will be added.

Also a logo for the project would be nice.

# What then? #

Once the game is finished these changes to the codebase are planned:
  * Integrate Lua scripting and move game-dependant code from main line, so that it will be easier to create other games
  * Add the Bullet Physics engine. We'll see how it works on mobile devices first of course

These are the biggest design-impacting things I definitely would like to have in the engine (then I will call it an engine).

Other must-have features like bone-animations are not listed here. More details regarding the plan will be available on the project wiki.