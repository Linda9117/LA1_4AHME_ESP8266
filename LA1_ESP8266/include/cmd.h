/**
 * @file cmd.h
 * @author STEINBERGER
 * @date date
 * @version 0.0
 * @brief h-template
 *
 * Features: execute user comands
 *  
 * @copyright
 * Released under the Apache License, Version 2.0, January 2004.
 * http://www.apache.org/licenses/
 */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

/****************************************************/
// INCLUDES
/****************************************************/

#include <stdint.h>
#include "cli.h"

/****************************************************/
// GLOBAL DEFINES
/****************************************************/

/****************************************************/
// GLOBAL ENUMS
/****************************************************/

/****************************************************/
// GLOBAL STRUCT TYPE DEFINITION
/****************************************************/

/****************************************************/
// GLOBAL STATIC STRUCTS and VARIABLES
/****************************************************/

/****************************************************/
// GLOBAL MACROS
/****************************************************/

/****************************************************/
// GLOBAL FUNCTIONS
/****************************************************/

//execute commands defined by user
uint8_t cmdExecuteCommand(CliComPort *cliComPort);

#if defined(__cplusplus)
} // extern "C"
#endif
