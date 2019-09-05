#include <string>
//#include <Patterns/Facade/Facade.hpp>
//#include <Interfaces/IFacade.hpp>
//#include <Patterns/Command/MacroCommand.hpp>

#include <PureMVC.hpp>

#include <iostream>

using namespace std;

using namespace PureMVC::Patterns;


class ChangeDataCommand
	: public SimpleCommand
{
	void execute(INotification const& notification) override
	{
		//if (notification.getName().compare("Cmd_ChangeData") != 0)
		//	return;
		
		IProxy &proxy=(IProxy&)this->getFacade().retrieveProxy("class MyDataProxy");
		int *data = (int*)notification.getBody();
		cout << "ChangeDataCommand:" << notification.getName() << ":" << (int)(*data) << endl;
		proxy.setData(data);
	}
};

class StartupCommand
	: public SimpleCommand
{
	void execute(INotification const& notification) override
	{
		//Facade::retrieveProxy()
	}
};
class ExitCommand
	: public SimpleCommand
{	
	void execute(INotification const& notification) override
	{

	}
};

class MyDataProxy 
	: public Proxy
{
private:
	int m_data = 0;
public:
	MyDataProxy()
		:Proxy((void const*)&m_data)
	{
		//setProxyName(typeid(*this).name());
		_proxy_name = typeid(*this).name();

	}
	void setProxyName(std::string const& proxy_name)
	{
		_proxy_name = proxy_name;
	}
	void setData(void const* data) override
	{
		m_data += *(int*)data;

		Proxy::setData( &m_data);
		
		sendNotification("Msg_DataChanged", &m_data);
	}	
};

class MyMediator : public Mediator
{
public:
	MyMediator()
		: Mediator("MyMediator")
	{

	}
	Mediator::NotificationNames listNotificationInterests(void) const override
	{
		typedef StdContainerAggregate<std::list<NotificationNames::element_type::type> > result_t;
		result_t* result = new result_t;
		result->get().push_back("Msg_DataChanged");
		return NotificationNames(result);			
	}
	void handleNotification(INotification const& notification) override
	{
		std::string msg_txt = notification.getName();
		std::cout << "MyMediator:" << msg_txt << endl;
		if (msg_txt.compare("Msg_DataChanged") == 0)
		{
			int data = *(int*)notification.getBody();
			std::cout << "New_Data:" << data << endl;
		}
	}
	
};

class ApplicationFacade : public Facade
{
	friend class Facade;
public:
	static const string STARTUP;
	static const string EXIT;
	static const string CHANGE;
protected:
	ApplicationFacade(void)
		: Facade(this, "ApplicationFacade")
	{
		initializeController();
	}

public:
	static ApplicationFacade& getInstance(void)
	{
		if (Facade::hasCore("ApplicationFacade"))
			return *(dynamic_cast<ApplicationFacade*>(&Facade::getInstance("ApplicationFacade")));
		return *(new ApplicationFacade());
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
		ChangeDataCommand* changeCommand = new ChangeDataCommand();
		registerCommand(CHANGE, changeCommand);
		StartupCommand* startupCommand = new StartupCommand();
		registerCommand(STARTUP, startupCommand);
		ExitCommand* exitCommand = new ExitCommand();
		registerCommand(EXIT, exitCommand);
	}

	~ApplicationFacade()
	{
	}
};
const string ApplicationFacade::STARTUP = "startup";
const string ApplicationFacade::EXIT = "exit";
const string ApplicationFacade::CHANGE = "change";

#include <thread>
void main()
{
	ApplicationFacade& facade = ApplicationFacade::getInstance();

	MyDataProxy dataProxy;
	facade.registerProxy(&dataProxy);

	MyMediator myMediator;
	facade.registerMediator(&myMediator);

	std::cout << dataProxy.getProxyName()<< std::endl;

	for (int i = 0; i < 5; i++)
	{
		myMediator.sendNotification(ApplicationFacade::CHANGE, &i);
	}

	getchar();
		

	//facade.sendNotification(ApplicationFacade::EXIT);

}
