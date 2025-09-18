add_executable(practice
  "main.c"
  src/practice_examples.c)

target_include_directories(practice PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

