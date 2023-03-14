#include "Shop.h"

Shop::Shop() {
	m_shopName = "Test";
	m_shopRank = 'F';
	m_numIngredients = 0;

}

Shop::Shop(string name) {
	m_shopName = name;
	m_shopRank = 'F';
	m_numIngredients = 0;

}

string Shop::GetName() {

		return m_shopName;
}

void Shop::SetName(string name) {
	m_shopName = name;
}

int Shop::CheckIngredient(Ingredient ingredientName) {
	if (m_numIngredients == 0){
		return -1;
	}
	
	for (int i = 0; i < PROJ2_SIZE; i++) {
		if (ingredientName.m_name == m_myIngredients[i].m_name) {
			return i;
		}

	}
	return -1;
}
void Shop::AddIngredient(Ingredient gameIngredients) {
	int exists = 0;

	//checks if the ingredient already exists
	for (int i = 0; i < m_numIngredients; i++) {
		if (gameIngredients.m_name == m_myIngredients[i].m_name) {
			exists++;
		}

	}
	if (exists == 0) {
		m_myIngredients[m_numIngredients] = gameIngredients;
		m_myIngredients[m_numIngredients].m_quantity = 0;
		IncrementQuantity(m_myIngredients[m_numIngredients]);
		m_numIngredients++;
	}
	else {
		for (int i = 0; i < m_numIngredients + 1; i++) {
			if (gameIngredients.m_name == m_myIngredients[i].m_name) {
				m_myIngredients[i].m_quantity += 1;

			}
		}
	}
}

void Shop::IncrementQuantity(Ingredient gameIngredients) {
	for (int i = 0; i < m_numIngredients + 1; i++) {
		if (gameIngredients.m_name == m_myIngredients[i].m_name) {
				m_myIngredients[i].m_quantity++;
		}
	};
}

bool Shop::DecrementQuantity(Ingredient gameIngredients) {
	for (int i = 0; i < m_numIngredients + 1; i++) {
		if (gameIngredients.m_name == m_myIngredients[i].m_name) {
			if (m_myIngredients[i].m_quantity > 0) {
				m_myIngredients[i].m_quantity -= 1;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
bool Shop::CheckQuantity(Ingredient first, Ingredient second) {
	bool firstExits = false;
	bool secondExists = false;
	
	for (int i = 0; i < PROJ2_SIZE; i++) {
		if ((first.m_name == m_myIngredients[i].m_name) and (m_myIngredients[i].m_quantity > 0)) {
			firstExits = true;
		}
		if ((second.m_name == m_myIngredients[i].m_name) and (m_myIngredients[i].m_quantity > 0)) {
			secondExists = true;
		}

	}
	if ((firstExits and secondExists)) {
		return true;
	}
	return false;
}

Ingredient Shop::GetIngredient(int index) {
	if (sizeof(m_myIngredients) == 0) {
		cout << "there are currently no ingredients" << endl;
	}
	else {
		return m_myIngredients[index];
	}
	return Ingredient();
}

void Shop::CalcRank() {
	double percentage = (double(IngredientCount()) / double(PROJ2_SIZE)) * 100;
	
	if (percentage < 30) {
		m_shopRank = 'F';
	}
	else if (percentage < 50) {
		m_shopRank = 'D';
	}
	else if (percentage < 70) {
		m_shopRank = 'C';
	}
	else if (percentage < 90) {
		m_shopRank = 'B';
	}
	else if (percentage < 100) {
		m_shopRank = 'A';
	}
	else {
		m_shopRank = 'S';
	}

}

char Shop::GetRank() {
	return m_shopRank;
}

int Shop::IngredientCount() {
	int numIngredients = 0;
	for (int i = 0; i < PROJ2_SIZE; i++) {
		if (m_myIngredients[i].m_quantity > 0) {
			numIngredients += 1;
		}
	}

	return numIngredients;
}

void Shop::ShopScore() {
	double percentage = (double(IngredientCount()) / double(PROJ2_SIZE)) * 100;

	cout << "***The Potion Shop***" << endl;
	cout << "Owened by: " << m_shopName << endl;
	cout << "There are " << PROJ2_SIZE << " available products." << endl;
	cout << "This shop has " << m_numIngredients << " products in stock" << endl;
	cout << "Which is " << int(percentage) << "%" << endl;
	cout << "Shop rank: " << m_shopRank << endl;
	cout << "*********************" << endl;

}