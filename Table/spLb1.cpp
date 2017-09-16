// spLb1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tables.h"
#include "vistab.h"
#include <stdlib.h>

int nTbStud = 2, lnTbStud = 100;
struct recrd tbStud[100] = // static table defintion
{{{"Diatlov",88}, FunctionalField::value_1, 0},	// 1st record ititialization
{ {"Kutsar",89}, FunctionalField::value_2, 0}};// 2nd record ititializaton
struct recrd tstArg = {{"Diatlov",89}, FunctionalField::value_1, 0},	// appending element intialization
	insArg = {{"Gazizov",89}, FunctionalField::value_3, 0},	// appending element intialization
	insArg0 = {{"Gazizov",55}, FunctionalField::value_1, 0},	// appending element intialization
	insArg1 = {{"Bilyk",8}, FunctionalField::value_2, 0},		// appending element intialization
	insArg2 = {{"Dudko",80}, FunctionalField::value_1, 0};	// appending element intialization

#include <iostream>
#include <iomanip>
int main(int argc, char* argv[]) {
	struct recrd*pTb;
	pTb = (struct recrd*)malloc(100 * sizeof(struct recrd));
	pTb = new struct recrd[100];
	prRow(&tstArg);
	prRow(selNmb(tbStud, 1));
	prRow(selLin(tstArg.key, tbStud, 2));
	prRow(insNmb(&insArg, tbStud, 3, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(updNmb(&insArg1, tbStud, 2, &nTbStud));
	prRow(delNmb(tbStud, 1));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(insLin(&insArg2, tbStud, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(delLin(&insArg1, tbStud, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(updLin(insArg.key, &insArg0, tbStud, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(pckLin(tbStud, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(srtBin(tbStud, nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(selBin(insArg2.key, tbStud, nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prRow(insBin(&insArg1, tbStud, &nTbStud));
	prTab(tbStud, 0, nTbStud - 1);
	prClr(blue);

	auto t = coincSymbs(selBin(insArg1.key, tbStud, nTbStud), selBin(insArg2.key, tbStud, nTbStud));
	return 0;
}