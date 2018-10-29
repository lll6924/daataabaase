#include "bufmanager/BufPageManager.h"
#include "fileio/FileManager.h"
#include "utils/pagedef.h"
#include "RecordManager.h"
#include <iostream>

using namespace std;

int main() {
	MyBitMap::initConst();
	FileManager* fm = new FileManager();
	BufPageManager* bpm = new BufPageManager(fm);
	RecordManager* rm=new RecordManager(fm,bpm);
	return 0;
}
