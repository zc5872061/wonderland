################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/BasicMesh.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/Material.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/MaterialInstance.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/MaterialsManager.cpp \
C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/Model.cpp 

OBJS += \
./Sources/Engine/BasicMesh.o \
./Sources/Engine/Material.o \
./Sources/Engine/MaterialInstance.o \
./Sources/Engine/MaterialsManager.o \
./Sources/Engine/Model.o 

CPP_DEPS += \
./Sources/Engine/BasicMesh.d \
./Sources/Engine/Material.d \
./Sources/Engine/MaterialInstance.d \
./Sources/Engine/MaterialsManager.d \
./Sources/Engine/Model.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Engine/BasicMesh.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/BasicMesh.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Engine/Material.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/Material.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Engine/MaterialInstance.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/MaterialInstance.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Engine/MaterialsManager.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/MaterialsManager.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Engine/Model.o: C:/Users/Artur/Documents/Programowanie/wonderland/Code/src/Engine/Model.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"C:/bada/1.2.1/include" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Freetype" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Boost" -I"C:\Users\Artur\Documents\Programowanie\wonderland\Code\inc" -I"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


