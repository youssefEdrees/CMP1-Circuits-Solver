#include "pch.h"
#include "Utility.h"

using namespace std;

Utility::Utility()
{
}

//string Utility::fileDialog() { // http://www.cplusplus.com/forum/windows/169960/
//	const int BUFSIZE = 1024;
//	char buffer[BUFSIZE] = { 0 };
//	OPENFILENAME ofns = { 0 };
//	ZeroMemory(&buffer, sizeof(buffer));
//	ZeroMemory(&ofns, sizeof(ofns));
//	ofns.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
//
//	ofns.lStructSize = sizeof(ofns);
//
//	//wchar_t wtext[1024];
//	//mbstowcs_s(wtext, buffer, strlen(buffer)+1);
//
//	ofns.lpstrFile = /*wtext*/ LPWSTR(buffer);
//	ofns.nMaxFile = BUFSIZE;
//	ofns.lpstrFilter = _T("Text Files (*.txt)\0*.txt\0");
//	ofns.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_CREATEPROMPT;
//
//	// A solution to the previous problem adressed in commit 59788d4267a2b73950dbb8d630eacaa13fa969ed https://stackoverflow.com/questions/50468051/how-to-prevent-getopenfilename-from-changing-the-current-directory-while-the-dia
//
//	TCHAR g_BackupDir[MAX_PATH];
//	GetCurrentDirectory(ARRAYSIZE(g_BackupDir), g_BackupDir);
//	////////////////////////////
//
//	
//	ofns.lpstrTitle = _T("Open");
//	GetOpenFileName(&ofns);
//	
//	SetCurrentDirectory(g_BackupDir);
//	return buffer;
//}

void Utility::load(string path, vector<Element>* elements, vector<Element>* voltageSources)
{

	cout << path;

	ifstream myfile(path);
	//myfile.open(Utility::fileDialog());
	if (myfile.is_open()) {

		float frequency;

		string line;

		for (int i = 0; getline(myfile, line); i++) {
			cout << line << "\n";

			if (i == 0) frequency = stof(line);


			string word;
			istringstream stream(line);
			for (int j = 0; stream >> word; j++) {

			}

		}

		myfile.close();
	}
}


Utility::~Utility()
{
}
