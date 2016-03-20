//============================================================================
// Name        : Main.cpp
// Author      : Dishan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	return 0;
}

extern "C" int ProcessRequest(char* request, char* method, char* body, char**headers, int hederCount, char** out_response) {

	ostringstream hederCountString;
	hederCountString << hederCount;

	std::string* requestString = new std::string();
	requestString->append("{ \"request\" : \"");
	requestString->append(request);
	requestString->append("\" , \"method\" :\"");
	requestString->append(method);
	requestString->append("\" , \"hederCount\" :");
	requestString->append(hederCountString.str());
	requestString->append(" ,\n\"headers\" :[");

	for(int i=0;i<hederCount;i++)
	{
		if(i!=0)
		{
			requestString->append(" , ");
		}
		requestString->append("\"");
		requestString->append(headers[i]);
		requestString->append("\"");
	}


	requestString->append("]\n , \"body\" :");
	requestString->append(body);
	requestString->append(" }");

	*out_response = (char*) requestString->c_str();
	return 200;
}
