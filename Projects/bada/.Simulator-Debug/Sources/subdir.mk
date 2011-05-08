################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Actor.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Ball.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsGameController.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsHUD.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsInformations.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BlockButton.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Board.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BoardController.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BoardModel.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Camera.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/CollisionShapes.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GLRenderer.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Game.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameBitmap.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameController.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameFile.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameThread.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/LineActor.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/MathHelper.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/MeshManager.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/PhysicsEngine.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Program.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/ResourceManager.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Shader.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/ShaderManager.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/StaticMesh.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/StringHelper.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Vector.cpp 

OBJS += \
./Sources/Actor.o \
./Sources/Ball.o \
./Sources/BallsGameController.o \
./Sources/BallsHUD.o \
./Sources/BallsInformations.o \
./Sources/BlockButton.o \
./Sources/Board.o \
./Sources/BoardController.o \
./Sources/BoardModel.o \
./Sources/Camera.o \
./Sources/CollisionShapes.o \
./Sources/GLRenderer.o \
./Sources/Game.o \
./Sources/GameBitmap.o \
./Sources/GameController.o \
./Sources/GameFile.o \
./Sources/GameThread.o \
./Sources/LineActor.o \
./Sources/MathHelper.o \
./Sources/MeshManager.o \
./Sources/PhysicsEngine.o \
./Sources/Program.o \
./Sources/ResourceManager.o \
./Sources/Shader.o \
./Sources/ShaderManager.o \
./Sources/StaticMesh.o \
./Sources/StringHelper.o \
./Sources/Vector.o 

CPP_DEPS += \
./Sources/Actor.d \
./Sources/Ball.d \
./Sources/BallsGameController.d \
./Sources/BallsHUD.d \
./Sources/BallsInformations.d \
./Sources/BlockButton.d \
./Sources/Board.d \
./Sources/BoardController.d \
./Sources/BoardModel.d \
./Sources/Camera.d \
./Sources/CollisionShapes.d \
./Sources/GLRenderer.d \
./Sources/Game.d \
./Sources/GameBitmap.d \
./Sources/GameController.d \
./Sources/GameFile.d \
./Sources/GameThread.d \
./Sources/LineActor.d \
./Sources/MathHelper.d \
./Sources/MeshManager.d \
./Sources/PhysicsEngine.d \
./Sources/Program.d \
./Sources/ResourceManager.d \
./Sources/Shader.d \
./Sources/ShaderManager.d \
./Sources/StaticMesh.d \
./Sources/StringHelper.d \
./Sources/Vector.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Actor.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Actor.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Ball.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Ball.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BallsGameController.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsGameController.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BallsHUD.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsHUD.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BallsInformations.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BallsInformations.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BlockButton.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BlockButton.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Board.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Board.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BoardController.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BoardController.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/BoardModel.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/BoardModel.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Camera.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Camera.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CollisionShapes.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/CollisionShapes.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/GLRenderer.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GLRenderer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Game.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Game.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/GameBitmap.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameBitmap.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/GameController.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameController.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/GameFile.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameFile.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/GameThread.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/GameThread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/LineActor.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/LineActor.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MathHelper.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/MathHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MeshManager.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/MeshManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/PhysicsEngine.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/PhysicsEngine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Program.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Program.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ResourceManager.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/ResourceManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Shader.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Shader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ShaderManager.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/ShaderManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/StaticMesh.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/StaticMesh.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/StringHelper.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/StringHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Vector.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Vector.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


