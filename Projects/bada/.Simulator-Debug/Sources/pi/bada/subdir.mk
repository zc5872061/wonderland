################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaBitmap.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaFile.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaThread.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/pi_bada.cpp 

OBJS += \
./Sources/pi/bada/BadaBitmap.o \
./Sources/pi/bada/BadaFile.o \
./Sources/pi/bada/BadaThread.o \
./Sources/pi/bada/pi_bada.o 

CPP_DEPS += \
./Sources/pi/bada/BadaBitmap.d \
./Sources/pi/bada/BadaFile.d \
./Sources/pi/bada/BadaThread.d \
./Sources/pi/bada/pi_bada.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/pi/bada/BadaBitmap.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaBitmap.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pi/bada/BadaFile.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaFile.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pi/bada/BadaThread.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/BadaThread.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pi/bada/pi_bada.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/pi/bada/pi_bada.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


