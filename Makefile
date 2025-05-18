CXX = g++
CXXFLAGS = -g -O0
TARGET = nmoku
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d) # 依存関係ファイルを保存する変数

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# .cpp ファイルから .o ファイルを生成するルール（暗黙のルールに頼る）
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# 依存関係ファイルを生成するルール
%.d: %.cpp
	$(CXX) -MM $(CXXFLAGS) $< > $@

# 依存関係ファイルをインクルード（存在する場合）
-include $(DEPS)

clean:
	rm -f $(OBJECTS) $(TARGET) $(DEPS)