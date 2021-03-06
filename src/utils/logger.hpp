#pragma once

#define SPDLOG_FMT_EXTERNAL
#define FMT_HEADER_ONLY
#include "spdlog/spdlog.h"


#define log_debug(...) (spdlog::debug(__VA_ARGS__))
#define log_info(...) (spdlog::info(__VA_ARGS__))
#define log_error(...) (spdlog::error(__VA_ARGS__))
