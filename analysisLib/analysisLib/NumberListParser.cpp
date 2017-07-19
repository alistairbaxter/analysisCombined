//
//  NumberListParser.cpp
//  analyse
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#include "NumberListParser.hpp"

namespace analysis
{
    NumberListParser::NumberListParser(std::string filename)
    : m_inputFile(filename)
    {
    }
    
    NumberListParser::~NumberListParser()
    {
        m_inputFile.close();
    }
    
    AnalysisError NumberListParser::getNextNumber(int64_t &nextNumber)
    {
        std::string line;
        
        if (getline (m_inputFile ,line) )
        {
            //check if the string represents a valid number
            for (char currChar : line)
            {
                if (currChar != '-' && currChar != ' ')
                {
                    if (currChar < '0' || currChar > '9')
                    {
                        return Error_InvalidNumber;
                    }
                }
            }
            
            // Convert the line to a whole number
            nextNumber = atoll(line.c_str());
        }
        else
        {
            return Error_ReadError;
        }

        return Error_NoError;
    }

    bool NumberListParser::isValid()
    {
        return m_inputFile.good();
    }
    
    bool NumberListParser::numbersRemaining()
    {
        if (!isValid())
            return false;
        
        // read past the end of the last line
        m_inputFile.get();
        if (!m_inputFile.eof())
            m_inputFile.unget();
        
        return !m_inputFile.eof();
    }


}
