/*	File:		StandardGetFolderMain.c	Contains:	A simple shell that allows the testing of the StandardGetFolder 				routines.	Written by: Andy Bachorski		Copyright:	Copyright � 1998-1999 by Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.	Change History (most recent first):				7/1/1999	Karl Groethe		 Updated for Metrowerks Codewarror Pro 2.1				*///******************	Universal Interfaces		****************************#include <Dialogs.h>#include <Finder.h>#include <Fonts.h>#include <Menus.h>#include <Quickdraw.h>#include <TextEdit.h>//******************	Project Interfaces			****************************#include "StandardGetFolder.h"void main(void){	FileFilterYDUPP 	customFilterUPP;	StandardFileReply	mySFReply;		// init the toolbox		MaxApplZone();	InitGraf(&qd.thePort);	InitFonts();	InitWindows(); 	InitMenus();	TEInit();	InitDialogs(nil);	//	Call the get folder routine, passing in our file filter		customFilterUPP = NewFileFilterYDProc( OnlyVisibleFoldersCustomFileFilter );	StandardGetFolder( customFilterUPP, &mySFReply );		DisposeRoutineDescriptor( customFilterUPP );		// MacsBug is indeed the best UI for reporting results	/*		if (mySFReply.sfGood)		{			DebugStr(mySFReply.sfFile.name);						if (mySFReply.sfIsVolume) DebugStr("\p is a volume");		}		else		{			DebugStr("\p cancelled");		}	*/}