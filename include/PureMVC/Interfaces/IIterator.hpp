//  IIterator.hpp
//  PureMVC_C++
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(PUREMVC_INTERFACES_IITERATOR_HPP)
#define PUREMVC_INTERFACES_IITERATOR_HPP

// PureMVC include
#if !defined(PUREMVC_HPP)
#define PUREMVC_INCLUDE
#include "../PureMVC.hpp"
#endif /* PUREMVC_HPP */

namespace PureMVC
{
    namespace Interfaces
    {
        /**
         * Interface of iterator class
         */
        template<typename _Type>
        struct IIterator
        {
            typedef _Type type;

            /**
             * Gets the current item.
             *
             * @return The references of current item.
            **/
            virtual _Type const& getCurrent(void) const = 0;

            /**
             * Gets the current item base on operator.
             *
             * @return The references of current item.
            **/
            virtual _Type const& operator*(void) const = 0;

            /**
             * Move to next item.
             *
             * @return true if it succeeds, false if it fails. 
            **/
            virtual bool moveNext(void) const = 0;

            /**
             * Reset iterator.
            **/
            virtual void reset(void) const = 0;

            /**
             * Virtual destructor.
             */
            virtual ~IIterator(void) { };
        };
    }
}

#endif /* PUREMVC_INTERFACES_IITERATOR_HPP */
