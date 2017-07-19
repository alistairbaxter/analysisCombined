//
//  NumberListWriter.cpp
//  analyse
//
//  Created by Alistair Baxter on 18/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#include "NumberListWriter.hpp"

namespace analysis
{
    
    NumberListWriter::NumberListWriter(std::string filename)
    : m_outputFile(filename)
    {
        
    }
    
    NumberListWriter::~NumberListWriter()
    {
        m_outputFile.close();
    }
        
    bool NumberListWriter::isValid()
    {
        return m_outputFile.good();
    }
        
    AnalysisError NumberListWriter::writeNumber(int64_t number)
    {
        m_outputFile << number << std::endl;
        if (isValid())
            return Error_NoError;
        else
            return Error_WriteError;
    }
    
}
