################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

REPOSITORY_ROOT := C:/bada/1.2.1/IDE/workspace/repository/FreetypeBada/Simulator-Debug

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/src/truetype/subdir.mk
-include Sources/src/smooth/subdir.mk
-include Sources/src/sfnt/subdir.mk
-include Sources/src/raster/subdir.mk
-include Sources/src/psnames/subdir.mk
-include Sources/src/pshinter/subdir.mk
-include Sources/src/cff/subdir.mk
-include Sources/src/base/subdir.mk
-include Sources/src/autofit/subdir.mk
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
all: libFreetypeBada.a

# Tool invocations
libFreetypeBada.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: bada Archiver'
	@echo 'ldflags: -r "libFreetypeBada.a" ./Sources/src/truetype/truetype.o ./Sources/src/truetype/ttdriver.o ./Sources/src/truetype/ttgload.o ./Sources/src/truetype/ttgxvar.o ./Sources/src/truetype/ttinterp.o ./Sources/src/truetype/ttobjs.o ./Sources/src/truetype/ttpic.o ./Sources/src/truetype/ttpload.o ./Sources/src/smooth/ftgrays.o ./Sources/src/smooth/ftsmooth.o ./Sources/src/smooth/ftspic.o ./Sources/src/smooth/smooth.o ./Sources/src/sfnt/sfdriver.o ./Sources/src/sfnt/sfnt.o ./Sources/src/sfnt/sfntpic.o ./Sources/src/sfnt/sfobjs.o ./Sources/src/sfnt/ttbdf.o ./Sources/src/sfnt/ttcmap.o ./Sources/src/sfnt/ttkern.o ./Sources/src/sfnt/ttload.o ./Sources/src/sfnt/ttmtx.o ./Sources/src/sfnt/ttpost.o ./Sources/src/sfnt/ttsbit.o ./Sources/src/sfnt/ttsbit0.o ./Sources/src/raster/ftraster.o ./Sources/src/raster/ftrend1.o ./Sources/src/raster/raster.o ./Sources/src/raster/rastpic.o ./Sources/src/psnames/psmodule.o ./Sources/src/psnames/psnames.o ./Sources/src/psnames/pspic.o ./Sources/src/pshinter/pshalgo.o ./Sources/src/pshinter/pshglob.o ./Sources/src/pshinter/pshinter.o ./Sources/src/pshinter/pshmod.o ./Sources/src/pshinter/pshpic.o ./Sources/src/pshinter/pshrec.o ./Sources/src/cff/cff.o ./Sources/src/cff/cffcmap.o ./Sources/src/cff/cffdrivr.o ./Sources/src/cff/cffgload.o ./Sources/src/cff/cffload.o ./Sources/src/cff/cffobjs.o ./Sources/src/cff/cffparse.o ./Sources/src/cff/cffpic.o ./Sources/src/base/basepic.o ./Sources/src/base/ftadvanc.o ./Sources/src/base/ftapi.o ./Sources/src/base/ftbase.o ./Sources/src/base/ftbbox.o ./Sources/src/base/ftbitmap.o ./Sources/src/base/ftcalc.o ./Sources/src/base/ftdbgmem.o ./Sources/src/base/ftdebug.o ./Sources/src/base/ftgloadr.o ./Sources/src/base/ftglyph.o ./Sources/src/base/ftinit.o ./Sources/src/base/ftobjs.o ./Sources/src/base/ftoutln.o ./Sources/src/base/ftpic.o ./Sources/src/base/ftrfork.o ./Sources/src/base/ftsnames.o ./Sources/src/base/ftstream.o ./Sources/src/base/ftstroke.o ./Sources/src/base/ftsynth.o ./Sources/src/base/ftsystem.o ./Sources/src/base/fttrigon.o ./Sources/src/base/ftutil.o ./Sources/src/autofit/afangles.o ./Sources/src/autofit/afcjk.o ./Sources/src/autofit/afdummy.o ./Sources/src/autofit/afglobal.o ./Sources/src/autofit/afhints.o ./Sources/src/autofit/afindic.o ./Sources/src/autofit/aflatin.o ./Sources/src/autofit/aflatin2.o ./Sources/src/autofit/afloader.o ./Sources/src/autofit/afmodule.o ./Sources/src/autofit/afpic.o ./Sources/src/autofit/afwarp.o ./Sources/src/autofit/autofit.o '
	i686-mingw32-ar @ldflags @ldobjs  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(ARCHIVES)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) libFreetypeBada.a $(REPOSITORY_ROOT)/*
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
