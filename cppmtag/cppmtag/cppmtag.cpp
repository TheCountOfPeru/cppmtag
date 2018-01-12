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
	ofstream o("tracklist.txt");				// Create an input file stream.
	TagLib::Tag *tag = NULL;			// Initialize tag
	string temp;
	
	if (o.is_open()) {
		o << "Tracklist" << endl;
		for (auto & p : fs::directory_iterator(path)) {		//Iterate through files in given path


			//in.open(p.path().string());					//Open path as stream
			temp = p.path().string();						//
			replace(temp.begin(), temp.end(), '\\', '/');	//Fileref needs slashes reversed.
			const char *cstr = temp.c_str();				//Convert path to c-string 
			TagLib::FileRef f(cstr);						//Create FileRef

			if (!f.isNull() && f.tag()) {					//Parse and print tags if it is a valid audio file

				TagLib::Tag *tag = f.tag();
				o << tag->track() << ". " << tag->title() << endl;

				/*
				cout << "title   - \"" << tag->title() << "\"" << endl;
				cout << "artist  - \"" << tag->artist() << "\"" << endl;
				cout << "album   - \"" << tag->album() << "\"" << endl;
				cout << "year    - \"" << tag->year() << "\"" << endl;
				cout << "track   - \"" << tag->track() << "\"" << endl;
				*/

			}
			//Close the stream
//in.close();
		}
	}
	else if (!o.is_open()) {
		cout << "Error" << endl;
	}
	o.close();
	return 0;
}


