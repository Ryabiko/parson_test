#Set this to @ to keep the makefile quiet

SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = parson_Unity

#--- Inputs ----#
UNITY_HOME = ../tdd_creator/Unity
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .
PROJECT_TEST_DIR = test
UNITY_BUILD_HOME = ../tdd_creator

UNITY_CFLAGS += -Wno-missing-prototypes
UNITY_WARNINGFLAGS = -Wall
UNITY_WARNINGFLAGS = -Werror
UNITY_WARNINGFLAGS = -Wswitch-default
#UNITY_WARNINGFLAGS += -Wshadow
SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src/ \
	$(PROJECT_HOME_DIR)/src/parse_example \

TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR) \
	$(PROJECT_TEST_DIR)/parse_example \
	$(UNITY_HOME)/unity \
	$(UNITY_HOME)/src \
	$(UNITY_HOME)/extras/memory/src/ \
	$(UNITY_HOME)/extras/fixture/src \
	$(UNITY_HOME)/extras/fixture/test \

INCLUDE_DIRS = \
	. \
	$(UNITY_HOME)/src \
	$(UNITY_HOME)/extras/memory/src/ \
	$(UNITY_HOME)/extras/fixture/src \
	$(UNITY_HOME)/extras/fixture/test \
	$(PROJECT_HOME_DIR)/inc/ \
	$(PROJECT_HOME_DIR)/inc/parse_example \

include $(UNITY_BUILD_HOME)/MakefileWorker.mk
