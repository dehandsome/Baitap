#include "logger.h"

int main() {
    // Khởi tạo logger: ghi từ mức LOG_INFO trở lên, ghi log ra file "log.txt"
    if (!logger_init(LOG_INFO, "log.txt")) {
        return 1;
    }

    // Các ví dụ ghi log
    log_message(LOG_DEBUG, "This is a debug message (should not be shown at current level).");
    log_message(LOG_INFO, "Starting application...");
    log_message(LOG_WARNING, "Low disk space.");
    log_message(LOG_ERROR, "Failed to load configuration file.");
    log_message(LOG_CRITICAL, "Critical failure detected.");

    // Thay đổi mức lọc về DEBUG và log thêm
    logger_set_level(LOG_DEBUG);
    log_message(LOG_DEBUG, "Now DEBUG level messages will be shown.");

    // Kết thúc
    logger_cleanup();
    return 0;
}
