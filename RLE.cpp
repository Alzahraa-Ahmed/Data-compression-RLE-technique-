//============================================================================
// Name        : RLE.cpp
// Author      : alzahraa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void RLE_Compression();
void RLE_Decompression();

int main() {
	RLE_Compression();
	RLE_Decompression();
	return 0;
}

void RLE_Compression(){
	    string s;
		int count;
		ifstream input("html.txt");
		ofstream  output ("compressed.txt");

		while(!input.eof()){

			getline(input,s); //takes line by line from the input file

		    for(int i=0;i<(int)s.length();++i){
			    count=1;
			   while(s[i]==s[i+1]){
				count++;
				i++;
			}
			if(count<=3){
			while(count>0){
				output<<s[i];
				count--;
			}// undo compression if the num of char less than or equal 3

			}
			else
			output<<"@"<<count <<s[i]; //compress

		}
		output<<endl;

		}
	input.close();
	output.close();

}

void RLE_Decompression(){
	   string s ;
	   ifstream input("compressed.txt") ;
	   ofstream output("extended.txt") ;

	  if (!input.is_open())
			input.open("compressed.txt", ios::in);

	   while(!input.eof()){
	        while(getline(input ,s)){                             ///takes line by line in string
	             for(int i=0 ;i<(int)s.length();i++){             ///loop the string char by char
	                if(s[i]=='@'){                                /// if it found '@' then apply RLE
	                 int x = s[i+1]-'0';                          ///take the number followed in position i+1 as an integer
	                  for(int j=i ; j <(i+x);j++){                ///loop from your current position for a x iterations to repeat the target char in position i+2
	                   if (!output.is_open())                      ///if the output file closed then open it
	                             output.open("extended.txt", ios::out);
	                             output<<s[i+2];                   ///print the char in the output file
	                    }
	                    i+=2;                                  /// to skip the num and char we repeated
	                    }

                      else{
	                       if (!output.is_open())
	                         output.open("extinted.txt", ios::out);
	                         output<<s[i];
	                       }

	              }
	             output<<endl;
	          }
	   }
	   input.close();
	   output.close();

}
