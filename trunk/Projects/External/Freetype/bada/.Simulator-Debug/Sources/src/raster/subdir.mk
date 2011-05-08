################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/ftraster.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/ftrend1.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/raster.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/rastpic.c 

OBJS += \
./Sources/src/raster/ftraster.o \
./Sources/src/raster/ftrend1.o \
./Sources/src/raster/raster.o \
./Sources/src/raster/rastpic.o 

C_DEPS += \
./Sources/src/raster/ftraster.d \
./Sources/src/raster/ftrend1.d \
./Sources/src/raster/raster.d \
./Sources/src/raster/rastpic.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/src/raster/ftraster.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/ftraster.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/raster/ftrend1.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/ftrend1.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/raster/raster.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/raster.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/raster/rastpic.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/raster/rastpic.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


