# curl-android

#### Usage

```cmake
include(FetchContent)

FetchContent_Declare(
        curl_android
        GIT_REPOSITORY https://github.com/enenH/curl-android.git
        GIT_TAG v8.6.0
)

FetchContent_MakeAvailable(curl_android)


target_link_libraries(your_lib_name curl::curl_static)

```

#### Credits
https://github.com/vvb2060/curl-android