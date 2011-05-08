################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfdriver.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfnt.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfntpic.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfobjs.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttbdf.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttcmap.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttkern.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttload.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttmtx.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttpost.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttsbit.c \
C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttsbit0.c 

OBJS += \
./Sources/src/sfnt/sfdriver.o \
./Sources/src/sfnt/sfnt.o \
./Sources/src/sfnt/sfntpic.o \
./Sources/src/sfnt/sfobjs.o \
./Sources/src/sfnt/ttbdf.o \
./Sources/src/sfnt/ttcmap.o \
./Sources/src/sfnt/ttkern.o \
./Sources/src/sfnt/ttload.o \
./Sources/src/sfnt/ttmtx.o \
./Sources/src/sfnt/ttpost.o \
./Sources/src/sfnt/ttsbit.o \
./Sources/src/sfnt/ttsbit0.o 

C_DEPS += \
./Sources/src/sfnt/sfdriver.d \
./Sources/src/sfnt/sfnt.d \
./Sources/src/sfnt/sfntpic.d \
./Sources/src/sfnt/sfobjs.d \
./Sources/src/sfnt/ttbdf.d \
./Sources/src/sfnt/ttcmap.d \
./Sources/src/sfnt/ttkern.d \
./Sources/src/sfnt/ttload.d \
./Sources/src/sfnt/ttmtx.d \
./Sources/src/sfnt/ttpost.d \
./Sources/src/sfnt/ttsbit.d \
./Sources/src/sfnt/ttsbit0.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/src/sfnt/sfdriver.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfdriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/sfnt.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfnt.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/sfntpic.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfntpic.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/sfobjs.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/sfobjs.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttbdf.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttbdf.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttcmap.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttcmap.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttkern.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttkern.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttload.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttload.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttmtx.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttmtx.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttpost.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttpost.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttsbit.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttsbit.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/sfnt/ttsbit0.o: C:/Users/Artur/Documents/Programowanie/wonderland/External/Freetype/src/sfnt/ttsbit0.c
	@echo 'Building file: $<'
	@echo 'Invoking: bada C Compiler'
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-gcc -D_DEBUG -DFT2_BUILD_LIBRARY -DSHP -DBUILD_DLL -I"C:\Users\Artur\Documents\Programowanie\wonderland\External\Freetype" -I"C:/bada/1.2.1/include" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


