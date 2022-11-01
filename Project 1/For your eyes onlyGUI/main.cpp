#include "ForyoureyesonlyGUI.h"
#include <QtWidgets/QApplication>
#include "RepositoryFromTxt.h"
#include "Business.h"
#include "Validator.h"
#include "Records.h"
#include <memory>
#include "GUI.h"
#include "MemoryRepository.h"

using namespace std;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ifstream file("configuration.txt");
	string fileLocation,mylistLocation;

	if (file.is_open())
	{
		getline(file, fileLocation);
		if (fileLocation == "memory")
		{
			MemoryRepository repository{};
			getline(file, mylistLocation);
			Business business { repository };
			business.mylistFileLocation(mylistLocation);

			GUI gui{ business };
			gui.show();

			return a.exec();
		}
		else
		{
			FileRepository repository{};
			repository.setFileLocation(fileLocation);
			getline(file, mylistLocation);
			Business business{ repository };
			business.mylistFileLocation(mylistLocation);

			GUI gui{ business };
			gui.show();

			return a.exec();
		}
	}
}
