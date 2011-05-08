################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Fonts/FontEngine.cpp 

OBJS += \
./Sources/Fonts/FontEngine.o 

CPP_DEPS += \
./Sources/Fonts/FontEngine.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Fonts/FontEngine.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Fonts/FontEngine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


