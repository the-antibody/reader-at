#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#pragma once

#include <iostream>
#include <string>

// exception type enum
enum EXCEPTION_TYPE {
    INCORRECT_USAGE,
    FILE_NOT_FOUND
};

// public accessible
typedef enum EXCEPTION_TYPE EXCEPTION_TYPE;

// create exception class
class exception
{
    // private methods
    private:
        /**
         * @brief Converts an exception type enum value to a string
         * 
         * @param type - the type to convert
         */
        std::string to_string(EXCEPTION_TYPE type)
        {
            // the type
            switch (type)
            {
                case INCORRECT_USAGE:
                    return "INCORRECT_USAGE_EXCEPTION";
                    break;
                case FILE_NOT_FOUND:
                    return "FILE_NOT_FOUND_EXCEPTION";
                    break;
            }

            // failsafe
            return "NULL";
        }

    // public methods
    public:
        /**
         * @brief Construct a new exception object
         * 
         * @param message 
         * @param type 
         */
        exception(std::string message, EXCEPTION_TYPE type)
        {
            this->message = message;
            this->type = type;
        }

        // the message
        std::string message;

        // the type
        EXCEPTION_TYPE type;

        /**
         * @brief Throw the exception
         */
        void throw_exception()
        {
            std::cout << "Error: " << to_string(this->type) << std::endl << this->message << std::endl;
        }
};

#endif
