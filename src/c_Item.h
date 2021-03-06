/*********************************************************
 * AUTHOR 			: Daniel Phan
 * STUDENT ID 		: 243390
 * Class Project	: Ralph's Club Membership RipOff
 * CLASS 			: CS1C
 * SECTION 			: TTh 12:30PM - 4:20PM
 * DUE DATE 		: 3/17/15
 *********************************************************/
#ifndef C_ITEM_H_
#define C_ITEM_H_

#include <string>
#include "Date.h"

using namespace std;


class Item
{
public:
	Item();
	~Item();

	/************
	 * Mutators *
	 ************/
	void SetItemName(string theName);
	void SetItemPrice(float thePrice);
	void SetItemQuantity(int theQuantity);
	void SetPurchaseID(int theBuyerID);
	void SetDatePurchased(Date aDate);
	void SetNextItem(Item *itemHead);

	/*************
	 * Accessors *
	 *************/
	string GetName() const;
	float GetPrice() const;
	int GetQuantity() const;
	int GetBuyerID() const;
	Date GetDatePurchased() const;
	Item *GetNextItem() const;

private:

	string itemName;
	float itemPrice;
	int itemQuantity;
	int buyerID;
	Date purchaseDate;
	Item *nextItemPtr;

};
#endif /* C_ITEM_H_ */
