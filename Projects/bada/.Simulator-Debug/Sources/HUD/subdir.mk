################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameButton.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameControl.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameLabel.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GamePanel.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/HUD.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/HUDDataLoader.cpp 

OBJS += \
./Sources/HUD/GameButton.o \
./Sources/HUD/GameControl.o \
./Sources/HUD/GameLabel.o \
./Sources/HUD/GamePanel.o \
./Sources/HUD/HUD.o \
./Sources/HUD/HUDDataLoader.o 

CPP_DEPS += \
./Sources/HUD/GameButton.d \
./Sources/HUD/GameControl.d \
./Sources/HUD/GameLabel.d \
./Sources/HUD/GamePanel.d \
./Sources/HUD/HUD.d \
./Sources/HUD/HUDDataLoader.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/HUD/GameButton.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameButton.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HUD/GameControl.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameControl.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HUD/GameLabel.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GameLabel.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HUD/GamePanel.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/GamePanel.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HUD/HUD.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/HUD.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HUD/HUDDataLoader.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/HUD/HUDDataLoader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


