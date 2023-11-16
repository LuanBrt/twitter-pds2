project(TwitterApp)

include_directories(include)
file(GLOB SOURCES "main/*.cpp" "main/models/*.cpp" "main/screens/*.cpp" "main/controllers/*.cpp")
file(GLOB TESTES "main/models/*.cpp" "main/screens/*.cpp" "main/controllers/*.cpp" "tests/*.cpp" "tests/*.h")

# Definindo onde o executavle será gerado
set(EXECUTABLE_OUTPUT_PATH "../")

add_executable(TwitterApp ${SOURCES})
add_executable(test ${TESTES})

find_package(SQLite3 REQUIRED)
target_link_libraries (TwitterApp PRIVATE SQLite::SQLite3)
target_link_libraries (test PRIVATE SQLite::SQLite3)
