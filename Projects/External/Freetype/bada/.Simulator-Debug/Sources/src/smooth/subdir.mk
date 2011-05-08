################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftgrays.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftsmooth.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftspic.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/smooth.c 

OBJS += \
./Sources/src/smooth/ftgrays.o \
./Sources/src/smooth/ftsmooth.o \
./Sources/src/smooth/ftspic.o \
./Sources/src/smooth/smooth.o 

C_DEPS += \
./Sources/src/smooth/ftgrays.d \
./Sources/src/smooth/ftsmooth.d \
./Sources/src/smooth/ftspic.d \
./Sources/src/smooth/smooth.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/src/smooth/ftgrays.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftgrays.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/smooth/ftsmooth.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftsmooth.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/smooth/ftspic.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/ftspic.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/smooth/smooth.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/smooth/smooth.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


