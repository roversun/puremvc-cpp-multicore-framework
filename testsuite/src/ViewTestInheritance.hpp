//  ViewTestInheritance.hpp
//  PureMVC_C++ Test suite
//
//  PureMVC Port to C++ by Tang Khai Phuong <phuong.tang@puremvc.org>
//  PureMVC - Copyright(c) 2006-2011 Futurescale, Inc., Some rights reserved.
//  Your reuse is governed by the Creative Commons Attribution 3.0 License
//

#if !defined(VIEW_TEST_HERITANCE_HPP)
#define VIEW_TEST_HERITANCE_HPP

#include <PureMVC/PureMVC.hpp>

namespace data
{
    using PureMVC::Interfaces::IView;
    using PureMVC::Core::View;

    class ViewTestInheritance 
        : public virtual IView
        , public View
    {
        friend class View;
    public:
        std::string* initializeViewCalled;
    protected:
        ViewTestInheritance(void)
        :View(this, "ViewTestInheritance")
        { }
    public:
        static ViewTestInheritance& getInstance(void)
        {
            if (View::find("ViewTestInheritance") == NULL)
                new ViewTestInheritance();
            return *(dynamic_cast<ViewTestInheritance*>(&View::getInstance("ViewTestInheritance")));
        }
    protected:
        void initializeView(void)
        {
            initializeViewCalled = new std::string("Called!!!");
            View::initializeView();
        }
    public:
        ~ViewTestInheritance()
        {
            delete initializeViewCalled;
        }
    };
}

#endif /* VIEW_TEST_HERITANCE_HPP */
