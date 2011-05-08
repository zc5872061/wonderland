################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/truetype.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttdriver.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttgload.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttgxvar.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttinterp.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttobjs.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttpic.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttpload.c 

OBJS += \
./Sources/src/truetype/truetype.o \
./Sources/src/truetype/ttdriver.o \
./Sources/src/truetype/ttgload.o \
./Sources/src/truetype/ttgxvar.o \
./Sources/src/truetype/ttinterp.o \
./Sources/src/truetype/ttobjs.o \
./Sources/src/truetype/ttpic.o \
./Sources/src/truetype/ttpload.o 

C_DEPS += \
./Sources/src/truetype/truetype.d \
./Sources/src/truetype/ttdriver.d \
./Sources/src/truetype/ttgload.d \
./Sources/src/truetype/ttgxvar.d \
./Sources/src/truetype/ttinterp.d \
./Sources/src/truetype/ttobjs.d \
./Sources/src/truetype/ttpic.d \
./Sources/src/truetype/ttpload.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/src/truetype/truetype.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/truetype.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttdriver.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttdriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttgload.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttgload.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttgxvar.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttgxvar.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttinterp.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttinterp.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttobjs.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttobjs.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttpic.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttpic.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/truetype/ttpload.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/truetype/ttpload.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


