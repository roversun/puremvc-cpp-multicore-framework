#ifndef CHANGEDATACOMMAND_H
#define CHANGEDATACOMMAND_H

#include "common.h"

class ChangeDataCommand : public SimpleCommand
{
public:
    ChangeDataCommand();

    void execute(INotification const& notification) override;
};

#endif // CHANGEDATACOMMAND_H
