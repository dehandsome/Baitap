#include<time.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
#include"logger.h"

#define MAX_LOG_MESSAGE_LEN 1024

static LogLevel current_level = LOG_INFO;
static FILE *log_file = NULL;
static bool log_to_file = false;

static const char *level_strings[] = {
    "EMERGENCY", "ALERT", "CRITICAL", "ERROR",
    "WARNING", "NOTICE", "INFO", "DEBUG"
};

bool logger_init(LogLevel min_level, const char *log_file_path) {
    current_level = min_level;

    if (log_file_path != NULL) {
        log_file = fopen(log_file_path, "a");
        if (log_file == NULL) {
            fprintf(stderr, "Failed to open log file: %s\n", log_file_path);
            return false;
        }
        log_to_file = true;
    }

    return true;
}

void logger_cleanup() {
    if (log_to_file && log_file != NULL) {
        fclose(log_file);
        log_file = NULL;
    }
    log_to_file = false;
}

void logger_set_level(LogLevel level) {
    current_level = level;
}

static void get_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

void logger_log(LogLevel level, const char *file, int line, const char *format, ...) {
    if (level > current_level) {
        return;
    }

    char timestamp[20];
    get_timestamp(timestamp, sizeof(timestamp));

    char user_msg[MAX_LOG_MESSAGE_LEN];
    va_list args;
    va_start(args, format);
    vsnprintf(user_msg, sizeof(user_msg), format, args);
    va_end(args);

    char final_msg[MAX_LOG_MESSAGE_LEN];
    snprintf(final_msg, sizeof(final_msg), "[%s] [%s] [%s:%d] - %s\n",
             timestamp, level_strings[level], file, line, user_msg);

    // Ghi ra console
    FILE *out = (level <= LOG_ERROR) ? stderr : stdout;
    fputs(final_msg, out);
    fflush(out);

    // Ghi ra file nếu có
    if (log_to_file && log_file != NULL) {
        fputs(final_msg, log_file);
        fflush(log_file);
    }
}