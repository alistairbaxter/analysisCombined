//
//  Analyser.cpp
//  analyse
//
//  Created by Alistair Baxter on 17/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#include "Analyser.hpp"

namespace analysis
{
    Analyser::Analyser()
        : m_sumValid(true),
          m_sum(0)
    {
    }
    
    Analyser::~Analyser()
    {
    }
    
    void Analyser::addWholeNumber(int64_t newNumber)
    {
        size_t oldCount = count();
        
        m_numbers.push_back(newNumber);
        
        // Detect problem adding to vector
        if (count() != (oldCount+1))
            m_sumValid = false;
        
        int64_t oldSum = m_sum;
        
        m_sum += newNumber;
        
        // detect underflow
        if (newNumber < 0 && m_sum > oldSum)
            m_sumValid = false;
        
        // detect overflow
        else if (newNumber > 0 && m_sum < oldSum)
            m_sumValid = false;
    }
    
    int64_t Analyser::average()
    {
        return m_sum / count();
    }
    
    int64_t Analyser::sum()
    {
        return m_sum;
    }
    
    size_t Analyser::count()
    {
        return m_numbers.size();
    }
    
    bool Analyser::isAnalysisValid()
    {
        return (count() > 0) && m_sumValid;
    }
    
    
} // namespace analyse
