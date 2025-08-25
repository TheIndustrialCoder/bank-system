#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"
using namespace std;

class FileManager : public DataSourceInterface
{
public:
	static void RemoveAllClients() {
		FileHelper::clearFile("Clients.txt", "ClientsLastIdUsed.txt");
	}
};

