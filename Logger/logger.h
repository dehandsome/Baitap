#ifndef LOGGER_H
#define LOGGER_H

#include<stdio.h>
#include<stdbool.h>

#define log_message(level, format, ...)

typedef enum{
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} LogLevel;

bool logger_init(LogLevel min_level, const char *log_file_path);
void logger_cleanup();
void logger_set_level(LogLevel level);
void logger_log(LogLevel level, const char *file, int line, const char *format, ...);


#endif