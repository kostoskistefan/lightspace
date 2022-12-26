TARGET := lightspace

SOURCE_DIR := source
DATA_DIR   := data
OBJECT_DIR := obj

SOURCE_FILES := $(shell find $(SOURCE_DIR) -name "*.cc")
OBJECT_FILES := $(patsubst $(SOURCE_DIR)/%.cc, $(OBJECT_DIR)/%.o, $(SOURCE_FILES))

CFLAGS := $(shell pkg-config --cflags --libs gtkmm-4.0)\
		  -lm -std=c++17 -fopenmp -Wall -Wextra -Werror -pedantic

all: resources $(OBJECT_FILES) 
	g++ -o $(TARGET) $(OBJECT_FILES) $(CFLAGS)

resources:
	glib-compile-resources $(DATA_DIR)/$(TARGET).gresource.xml --target=$(SOURCE_DIR)/resources.cc --sourcedir=$(DATA_DIR) --generate-source

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cc
	@mkdir -p $(@D)
	g++ -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJECT_DIR) $(TARGET) $(SOURCE_DIR)/resources.cc

$(shell mkdir -p $(OBJECT_DIR))
