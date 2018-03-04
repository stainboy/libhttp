CXX		:= -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS	:= -L/usr/lib -lstdc++ -lm -luv
BUILD	:= ./build
OBJ_DIR	:= $(BUILD)/objects
APP_DIR	:= $(BUILD)/apps
TARGET	:= program
INCLUDE	:= -I./
SRC		:=							 \
	$(wildcard src/*.cc) \
	$(wildcard examples/app/*.cc) \
	$(wildcard examples/app/controllers/*.cc) \
	$(wildcard examples/app/filters/*.cc) \


OBJECTS := $(SRC:%.cc=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rf $(OBJ_DIR)/*
	-@rm -rf $(APP_DIR)/*
