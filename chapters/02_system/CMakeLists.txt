cmake_minimum_required(VERSION 3.16)
project(system_ch02 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(system_demos
    src/memory_model.c
    src/pointers.c
    src/bitops.c
    src/build_link.c
    main.c
)

target_include_directories(system_demos PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ---- Compiler warnings (per-compiler) ----
# MSVC: /W4 /permissive- (가급적 엄격)
# GCC/Clang: -Wall -Wextra -Wpedantic
target_compile_options(system_demos PRIVATE
    $<$<C_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<NOT:$<C_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

# ---- Linker map file (per-linker) ----
set(MAP_FILE "${CMAKE_BINARY_DIR}/chapters_02_system/system_demos.map")
if (MSVC)
    # Ensure directory exists
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/chapters_02_system")
    # Just /MAP:file, no /LINK
    target_link_options(system_demos PRIVATE /MAP:${MAP_FILE})
else()
    target_link_options(system_demos PRIVATE -Wl,-Map=${MAP_FILE})
endif()


# ---- Convenience inspection targets (platform aware) ----
if (MSVC)
    # dumpbin은 VS 개발자 명령 프롬프트에서 사용 권장
    add_custom_target(sys_headers
        COMMAND dumpbin /HEADERS $<TARGET_FILE:system_demos> | more
        DEPENDS system_demos
        COMMENT "dumpbin /HEADERS"
    )
    add_custom_target(sys_symbols
        COMMAND dumpbin /SYMBOLS $<TARGET_FILE:system_demos> | more
        DEPENDS system_demos
        COMMENT "dumpbin /SYMBOLS"
    )
else()
    find_program(SIZE_TOOL NAMES size)
    add_custom_target(sys_size
        COMMAND ${SIZE_TOOL} $<TARGET_FILE:system_demos>
        DEPENDS system_demos
        COMMENT "size (ELF)"
    )
    add_custom_target(sys_nm
        COMMAND nm --print-size --size-sort -t d $<TARGET_FILE:system_demos> | head -n 40
        DEPENDS system_demos
        COMMENT "nm top symbols"
    )
    add_custom_target(sys_sections
        COMMAND objdump -h $<TARGET_FILE:system_demos> | sed -n '1,200p'
        DEPENDS system_demos
        COMMENT "objdump -h"
    )
endif()
