// cppmtag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <filesystem>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "taglib\fileref.h"
#include "taglib\tag.h"
#include "taglib\tpropertymap.h"

using namespace std;
namespace fs = std::experimental::filesystem;


int main(int argc, char *argv[]) //User must pass full path
{
	string path = argv[1];		// Save full directory path name as string
	ifstream in;				// Create an input file stream.
	TagLib::Tag *tag = NULL;			// Initialize tag
	
	for (auto & p : fs::directory_iterator(path)) {		//Iterate through files in given path
		cout << p << endl;
		/*
		in.open(p.path().string());						//Open path as stream
		const char *cstr = p.path().string().c_str();	//Convert path to c-string 
		TagLib::FileRef f(cstr);						//Create FileRef
		if (!f.isNull() && f.tag()) {					//Parse and print tags if it is a valid audio file

			TagLib::Tag *tag = f.tag();

			cout << "title   - \"" << tag->title() << "\"" << endl;
			cout << "artist  - \"" << tag->artist() << "\"" << endl;
			cout << "album   - \"" << tag->album() << "\"" << endl;
			cout << "year    - \"" << tag->year() << "\"" << endl;
			cout << "track   - \"" << tag->track() << "\"" << endl;
			

		}
		in.close();										//Close the stream
		*/
	}

		
	

	//system("PAUSE");
	return 0;
}


