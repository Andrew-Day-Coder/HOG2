#pragma once

#include <stdio.h>

enum class ErrorLevel
{
  INFO,
  WARNING,
  CRITICAL,
};
/**
 * A really basic logging class
 * makes it so that errors that happen
 * during competition can be shown 
 * and reviewed
 */
class Logger
{
  private:
    static FILE* output;
    static ErrorLevel logLevel;
  public:
    /**
     * sets the output file of the logging system, 
     * makes it easy to switch from the terminal stdout
     * and a file on the sd card
     * 
     * @param file the output stream to use
     */
    static void setOutputFile(FILE* file)
    {
      output = file;
    }
    /**
     * Limits the number of errors printed simply
     * by setting a minimum importance for the error
     * to output.
     */
    static void setLogLevel(ErrorLevel level){ logLevel = level; }

    /**
     * Logs errors to an output stream such as stdout, or another file
     *
     * @param level the logging level
     * @param msg the message to be put into the stream
     *
     */
    static void log(ErrorLevel level, const char* msg, ...)
    {
      if (output == nullptr)
      {
        output = stdout;
        Logger::log(ErrorLevel::INFO, "No output file specified, using stdout\n");
      }

      // handle variatic arguemnts, taken from gcc definition of printf
      va_list arg;
      va_start(arg, msg);

      if (level == ErrorLevel::CRITICAL)
      {
        fputs("[CRITICAL]: ", output);
        fprintf(output,msg, arg);
      }
      else if (level == ErrorLevel::WARNING)
      {
        if (logLevel == ErrorLevel::INFO || logLevel == ErrorLevel::WARNING)
        {
          fputs("[WARNING]: ", output);
          fprintf(output,msg, arg);
        }
      }
      else if (logLevel == ErrorLevel::INFO && level == ErrorLevel::INFO)
      {
        fputs("[INFO]: ", output);
        fprintf(output,msg, arg);
      }
      va_end(arg);
    }
};