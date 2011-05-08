################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

REPOSITORY_ROOT := C:/bada/1.2.1/IDE/workspace/repository/Wonderland/Simulator-Debug

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include Sources/pi/bada/subdir.mk
-include Sources/subdir.mk
-include Sources/HUD/subdir.mk
-include Sources/Fonts/subdir.mk
-include Sources/Engine/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Wonderland.exe

# Tool invocations
Wonderland.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: bada C++ Linker'
	@echo 'ldflags: -L"C:/bada/1.2.1/Model/Wave_LP1/Simulator" -L"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/../../External/Prebuilt/bada/Simulator" -L"C:/bada/1.2.1/Lib" -L"C:/Users/Artur/Documents/Programowanie/wonderland/Projects/bada/lib" -shared -o"Wonderland.exe" ./src/Form1.o ./src/Wonderland.o ./src/WonderlandEntry.o ./Sources/pi/bada/BadaBitmap.o ./Sources/pi/bada/BadaFile.o ./Sources/pi/bada/BadaThread.o ./Sources/pi/bada/pi_bada.o ./Sources/Actor.o ./Sources/Ball.o ./Sources/BallsGameController.o ./Sources/BallsHUD.o ./Sources/BallsInformations.o ./Sources/BlockButton.o ./Sources/Board.o ./Sources/BoardController.o ./Sources/BoardModel.o ./Sources/Camera.o ./Sources/CollisionShapes.o ./Sources/GLRenderer.o ./Sources/Game.o ./Sources/GameBitmap.o ./Sources/GameController.o ./Sources/GameFile.o ./Sources/GameThread.o ./Sources/LineActor.o ./Sources/MathHelper.o ./Sources/MeshManager.o ./Sources/PhysicsEngine.o ./Sources/Program.o ./Sources/ResourceManager.o ./Sources/Shader.o ./Sources/ShaderManager.o ./Sources/StaticMesh.o ./Sources/StringHelper.o ./Sources/Vector.o ./Sources/HUD/GameButton.o ./Sources/HUD/GameControl.o ./Sources/HUD/GameLabel.o ./Sources/HUD/GamePanel.o ./Sources/HUD/HUD.o ./Sources/HUD/HUDDataLoader.o ./Sources/Fonts/FontEngine.o ./Sources/Engine/BasicMesh.o ./Sources/Engine/Material.o ./Sources/Engine/MaterialInstance.o ./Sources/Engine/MaterialsManager.o ./Sources/Engine/Model.o '
	i686-mingw32-g++ @ldflags @ldobjs  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) Wonderland.exe $(REPOSITORY_ROOT)/*
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
