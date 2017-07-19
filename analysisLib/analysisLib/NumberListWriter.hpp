//
//  @file NumberListWriter.hpp
//  Number File Writer Class
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#ifndef NumberListWriter_hpp
#define NumberListWriter_hpp

#include <stdio.h>

#include <fstream>
#include "analyse.hpp"

namespace analysis
{
    
    /**
     *  @brief Class that writes a list of whole numbers from a text file.
     *
     * The resulting file will contain a list of return-delimited whole numbers
     * stored from 64-bit signed integers.
     *
     * The file is opened automatically upon construction, and closed
     * automatically on destruction of the instance of this class.
     */
    class NumberListWriter
    {
    public:
        /**
         * Open the file with the given filename for writing
         *
         * @param filename The name of the file to open
         */
        NumberListWriter(std::string filename);
        
        /**
         * Closes the file being written to
         */
        virtual ~NumberListWriter();
        
        /**
         * Has the output file been successfully opened for parsing
         *
         * @return true if there have been no file errors, false otherwise
         */
        bool isValid();
        
        /**
         * Writes a whole number to the file
         *
         * @param number The number to be written
         * @return Error_NoError on success, Error_WriteError if there was a
         *         problem when writing to the file
         */
        AnalysisError writeNumber(int64_t number);
        
    protected:
        std::ofstream m_outputFile;
    };
    
}

#endif /* NumberListWriter_hpp */
