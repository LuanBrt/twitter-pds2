project(TwitterApp)

include_directories(include)
file(GLOB SOURCES "main/*.cpp" "main/models/*.cpp" "main/screens/*.cpp" "main/controllers/*.cpp")

# Definindo onde o executavle será gerado
set(EXECUTABLE_OUTPUT_PATH "../")
add_executable(TwitterApp ${SOURCES})