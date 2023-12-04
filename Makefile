CXX := g++
CXXFLAGS := -std=c++17 -fPIC -lsqlite3

INCLUDE := -I src/include/
DOCTEST += -I src/test/doctest.h

SRC_DIR := src/main
TEST_DIR := src/tests

BIN_DIR := bin
BUILD_DIR := build


SRC_FILES := $(filter-out src/main/twitter.cpp, $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(OBJ_SRC_FILES)
OBJ_TEST_FILES += $(TEST_FILES:.cpp=.o)

run: $(BIN_DIR)/TwitterApp
	@$(BIN_DIR)/TwitterApp migrate
	@$(BIN_DIR)/TwitterApp run

$(BIN_DIR)/TwitterApp: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES)) $(BUILD_DIR)/libtwitter.so
	@echo "🔧 Preparing executable..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) src/main/twitter.cpp $^ -L$(BUILD_DIR) -ltwitter -o $@ -lsqlite3

build: $(BUILD_DIR)/libtwitter.so

$(BUILD_DIR)/libtwitter.so: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -shared $^ -o $(BUILD_DIR)/libtwitter.so

test: $(BIN_DIR)/test
	@$(BIN_DIR)/test

$(BIN_DIR)/test: $(addprefix $(BUILD_DIR)/,$(OBJ_TEST_FILES))
	@echo "🔧 Preparing test suite ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS)  $^ -o $@ -lsqlite3

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo " Contruindo $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo " Contruindo $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(DOCTEST)  -MMD -MP -c $< -o $@ 

clean:
	@echo " Limpando ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)