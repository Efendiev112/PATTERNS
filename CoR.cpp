#include <iostream>
#include <string>


using namespace std;

class BaseHandler {
protected:
	BaseHandler* next;
public:
	BaseHandler() : next(nullptr){}
	
	void setNext(BaseHandler* nextHandler) {
		next = nextHandler;
	}

	virtual void handleRequest(string request) {
		if (next) {
			next->handleRequest(request);
		}
		else {
			cout << "Request ("<<request<<") could not be handled"<<endl;
		}
	}
};



class SimpleRequestHandler : public BaseHandler {
public:
	void handleRequest(string request) {
		if (request == "simple") {
			cout << "SimpleRequestHandler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};


class ComplexRequestHandler : public BaseHandler {
	void handleRequest(string request) {
		if (request == "complex") {
			cout << "ComplexRequestHandler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};


class CriticalRequestHandler : public BaseHandler {
	void handleRequest(string request) {
		if (request == "critical") {
			cout << "CriticalRequestHandler handled the request" << endl;
		}
		else {
			BaseHandler::handleRequest(request);
		}
	}
};




int main()
{
	//simple->complex->critical
	SimpleRequestHandler* srh1 = new SimpleRequestHandler();
	ComplexRequestHandler* crh = new ComplexRequestHandler();
	CriticalRequestHandler* crith = new CriticalRequestHandler();
	srh1->setNext(crh);
	crh->setNext(crith);

	srh1->handleRequest("critical");

}

