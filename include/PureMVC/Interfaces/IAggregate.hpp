//  IAggregate.hpp
//  PureMVC_C++
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(PUREMVC_INTERFACES_IAGGREGATE_HPP)
#define PUREMVC_INTERFACES_IAGGREGATE_HPP

// STL include
#include <memory>
#include <utility>
// PureMVC include
#if !defined(PUREMVC_HPP)
#define PUREMVC_INCLUDE
#include "../PureMVC.hpp"
#endif /* PUREMVC_HPP */

#include "IIterator.hpp"

namespace PureMVC
{
    namespace Interfaces
    {
        /**
         * Interface of aggregate class.
         */
        template<typename _Type>
        struct IAggregate
        {
            typedef _Type type;

#if defined(PUREMVC_USES_TR1)
            typedef std::unique_ptr<IIterator<_Type> > Iterator;
#else
            typedef std::auto_ptr<IIterator<_Type> > Iterator;
#endif

            /**
             * Set item collection from this to iterator.
             *
             * @param [out] iterator container.
            **/
            virtual void setIterator(IIterator<_Type>& iterator) const = 0;

            /**
             * Get iterator collection.
             *
             * @return The auto pointer of iterator.
            **/
            virtual Iterator getIterator(void) const = 0;

            /**
             * Virtual destructor.
             */
            virtual ~IAggregate() { };
        };
    }
}

#endif /* PUREMVC_INTERFACES_IAGGREGATE_HPP */
