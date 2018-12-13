/*
 * Document.hpp
 *
 *  Created on: Nov 7, 2016
 *      Author: Debra
 */

#ifndef DOCUMENT_HPP_
#define DOCUMENT_HPP_
#include "Node.hpp"
#include "LLSE.hpp"
#include <string>

class Document {
	string filename;
	LLSE *wordlist;
	string fw[48]={	"a",
					"along",
					"although",
					"am",
					"among",
					"and"
					"are",
					"as",
					"at",
					"be",
					"because",
					"between",
					"can",
					"do",
					"dont",
					"either",
					"for",
					"got",
					"has",
					"have",
					"havent",
					"he",
					"i",
					"in",
					"is",
					"isnt",
					"it",
					"more",
					"much",
					"neither",
					"no",
					"none",
					"nor",
					"not",
					"of",
					"one",
					"or",
					"that",
					"the",
					"they",
					"this",
					"though",
					"was",
					"when",
					"while",
					"why",
					"with",
					"without",
					"you"
	};
	int fwlen = 48;
public:
	Document(string f);
	string strip(string w);
	bool checkFunctionWords(string w);
	void readFile();
	void pickSort(int i);  // 0 = insertionSort, 1 = QuickSort, 2= heapSort
};



#endif /* DOCUMENT_HPP_ */
