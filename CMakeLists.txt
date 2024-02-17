cmake_minimum_required(VERSION 3.27)

if (NOT DEFINED CMAKE_ANDROID_NDK)
    set(CMAKE_ANDROID_NDK D:/Android/SDK/ndk/26.1.10909125)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_ANDROID_NDK}/build/cmake/android.toolchain.cmake)
    set(CMAKE_SYSTEM_NAME Android)
    set(CMAKE_SYSTEM_VERSION 24)
    set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(ANDROID_ABI ${CMAKE_ANDROID_ARCH_ABI})
    set(ANDROID_PLATFORM android-26)
    set(ANDROID_NDK ${CMAKE_ANDROID_NDK})
endif ()

project(curl_android)

add_library(curl_android INTERFACE)
add_library(curl::curl_static ALIAS curl_android)

function(add_imported_library lib_name lib_path)
    add_library(${lib_name} STATIC IMPORTED)
    set_target_properties(${lib_name} PROPERTIES IMPORTED_LOCATION ${lib_path})
endfunction()

set(LIBS curl nghttp2 nghttp3 ngtcp2 ngtcp2_crypto crypto ssl)

foreach (lib ${LIBS})
    add_imported_library(${lib} ${CMAKE_CURRENT_SOURCE_DIR}/modules/${lib}_static/libs/android.${CMAKE_ANDROID_ARCH_ABI}/lib${lib}_static.a)
    target_include_directories(curl_android INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/modules/${lib}_static/include)
endforeach ()

target_link_libraries(curl_android INTERFACE
        curl
        nghttp2
        nghttp3
        ngtcp2
        ngtcp2_crypto
        crypto
        ssl
        z)

#[[
add_executable(main test/main.cpp)
target_link_libraries(main curl::curl_static)]]
