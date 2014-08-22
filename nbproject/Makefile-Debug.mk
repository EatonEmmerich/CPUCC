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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Source/DoubleVector.o \
	${OBJECTDIR}/Source/SingleVector.o \
	${OBJECTDIR}/Source/complex.o \
	${OBJECTDIR}/Source/fft.o \
	${OBJECTDIR}/Source/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpucc

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpucc: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpucc ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Source/DoubleVector.o: Source/DoubleVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/DoubleVector.o Source/DoubleVector.cpp

${OBJECTDIR}/Source/SingleVector.o: Source/SingleVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/SingleVector.o Source/SingleVector.cpp

${OBJECTDIR}/Source/complex.o: Source/complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/complex.o Source/complex.cpp

${OBJECTDIR}/Source/fft.o: Source/fft.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/fft.o Source/fft.cpp

${OBJECTDIR}/Source/main.o: Source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/main.o Source/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/RuntSingleVector.o ${TESTDIR}/tests/testSingleVector.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   


${TESTDIR}/tests/RuntSingleVector.o: tests/RuntSingleVector.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/RuntSingleVector.o tests/RuntSingleVector.cpp


${TESTDIR}/tests/testSingleVector.o: tests/testSingleVector.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testSingleVector.o tests/testSingleVector.cpp


${OBJECTDIR}/Source/DoubleVector_nomain.o: ${OBJECTDIR}/Source/DoubleVector.o Source/DoubleVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/DoubleVector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/DoubleVector_nomain.o Source/DoubleVector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/DoubleVector.o ${OBJECTDIR}/Source/DoubleVector_nomain.o;\
	fi

${OBJECTDIR}/Source/SingleVector_nomain.o: ${OBJECTDIR}/Source/SingleVector.o Source/SingleVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/SingleVector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/SingleVector_nomain.o Source/SingleVector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/SingleVector.o ${OBJECTDIR}/Source/SingleVector_nomain.o;\
	fi

${OBJECTDIR}/Source/complex_nomain.o: ${OBJECTDIR}/Source/complex.o Source/complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Source/complex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/complex_nomain.o Source/complex.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/fft_nomain.o Source/fft.cpp;\
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
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Source/main_nomain.o Source/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Source/main.o ${OBJECTDIR}/Source/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpucc

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
