#include "Logger.h"

FILE* Logger::output = stdout;
ErrorLevel Logger::logLevel = ErrorLevel::INFO;