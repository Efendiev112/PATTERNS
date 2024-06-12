#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class serviceInterface {
public:
	virtual void operation() = 0;
};


class Service : public serviceInterface {
private:
	string path;
	string date;
	
public:

	string getdate() {
		this->date = date;
	}

	string getPath() {
		this->path = path;
	}

	void operation() {

	}
	vector <string> DownloadByID(int id) {
		vector <string> VideoID;
		int index = 0;
		ifstream in("file.txt");
		if (in.is_open()) {
			string input;
			while (true)
			{
				(getline(in, input));
				if (index == id) {
					cout << input << " " << endl;
				}
			}
		}
		return VideoID;
	}
	
	

	vector <string> DownloadVideo() {
		vector <string> video;
		ifstream in("file.txt");
		string input;
		if (in.is_open()) {
			while (getline(in, input)) {
				video.push_back(input);
				
			}
			return video;

		}
		
	}

	void GetDate() {
		ifstream in("file.txt");
		if (in.is_open()) {
			string input;
			getline(in, input);
			cout << input << " " << endl;
			
		}
	}
	



};

class Proxy : public serviceInterface {
private:
	Service* realService;
	bool checkAccess() {
		return true;
	}

public: 

	Proxy(Service* realService) : realService(realService) {}

	void operation() override {
		cout << "Proxy Handling request" << endl;
		int pass;
		cin >> pass;
		if (checkAccess()) {
			
		}
	}
};


int main()
{

	Service* realService = new Service;
	Proxy proxy(realService);


	vector<string> yy = realService->DownloadVideo();
	





}





