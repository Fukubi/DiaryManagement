target_link_libraries(${PROJECT_NAME} ncurses -static)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/includes)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRCS)

target_sources(${PROJECT_NAME} PUBLIC ${SRCS})