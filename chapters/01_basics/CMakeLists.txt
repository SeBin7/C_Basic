add_executable(basics
  "main.c"
  src/variables.c
  src/operators.c
  src/functions.c
  src/arrays.c
  src/strings.c
  src/structs_enums.c
 src/pointers_memory.c)

target_include_directories(basics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

