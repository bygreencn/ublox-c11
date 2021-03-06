cmake_minimum_required (VERSION 2.8.11)
project ("ublox")

option (UBLOX_LIB_ONLY "Install only UBLOX protocol library, no other applications/plugings are built." OFF)
option (UBLOX_CC_PLUGIN "Build and install protocol plugin for CommsChampion." ON)
option (UBLOX_CC_PLUGIN_COPY_TO_CC_INSTALL_PATH "Copy protocol plugin for CommsChampion to the install path of the latter." ON)

set (INSTALL_DIR ${CMAKE_BINARY_DIR}/install)
set (LIB_INSTALL_DIR ${INSTALL_DIR}/lib)
set (BIN_INSTALL_DIR ${INSTALL_DIR}/bin)
set (INC_INSTALL_DIR ${INSTALL_DIR}/include)
set (PLUGIN_INSTALL_DIR ${INSTALL_DIR}/plugin)
set (DOC_INSTALL_DIR ${INSTALL_DIR}/doc)

find_package (Doxygen)
if (DOXYGEN_FOUND)
    set (doc_output_dir "${DOC_INSTALL_DIR}/ublox")
    make_directory (${doc_output_dir})
    
    set (match_str "OUTPUT_DIRECTORY[^\n]*")
    set (replacement_str "OUTPUT_DIRECTORY = ${doc_output_dir}")
    set (output_file "${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf")

    set (config_file "${CMAKE_CURRENT_SOURCE_DIR}/doc/doxygen.conf")
    file (READ ${config_file} config_text)
    string (REGEX REPLACE "${match_str}" "${replacement_str}" modified_config_text "${config_text}")
    file (WRITE "${output_file}" "${modified_config_text}")
    
    if ("${UBLOX_CC_INSTALL_PATH}" STREQUAL "")
        add_custom_target ("doc_ublox"
            COMMAND ${DOXYGEN_EXECUTABLE} ${output_file}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    else ()
        add_custom_target ("doc_ublox"
            COMMAND ${DOXYGEN_EXECUTABLE} ${output_file}
            COMMAND ${CMAKE_COMMAND} -DDOC_OUTPUT_DIR="${doc_output_dir}" -P
                "${UBLOX_CC_INSTALL_PATH}/cmake/DocCleanupScript.cmake"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    endif ()
endif ()

install (
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ublox
    DESTINATION ${INC_INSTALL_DIR}
)

if (UBLOX_LIB_ONLY)
    return ()
endif ()    

if (CMAKE_COMPILER_IS_GNUCC)
    set (extra_flags_list
        "--std=c++11"
        "-Wall" "-Wextra" "-Werror" "-Wcast-align" "-Wcast-qual" "-Wctor-dtor-privacy"
        "-Wmissing-include-dirs" "-Wnoexcept" "-Wlogical-op" "-Wstrict-null-sentinel"
        "-Woverloaded-virtual" "-Wredundant-decls" "-Wshadow" "-Wundef" "-Wunused"
        "-Wno-unknown-pragmas" "-fdiagnostics-show-option"
    )
    
    string(REPLACE ";" " " extra_flags "${extra_flags_list}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")
elseif (MSVC)
    add_definitions( "/wd4503" "/wd4309" "/wd4267" "-D_SCL_SECURE_NO_WARNINGS")
endif ()

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(cc_plugin)

