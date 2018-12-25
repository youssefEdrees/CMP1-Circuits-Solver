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

void Utility::load(string path,
	int& numOfNodes,
	Element ** elements,
	int& sizeOfElements,
	Element ** voltageSources,
	int& sizeOfVoltageSources)
{

	cout << path;
	
	float frequency;

	ifstream myfile(path);
	//myfile.open(Utility::fileDialog());
	if (myfile.is_open()) {		

		string line;
		string words[10];

		int i;
		for (i = 0; getline(myfile, line); i++) {
			cout << line << "\n";

			if (i == 0) numOfNodes = stof(line);
			else if (i == 1) frequency = stof(line);
			else {
				string w;
				istringstream stream(line);
				for (int j = 0; stream >> w; j++) {
					words[j] = w;
				}
			}
		}

		if (i > 1)
			translateLine(words, 
				frequency, 
				elements, 
				sizeOfElements, 
				voltageSources, 
				sizeOfVoltageSources);

		myfile.close();
	}
}

void Utility::translateLine(string words[], 
	float freq, 
	Element ** elements,
	int& sizeOfElements,
	Element ** voltageSources,
	int& sizeOfVoltageSources) {

	sizeOfElements = 0;
	sizeOfVoltageSources = 0;

	Element* e = new Element(words[0], stof(words[1]), stof(words[2]));

	if (words[0].at(0) == 'R') {
		e->initResistor(stof(words[3]), freq);
	}
	else if (words[0].at(0) == 'C') {
		e->initCapacitor(stof(words[3]), freq);
	}
	else if (words[0].at(0) == 'L') {
		e->initInductor(stof(words[3]), freq);
	}
	else if (words[0].at(0) == 'V') {
		e->initVS(stof(words[3]), stof(words[4]), freq);
		voltageSources[sizeOfVoltageSources++] = e;
	}
	else if (words[0].at(0) == 'I') {
		e->initCS(stof(words[3]), stof(words[4]), freq);
	}
	else if (words[0].at(0) == '_' || 
		words[0].at(0) == '-') { // Depends on current.
		if (words[0].at(1) == 'V') {
			e->initCCVS(words[4], stof(words[3]));
			voltageSources[sizeOfVoltageSources++] = e;
		}
		else if (words[0].at(1) == 'I') {
			e->initCCCS(words[4], stof(words[3]));
		}
	}
	else if (words[0].at(0) == '=') { // Depends on voltage.
		if (words[0].at(1) == 'V') {
			e->initVCVS(stof(words[4]), stof(words[5]), stof(words[3]));
			voltageSources[sizeOfVoltageSources++] = e;
		}
		else if (words[0].at(1) == 'I') {
			e->initVCCS(stof(words[4]), stof(words[5]), stof(words[3]));
		}
	}

	elements[sizeOfElements++] = e;

}

Utility::~Utility()
{
}
