cmake_minimum_required(VERSION 3.9)

aux_source_directory(src FILLER_SRC)
aux_source_directory(libft/gnl_src GNL_SRC)
include_directories(libft libft/gnl_src include)

add_executable(bot_strong ${FILLER_SRC})

add_library(ft STATIC IMPORTED)
set_property(TARGET ft PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(bot_strong ft)


add_executable(vm IMPORTED)
set_property(TARGET vm PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/resources/filler_vm)