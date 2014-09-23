#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Source/NOR.o \
	${OBJECTDIR}/Source/PolyphaseFilter.o \
	${OBJECTDIR}/Source/complex.o \
	${OBJECTDIR}/Source/fft.o \
	${OBJECTDIR}/Source/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3

# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=`cppunit-config --cflags` 
CXXFLAGS=`cppunit-config --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f4

${TESTDIR}/TestFiles/f4: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Source/NOR.o: Source/NOR.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/NOR.o Source/NOR.cpp

${OBJECTDIR}/Source/PolyphaseFilter.o: Source/PolyphaseFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/PolyphaseFilter.o Source/PolyphaseFilter.cpp

${OBJECTDIR}/Source/complex.o: Source/complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/complex.o Source/complex.cpp

${OBJECTDIR}/Source/fft.o: Source/fft.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/fft.o Source/fft.cpp

${OBJECTDIR}/Source/main.o: Source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/main.o Source/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/RunMainTest.o ${TESTDIR}/tests/mainclasstest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/RunPolyTest.o ${TESTDIR}/tests/polyphasetest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/RunMainTest.o: tests/RunMainTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/RunMainTest.o tests/RunMainTest.cpp


${TESTDIR}/tests/mainclasstest.o: tests/mainclasstest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/mainclasstest.o tests/mainclasstest.cpp


${TESTDIR}/tests/RunPolyTest.o: tests/RunPolyTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/RunPolyTest.o tests/RunPolyTest.cpp


${TESTDIR}/tests/polyphasetest.o: tests/polyphasetest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/polyphasetest.o tests/polyphasetest.cpp


${OBJECTDIR}/Source/NOR_nomain.o: ${OBJECTDIR}/Source/NOR.o Source/NOR.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/NOR.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/NOR_nomain.o Source/NOR.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/NOR.o ${OBJECTDIR}/Source/NOR_nomain.o;\
	fi

${OBJECTDIR}/Source/PolyphaseFilter_nomain.o: ${OBJECTDIR}/Source/PolyphaseFilter.o Source/PolyphaseFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/PolyphaseFilter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/PolyphaseFilter_nomain.o Source/PolyphaseFilter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/PolyphaseFilter.o ${OBJECTDIR}/Source/PolyphaseFilter_nomain.o;\
	fi

${OBJECTDIR}/Source/complex_nomain.o: ${OBJECTDIR}/Source/complex.o Source/complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/complex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/complex_nomain.o Source/complex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/complex.o ${OBJECTDIR}/Source/complex_nomain.o;\
	fi

${OBJECTDIR}/Source/fft_nomain.o: ${OBJECTDIR}/Source/fft.o Source/fft.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/fft.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/fft_nomain.o Source/fft.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/fft.o ${OBJECTDIR}/Source/fft_nomain.o;\
	fi

${OBJECTDIR}/Source/main_nomain.o: ${OBJECTDIR}/Source/main.o Source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/main_nomain.o Source/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
