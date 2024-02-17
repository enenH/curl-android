#include <cstdio>
#include <curl/curl.h>

int main() {
    printf("Hello, World! %s", curl_version());
    return 0;
}