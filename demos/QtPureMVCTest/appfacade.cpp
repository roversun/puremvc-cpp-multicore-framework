#include "appfacade.h"
const string AppFacade::CHANGE_DATA = "Cmd_ChangeData";
const string AppFacade::GET_DATA = "Cmd_GetData";
AppFacade::AppFacade()
    : Facade(this, "ApplicationFacade")
{
    initializeController();
}
