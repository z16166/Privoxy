cmake_minimum_required(VERSION 3.15)
set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")
project(privoxy C)

# Set MSVC Runtime Library to static (/MT or /MTd)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(CMAKE_C_STANDARD 99)

if(MSVC)
    add_compile_definitions(
        _WIN32 WIN32 
        _CRT_SECURE_NO_WARNINGS 
        _WINSOCK_DEPRECATED_NO_WARNINGS 
        _AMD64_=1
    )
endif()

find_package(PCRE2 REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

add_definitions(-DHAVE_CONFIG_H -D_REENTRANT)

# Main console application sources
set(SRCS 
    actions.c cgi.c cgiedit.c cgisimple.c client-tags.c deanimate.c 
    encode.c errlog.c filters.c gateway.c jbsockets.c jcc.c list.c loadcfg.c 
    loaders.c miscutil.c parsers.c pcrs.c ssplit.c urlmatch.c win32.c w32log.c w32svrapi.c w32taskbar.c w32.rc
    ssl_common.c openssl.c
)

add_executable(privoxy WIN32 ${SRCS})
target_include_directories(privoxy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(privoxy PRIVATE PCRE2::8BIT PCRE2::POSIX OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB ws2_32.lib crypt32 comctl32.lib)
