add_executable(practice_00
  src/main.c
  src/practice_examples.c
    
)

target_include_directories(practice_00 PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
