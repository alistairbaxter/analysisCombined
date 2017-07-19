//
//  @file NumberListParser.hpp
//  Number File Parser Class
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#ifndef NumberListParser_hpp
#define NumberListParser_hpp

#include <fstream>
#include "analyse.hpp"

namespace analysis
{
    /**
     *  @brief Class that parses a list of whole numbers from a text file.
     *
     * The file must contain only a list of return-delimited whole numbers
     * which are capable of being stored in 64-bit signed integers.
     *
     * The file is opened automatically upon construction, and closed 
     * automatically on destruction of the instance of this class.
     */
    class NumberListParser
    {
    public:
        /**
         * Open the file with the given filename for parsing
         *
         * @param filename The name of the file to open
         */
        NumberListParser(std::string filename);
        
        /**
         * Closes the file being read from
         */
        virtual ~NumberListParser();
        
        /**
         * Has the input file been successfully opened for parsing
         *
         * @return true if there have been no file errors, false otherwise
         */
        bool isValid();
        
        /**
         * Parses a whole number from the file
         *
         * @param nextNumber The number to be parsed in to
         * @return Error_NoError on success, Error_InvalidNumber if the number 
         *         is incorrectly formatted, Error_ReadError if there was a 
         *         problem when reading from the file
         */
        AnalysisError getNextNumber(int64_t &nextNumber);
        
        /**
         * Determines whether there are more numbers remaining to be parsed
         * 
         * @return true if there are more numbers, false otherwise.
         */
        bool numbersRemaining();
        
    protected:
        std::ifstream m_inputFile;
    };
    
}

#endif /* NumberListParser_hpp */
