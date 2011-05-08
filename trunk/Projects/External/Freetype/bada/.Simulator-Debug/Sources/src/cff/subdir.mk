################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cff.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffcmap.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffdrivr.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffgload.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffload.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffobjs.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffparse.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffpic.c 

OBJS += \
./Sources/src/cff/cff.o \
./Sources/src/cff/cffcmap.o \
./Sources/src/cff/cffdrivr.o \
./Sources/src/cff/cffgload.o \
./Sources/src/cff/cffload.o \
./Sources/src/cff/cffobjs.o \
./Sources/src/cff/cffparse.o \
./Sources/src/cff/cffpic.o 

C_DEPS += \
./Sources/src/cff/cff.d \
./Sources/src/cff/cffcmap.d \
./Sources/src/cff/cffdrivr.d \
./Sources/src/cff/cffgload.d \
./Sources/src/cff/cffload.d \
./Sources/src/cff/cffobjs.d \
./Sources/src/cff/cffparse.d \
./Sources/src/cff/cffpic.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/src/cff/cff.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cff.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffcmap.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffcmap.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffdrivr.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffdrivr.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffgload.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffgload.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffload.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffload.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffobjs.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffobjs.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffparse.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffparse.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/cff/cffpic.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/cff/cffpic.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


