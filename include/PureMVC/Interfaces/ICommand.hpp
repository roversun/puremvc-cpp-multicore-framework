//  ICommand.hpp
//  PureMVC_C++
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(PUREMVC_INTERFACES_ICOMMMAND_HPP)
#define PUREMVC_INTERFACES_ICOMMMAND_HPP

// PureMVC include
#if !defined(PUREMVC_HPP)
#define PUREMVC_INCLUDE
#include "../PureMVC.hpp"
#endif /* PUREMVC_HPP */

#include "INotifier.hpp"
#include "INotification.hpp"

namespace PureMVC
{
    namespace Interfaces
    {
        /**
         * The interface definition for a PureMVC Command.
         *
         * @see Interfaces/INotification.hpp PureMVC::Interfaces::INotification
         */
        struct PUREMVC_API ICommand : public virtual INotifier
        {
            /**
             * Execute the <code>ICommand</code>'s logic to handle a given <code>INotification</code>.
             *
             * @param notification an <code>INotification</code> to handle.
             */
            virtual void execute(INotification const& notification) = 0;

            /**
             * Virtual destructor.
             */
            virtual ~ICommand(void);
        };
    }
}

#endif /* PUREMVC_INTERFACES_ICOMMMAND_HPP */
