#ifndef APPFACADE_H
#define APPFACADE_H

#include "common.h"
#include "changedatacommand.h"
#include "getdatacommand.h"

class AppFacade : public Facade
{
    friend class Facade;
protected:
    AppFacade();
public:
    static const string CHANGE_DATA;
    static const string GET_DATA;

public:
    static AppFacade& getInstance(void)
    {
        if (Facade::hasCore("ApplicationFacade"))
            return *(dynamic_cast<AppFacade*>(&Facade::getInstance("ApplicationFacade")));
        return *(new AppFacade());
    }

protected:
    virtual void initializeNotifier(string const& key)
    {
        Facade::initializeNotifier(key);
    }
    virtual void initializeFacade()
    {
        Facade::initializeFacade();
    }

    virtual void initializeController(void)
    {
        Facade::initializeController();
        //ChangeDataCommand* changeCommand = new ChangeDataCommand();
        registerCommand(CHANGE_DATA, new ChangeDataCommand());
        registerCommand(GET_DATA, new GetDataCommand());
    }

    ~AppFacade()
    {
    }
};

#endif // APPFACADE_H
