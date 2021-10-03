#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=i2c_x.c delay.S timer_x.c init.c SSD1306/lcd.c spi_x.c sine.c qei_x.c cni.c buffer.S i2c_eep.c i2c_misc.c window.c window_functions/blackman_window.c window_functions/dirichlet_window.c window_functions/gauss_window.c window_functions/hamming_window.c window_functions/kaiser_window.c window_functions/bartlett_window.c window_functions/blackman_harris_window.c window_functions/flat_top_window.c window_asm.S main.c filter.S fft.c display.c sine_asm.S

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/i2c_x.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/timer_x.o ${OBJECTDIR}/init.o ${OBJECTDIR}/SSD1306/lcd.o ${OBJECTDIR}/spi_x.o ${OBJECTDIR}/sine.o ${OBJECTDIR}/qei_x.o ${OBJECTDIR}/cni.o ${OBJECTDIR}/buffer.o ${OBJECTDIR}/i2c_eep.o ${OBJECTDIR}/i2c_misc.o ${OBJECTDIR}/window.o ${OBJECTDIR}/window_functions/blackman_window.o ${OBJECTDIR}/window_functions/dirichlet_window.o ${OBJECTDIR}/window_functions/gauss_window.o ${OBJECTDIR}/window_functions/hamming_window.o ${OBJECTDIR}/window_functions/kaiser_window.o ${OBJECTDIR}/window_functions/bartlett_window.o ${OBJECTDIR}/window_functions/blackman_harris_window.o ${OBJECTDIR}/window_functions/flat_top_window.o ${OBJECTDIR}/window_asm.o ${OBJECTDIR}/main.o ${OBJECTDIR}/filter.o ${OBJECTDIR}/fft.o ${OBJECTDIR}/display.o ${OBJECTDIR}/sine_asm.o
POSSIBLE_DEPFILES=${OBJECTDIR}/i2c_x.o.d ${OBJECTDIR}/delay.o.d ${OBJECTDIR}/timer_x.o.d ${OBJECTDIR}/init.o.d ${OBJECTDIR}/SSD1306/lcd.o.d ${OBJECTDIR}/spi_x.o.d ${OBJECTDIR}/sine.o.d ${OBJECTDIR}/qei_x.o.d ${OBJECTDIR}/cni.o.d ${OBJECTDIR}/buffer.o.d ${OBJECTDIR}/i2c_eep.o.d ${OBJECTDIR}/i2c_misc.o.d ${OBJECTDIR}/window.o.d ${OBJECTDIR}/window_functions/blackman_window.o.d ${OBJECTDIR}/window_functions/dirichlet_window.o.d ${OBJECTDIR}/window_functions/gauss_window.o.d ${OBJECTDIR}/window_functions/hamming_window.o.d ${OBJECTDIR}/window_functions/kaiser_window.o.d ${OBJECTDIR}/window_functions/bartlett_window.o.d ${OBJECTDIR}/window_functions/blackman_harris_window.o.d ${OBJECTDIR}/window_functions/flat_top_window.o.d ${OBJECTDIR}/window_asm.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/filter.o.d ${OBJECTDIR}/fft.o.d ${OBJECTDIR}/display.o.d ${OBJECTDIR}/sine_asm.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/i2c_x.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/timer_x.o ${OBJECTDIR}/init.o ${OBJECTDIR}/SSD1306/lcd.o ${OBJECTDIR}/spi_x.o ${OBJECTDIR}/sine.o ${OBJECTDIR}/qei_x.o ${OBJECTDIR}/cni.o ${OBJECTDIR}/buffer.o ${OBJECTDIR}/i2c_eep.o ${OBJECTDIR}/i2c_misc.o ${OBJECTDIR}/window.o ${OBJECTDIR}/window_functions/blackman_window.o ${OBJECTDIR}/window_functions/dirichlet_window.o ${OBJECTDIR}/window_functions/gauss_window.o ${OBJECTDIR}/window_functions/hamming_window.o ${OBJECTDIR}/window_functions/kaiser_window.o ${OBJECTDIR}/window_functions/bartlett_window.o ${OBJECTDIR}/window_functions/blackman_harris_window.o ${OBJECTDIR}/window_functions/flat_top_window.o ${OBJECTDIR}/window_asm.o ${OBJECTDIR}/main.o ${OBJECTDIR}/filter.o ${OBJECTDIR}/fft.o ${OBJECTDIR}/display.o ${OBJECTDIR}/sine_asm.o

# Source Files
SOURCEFILES=i2c_x.c delay.S timer_x.c init.c SSD1306/lcd.c spi_x.c sine.c qei_x.c cni.c buffer.S i2c_eep.c i2c_misc.c window.c window_functions/blackman_window.c window_functions/dirichlet_window.c window_functions/gauss_window.c window_functions/hamming_window.c window_functions/kaiser_window.c window_functions/bartlett_window.c window_functions/blackman_harris_window.c window_functions/flat_top_window.c window_asm.S main.c filter.S fft.c display.c sine_asm.S



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MC202
MP_LINKER_FILE_OPTION=,--script=p33EP512MC202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/i2c_x.o: i2c_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_x.o.d 
	@${RM} ${OBJECTDIR}/i2c_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_x.c  -o ${OBJECTDIR}/i2c_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_x.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer_x.o: timer_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_x.o.d 
	@${RM} ${OBJECTDIR}/timer_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_x.c  -o ${OBJECTDIR}/timer_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer_x.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/timer_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/init.o: init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SSD1306/lcd.o: SSD1306/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SSD1306" 
	@${RM} ${OBJECTDIR}/SSD1306/lcd.o.d 
	@${RM} ${OBJECTDIR}/SSD1306/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SSD1306/lcd.c  -o ${OBJECTDIR}/SSD1306/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SSD1306/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/SSD1306/lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/spi_x.o: spi_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_x.o.d 
	@${RM} ${OBJECTDIR}/spi_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  spi_x.c  -o ${OBJECTDIR}/spi_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_x.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/spi_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sine.o: sine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sine.o.d 
	@${RM} ${OBJECTDIR}/sine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sine.c  -o ${OBJECTDIR}/sine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sine.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/qei_x.o: qei_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/qei_x.o.d 
	@${RM} ${OBJECTDIR}/qei_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  qei_x.c  -o ${OBJECTDIR}/qei_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/qei_x.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/qei_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/cni.o: cni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/cni.o.d 
	@${RM} ${OBJECTDIR}/cni.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  cni.c  -o ${OBJECTDIR}/cni.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cni.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/cni.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c_eep.o: i2c_eep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_eep.o.d 
	@${RM} ${OBJECTDIR}/i2c_eep.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_eep.c  -o ${OBJECTDIR}/i2c_eep.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_eep.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_eep.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c_misc.o: i2c_misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_misc.o.d 
	@${RM} ${OBJECTDIR}/i2c_misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_misc.c  -o ${OBJECTDIR}/i2c_misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_misc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_misc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window.o: window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/window.o.d 
	@${RM} ${OBJECTDIR}/window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window.c  -o ${OBJECTDIR}/window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/blackman_window.o: window_functions/blackman_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/blackman_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/blackman_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/blackman_window.c  -o ${OBJECTDIR}/window_functions/blackman_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/blackman_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/blackman_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/dirichlet_window.o: window_functions/dirichlet_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/dirichlet_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/dirichlet_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/dirichlet_window.c  -o ${OBJECTDIR}/window_functions/dirichlet_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/dirichlet_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/dirichlet_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/gauss_window.o: window_functions/gauss_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/gauss_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/gauss_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/gauss_window.c  -o ${OBJECTDIR}/window_functions/gauss_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/gauss_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/gauss_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/hamming_window.o: window_functions/hamming_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/hamming_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/hamming_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/hamming_window.c  -o ${OBJECTDIR}/window_functions/hamming_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/hamming_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/hamming_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/kaiser_window.o: window_functions/kaiser_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/kaiser_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/kaiser_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/kaiser_window.c  -o ${OBJECTDIR}/window_functions/kaiser_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/kaiser_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/kaiser_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/bartlett_window.o: window_functions/bartlett_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/bartlett_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/bartlett_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/bartlett_window.c  -o ${OBJECTDIR}/window_functions/bartlett_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/bartlett_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/bartlett_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/blackman_harris_window.o: window_functions/blackman_harris_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/blackman_harris_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/blackman_harris_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/blackman_harris_window.c  -o ${OBJECTDIR}/window_functions/blackman_harris_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/blackman_harris_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/blackman_harris_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/flat_top_window.o: window_functions/flat_top_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/flat_top_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/flat_top_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/flat_top_window.c  -o ${OBJECTDIR}/window_functions/flat_top_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/flat_top_window.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/flat_top_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fft.o: fft.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fft.o.d 
	@${RM} ${OBJECTDIR}/fft.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fft.c  -o ${OBJECTDIR}/fft.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fft.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/fft.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/display.o: display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/display.o.d 
	@${RM} ${OBJECTDIR}/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  display.c  -o ${OBJECTDIR}/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/display.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/i2c_x.o: i2c_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_x.o.d 
	@${RM} ${OBJECTDIR}/i2c_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_x.c  -o ${OBJECTDIR}/i2c_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_x.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/timer_x.o: timer_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_x.o.d 
	@${RM} ${OBJECTDIR}/timer_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  timer_x.c  -o ${OBJECTDIR}/timer_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer_x.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/timer_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/init.o: init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/init.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SSD1306/lcd.o: SSD1306/lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/SSD1306" 
	@${RM} ${OBJECTDIR}/SSD1306/lcd.o.d 
	@${RM} ${OBJECTDIR}/SSD1306/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SSD1306/lcd.c  -o ${OBJECTDIR}/SSD1306/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SSD1306/lcd.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/SSD1306/lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/spi_x.o: spi_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi_x.o.d 
	@${RM} ${OBJECTDIR}/spi_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  spi_x.c  -o ${OBJECTDIR}/spi_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_x.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/spi_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/sine.o: sine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sine.o.d 
	@${RM} ${OBJECTDIR}/sine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  sine.c  -o ${OBJECTDIR}/sine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sine.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sine.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/qei_x.o: qei_x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/qei_x.o.d 
	@${RM} ${OBJECTDIR}/qei_x.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  qei_x.c  -o ${OBJECTDIR}/qei_x.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/qei_x.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/qei_x.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/cni.o: cni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/cni.o.d 
	@${RM} ${OBJECTDIR}/cni.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  cni.c  -o ${OBJECTDIR}/cni.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/cni.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/cni.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c_eep.o: i2c_eep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_eep.o.d 
	@${RM} ${OBJECTDIR}/i2c_eep.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_eep.c  -o ${OBJECTDIR}/i2c_eep.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_eep.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_eep.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/i2c_misc.o: i2c_misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c_misc.o.d 
	@${RM} ${OBJECTDIR}/i2c_misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c_misc.c  -o ${OBJECTDIR}/i2c_misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c_misc.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/i2c_misc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window.o: window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/window.o.d 
	@${RM} ${OBJECTDIR}/window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window.c  -o ${OBJECTDIR}/window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/blackman_window.o: window_functions/blackman_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/blackman_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/blackman_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/blackman_window.c  -o ${OBJECTDIR}/window_functions/blackman_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/blackman_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/blackman_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/dirichlet_window.o: window_functions/dirichlet_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/dirichlet_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/dirichlet_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/dirichlet_window.c  -o ${OBJECTDIR}/window_functions/dirichlet_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/dirichlet_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/dirichlet_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/gauss_window.o: window_functions/gauss_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/gauss_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/gauss_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/gauss_window.c  -o ${OBJECTDIR}/window_functions/gauss_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/gauss_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/gauss_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/hamming_window.o: window_functions/hamming_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/hamming_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/hamming_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/hamming_window.c  -o ${OBJECTDIR}/window_functions/hamming_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/hamming_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/hamming_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/kaiser_window.o: window_functions/kaiser_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/kaiser_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/kaiser_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/kaiser_window.c  -o ${OBJECTDIR}/window_functions/kaiser_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/kaiser_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/kaiser_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/bartlett_window.o: window_functions/bartlett_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/bartlett_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/bartlett_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/bartlett_window.c  -o ${OBJECTDIR}/window_functions/bartlett_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/bartlett_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/bartlett_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/blackman_harris_window.o: window_functions/blackman_harris_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/blackman_harris_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/blackman_harris_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/blackman_harris_window.c  -o ${OBJECTDIR}/window_functions/blackman_harris_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/blackman_harris_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/blackman_harris_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/window_functions/flat_top_window.o: window_functions/flat_top_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/window_functions" 
	@${RM} ${OBJECTDIR}/window_functions/flat_top_window.o.d 
	@${RM} ${OBJECTDIR}/window_functions/flat_top_window.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  window_functions/flat_top_window.c  -o ${OBJECTDIR}/window_functions/flat_top_window.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_functions/flat_top_window.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_functions/flat_top_window.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/fft.o: fft.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/fft.o.d 
	@${RM} ${OBJECTDIR}/fft.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  fft.c  -o ${OBJECTDIR}/fft.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/fft.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/fft.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/display.o: display.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/display.o.d 
	@${RM} ${OBJECTDIR}/display.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  display.c  -o ${OBJECTDIR}/display.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/display.o.d"      -mno-eds-warn  -g -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -funroll-loops -fomit-frame-pointer -falign-arrays -msmart-io=1 -Wall -msfr-warn=off    -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/display.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/delay.o: delay.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  delay.S  -o ${OBJECTDIR}/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/delay.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--relax,-alsi=${OBJECTDIR}/delay.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" "${OBJECTDIR}/delay.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/buffer.o: buffer.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buffer.o.d 
	@${RM} ${OBJECTDIR}/buffer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  buffer.S  -o ${OBJECTDIR}/buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buffer.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/buffer.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--relax,-alsi=${OBJECTDIR}/buffer.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/buffer.o.d" "${OBJECTDIR}/buffer.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/window_asm.o: window_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/window_asm.o.d 
	@${RM} ${OBJECTDIR}/window_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  window_asm.S  -o ${OBJECTDIR}/window_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_asm.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/window_asm.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--relax,-alsi=${OBJECTDIR}/window_asm.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_asm.o.d" "${OBJECTDIR}/window_asm.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/filter.o: filter.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filter.o.d 
	@${RM} ${OBJECTDIR}/filter.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  filter.S  -o ${OBJECTDIR}/filter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/filter.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/filter.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--relax,-alsi=${OBJECTDIR}/filter.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/filter.o.d" "${OBJECTDIR}/filter.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/sine_asm.o: sine_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sine_asm.o.d 
	@${RM} ${OBJECTDIR}/sine_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sine_asm.S  -o ${OBJECTDIR}/sine_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sine_asm.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/sine_asm.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--relax,-alsi=${OBJECTDIR}/sine_asm.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sine_asm.o.d" "${OBJECTDIR}/sine_asm.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/delay.o: delay.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  delay.S  -o ${OBJECTDIR}/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d"  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/delay.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--relax,-alsi=${OBJECTDIR}/delay.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" "${OBJECTDIR}/delay.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/buffer.o: buffer.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buffer.o.d 
	@${RM} ${OBJECTDIR}/buffer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  buffer.S  -o ${OBJECTDIR}/buffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/buffer.o.d"  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/buffer.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--relax,-alsi=${OBJECTDIR}/buffer.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/buffer.o.d" "${OBJECTDIR}/buffer.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/window_asm.o: window_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/window_asm.o.d 
	@${RM} ${OBJECTDIR}/window_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  window_asm.S  -o ${OBJECTDIR}/window_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/window_asm.o.d"  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/window_asm.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--relax,-alsi=${OBJECTDIR}/window_asm.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/window_asm.o.d" "${OBJECTDIR}/window_asm.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/filter.o: filter.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/filter.o.d 
	@${RM} ${OBJECTDIR}/filter.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  filter.S  -o ${OBJECTDIR}/filter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/filter.o.d"  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/filter.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--relax,-alsi=${OBJECTDIR}/filter.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/filter.o.d" "${OBJECTDIR}/filter.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/sine_asm.o: sine_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sine_asm.o.d 
	@${RM} ${OBJECTDIR}/sine_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  sine_asm.S  -o ${OBJECTDIR}/sine_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sine_asm.o.d"  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,-MD,"${OBJECTDIR}/sine_asm.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--relax,-alsi=${OBJECTDIR}/sine_asm.lst$(MP_EXTRA_AS_POST)  -mdfp=${DFP_DIR}/xc16
	@${FIXDEPS} "${OBJECTDIR}/sine_asm.o.d" "${OBJECTDIR}/sine_asm.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /opt/microchip/xc16/v1.41/lib/libdsp-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    /opt/microchip/xc16/v1.41/lib/libdsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=64,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--warn-section-align,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  /opt/microchip/xc16/v1.41/lib/libdsp-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    /opt/microchip/xc16/v1.41/lib/libdsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -save-temps=obj -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=64,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--warn-section-align,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp=${DFP_DIR}/xc16 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/bat-detector-2.0.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp=${DFP_DIR}/xc16 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
