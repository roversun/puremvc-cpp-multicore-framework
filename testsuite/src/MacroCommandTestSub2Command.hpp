//  MacroCommandTestSub2Command.hpp
//  PureMVC_C++ Test suite
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(MACRO_COMMAND_TEST_SUB2_COMMAND_HPP)
#define MACRO_COMMAND_TEST_SUB2_COMMAND_HPP

#include "MacroCommandTestVO.hpp"

namespace data
{
    using PureMVC::Patterns::SimpleCommand;
    using PureMVC::Patterns::INotification;
    /**
     * A SimpleCommand subclass used by MacroCommandTestCommand.
     */
    struct MacroCommandTestSub2Command: public SimpleCommand
    {
        MacroCommandTestSub2Command(void)
            :SimpleCommand()
        { }
        
        /**
         * Fabricate a result by multiplying the input by itself
         * 
         * @param event the <code>IEvent</code> carrying the <code>MacroCommandTestVO</code>
         */
        void execute(INotification const& note)
        {          
            MacroCommandTestVO& vo = *(MacroCommandTestVO*)note.getBody();
            // Fabricate a result
            vo.result2 = vo.input * vo.input;
        }
    };
}

#endif /* MACRO_COMMAND_TEST_SUB2_COMMAND_HPP */
