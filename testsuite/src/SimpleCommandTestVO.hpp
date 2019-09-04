//  SimpleCommandTestVO.hpp
//  PureMVC_C++ Test suite
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(SIMPLE_COMMAND_TEST_VO_HPP)
#define SIMPLE_COMMAND_TEST_VO_HPP

namespace data
{
    /**
     * A utility class used by SimpleCommandTest.
     */
    struct SimpleCommandTestVO
    {
        int input;
        int result;
        /**
         * Constructor.
         * 
         * @param input the number to be fed to the SimpleCommandTestCommand
         */
        SimpleCommandTestVO(int input)
        {
            this->input = input;
            this->result = 0;
        }
    };
}

#endif /* SIMPLE_COMMAND_TEST_VO_HPP */
