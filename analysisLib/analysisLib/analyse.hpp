/*
 * @file analyse.hpp
 * Main Header for Analysis Library
 *
 *  Created by Alistair Baxter on 17/07/2017.
 *  Copyright © 2017 Alistair Baxter. All rights reserved.
 *
 */

#ifndef analyse_
#define analyse_

/* The classes below are exported */
#pragma GCC visibility push(default)

namespace analysis
{
    
/**
 * @enum AnalysisError
 * @brief Error return types for the analysis library
 */
enum AnalysisError
{
    Error_NoError               =  0, /**< No error, function was successful */
    Error_InputFileInvalid      = -1, /**< An error occurred when trying to open the input file */
    Error_ReadError             = -2, /**< An error occurred when reading from the input file */
    Error_InvalidNumber         = -3, /**< The input file contained a line which was not a whole number */
    Error_InvalidAnalyis        = -4, /**< The list of numbers was not valid for analysis */
    Error_OutputFileInvalid     = -5, /**< There was a problem when opening the output file */
    Error_WriteError            = -6  /**< There was a problem when writing to the output file */
};

}

extern "C"
{
    /**
     * Perform Analysis on a list of numbers read from a specified file, and
     * write the results to another specified file.
     *
     * Each line in the input file must be a standalone whole number.
     *
     * In the output file:
     * The count of the numbers read will be written to a line.
     * The sum of the numbers read will be written to a line.
     * The average of the numbers will be written read to a line.
     *
     * @param input Filename for the file containing a lit of numbers to be read from.
     * @param output Filename for the file to which results will be written.
     *
     * @return 0 if the operation was successful, or a negative number otherwise
     */
    int analyse(const char * input, const char * output);
}

#pragma GCC visibility pop
#endif
