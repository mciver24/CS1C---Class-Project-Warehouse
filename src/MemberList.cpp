

/**************************************************************************
 * AUTHOR        : Jacob Mc'Iver
 * STUDENT ID    : 265933
 * Assignment #  : Group Project
 * CLASS         : MW 12:30pm - 4:20pm
 * SECTION       : CS1C
 * DUE DATE      : 3//2015
 **************************************************************************/

#include "memberList.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

MemberList::MemberList()
{
	head = NULL;
}

MemberList::~MemberList()
{
	Basic* memberPtr;

	memberPtr	= head;

	while(memberPtr != NULL)
	{
		memberPtr	= memberPtr->GetNext();
		delete head;
		head		= memberPtr;
	}
}

void MemberList::CreateList(ifstream &inFile)
{
	// VARIABLE DECLARATIONS
	Basic*	memberPtr;
	string 	name;
	int		id;
	string  memberType;
	Date	expiration;

	// Loop
	while(!inFile.eof())
	{
		getline(inFile, name);
		inFile >> id;
		inFile.ignore(1000, '\n');
		getline(inFile, memberType);
		expiration.SetDate(inFile);

		if(memberType == "Basic")
		{
			memberPtr = new Basic;
		}
		else
		{
			memberPtr = new Preferred;
		}

		memberPtr->SetName(name);
		memberPtr->SetId(id);
		memberPtr->SetExpiration(expiration);

		memberPtr->SetNext(head);
		head = memberPtr;
	}
}

//Need Contingency for Three Cases
//Removing from Head (The first item in list)
//Removing from Middle
//Removing from Last

//void MemberList::DeleteMember(Basic* deleteMember)
//{
//
//	 MemberList* memberPtr;
//	 memberPtr = head;
//
//	 if (head !=NULL )
//	 {
//		 memberPtr = memberPtr -> next;
//		 head = memberPtr;
//	 }
//
//	delete memberPtr;
//
//}

Basic *MemberList::SearchMember(int userId)
{
	Basic *memberPtr;
	bool found;
	int y;

	found = false;
	memberPtr = head;
	y = memberPtr->GetId();
	cout  << y;


//	for(int i=0; i < 11; i++)
//	{
//		if (memberPtr->GetId() == userId)
//		{
//			cout << "test " << memberPtr->GetId() << endl;
//			found = true;
//		}
//		else
//		{
//			memberPtr = memberPtr->GetNext();
//		}
//	}

	return memberPtr;
}

Basic *MemberList::GetHead() const
{
	return head;
}

