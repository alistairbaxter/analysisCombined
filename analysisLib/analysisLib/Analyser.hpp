//
//  Analyser.hpp
//  analyse
//
//  Created by Alistair Baxter on 17/07/2017.
//  Copyright © 2017 Alistair Baxter. All rights reserved.
//

#ifndef Analyser_hpp
#define Analyser_hpp

#include <vector>


namespace analysis
{
    /**
     *  @brief Class that maintains a list of whole numbers, and can perform
     *         various forms of analysis on them.
     */
    class Analyser
    {
    public:
        /**
         * Default constructor
         */
        Analyser();
        
        /**
         * Destructor
         */
        virtual ~Analyser();
        
        /**
         * Add a new whole number to the list.
         * 
         * @param[in] newNumber Number to add.
         */
        void addWholeNumber(int64_t newNumber);
 
        /**
         * Determine whether the numbers are valid for analysis.
         *
         * If there has been a maths overflow during summation,
         * or if a number could not be added to the list, or the
         * list is empty, then it will not be considered valid.
         *
         * @return Whether or not the list is valid for analysis.
         */
        bool isAnalysisValid();
        
        /**
         * Provides a count of the numbers in the list
         *
         * @return The number of numbers in the list.
         */
        size_t count();
        
        /**
         * The sum of the numbers in the list.
         *
         * @return Sum of the numbers in the list.
         */
        int64_t sum();
        
        /**
         * The average value of the values in the list
         *
         * @return Average of the numbers in the list.
         */
        int64_t average();
        
    protected:
        
        // The list of numbers
        std::vector<int64_t> m_numbers;
        
        // Running total of the sum
        int64_t m_sum;
        
        // Whether or not there have been any problems that invalidate analysis
        bool m_sumValid;
    };
    
} // namespace analyse


#endif /* Analyser_hpp */
