#pragma once

#include <cstdio>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define NAVIO2 3
#define NAVIO 1

inline int write_file(const char *path, const char *fmt, ...)
{
    errno = 0;

    int fd = ::open(path, O_WRONLY | O_CLOEXEC);
    if (fd == -1) {
        return -errno;
    }

    va_list args;
    va_start(args, fmt);

    int ret = ::vdprintf(fd, fmt, args);
    int errno_bkp = errno;
    ::close(fd);

    va_end(args);

    if (ret < 1) {
        return -errno_bkp;
    }

    return ret;
}

inline int read_file(const char *path, const char *fmt, ...)
{
    errno = 0;

    FILE *file = ::fopen(path, "re");
    if (!file)
        return -errno;

    va_list args;
    va_start(args, fmt);

    int ret = ::vfscanf(file, fmt, args);
    int errno_bkp = errno;
    ::fclose(file);

    va_end(args);

    if (ret < 1)
        return -errno_bkp;

    return ret;
}

inline bool check_apm()
{
    int ret =  system("ps -AT | grep -c ap-timer > /dev/null");

    if (WEXITSTATUS(ret) <= 0) {
        fprintf(stderr, "APM is running. Can't launch the example\n");
        return true;
    }

    return false;
}

inline int get_navio_version()
{
    int version;
    read_file("/sys/firmware/devicetree/base/hat/product_id", "%x",&version);
    return version;
}
