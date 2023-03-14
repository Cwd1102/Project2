#include "Game.h"

Game::Game() {}


void Game::LoadIngredients() {
    ifstream inputStream;

    inputStream.open(PROJ2_DATA);
    string line;
    string temp;
    
        
        for (int j = 0; j < PROJ2_SIZE; j++) { //loops for amount of ingredients(32) in the game
            m_ingredients[j].m_quantity = 0; //sets quantity to 0
            for (int i = 0; i < 4; i++) { //loops for number of details(4) in each ingredient
                if (i == 3) {
                    getline(inputStream, temp, '\n');
                }
                else {
                    getline(inputStream, temp, ',');
                }

                switch ((i + 1))
                {
                case 1:
                    m_ingredients[j].m_name = temp;
                    break;

                case 2:
                    m_ingredients[j].m_type = temp;
                    break;

                case 3:
                    m_ingredients[j].m_ingredient1 = temp;
                    break;

                case 4:
                    m_ingredients[j].m_ingredient2 = temp;
                }
            }
        }
    }

void Game::StartGame() {
    GameTitle();
    LoadIngredients();

    int playerSelection = -1; 
    bool condition = true;
    string shopName;
    
    cout << "What is the name of your Shop?" << endl;
    getline(cin, shopName);
    m_myShop.SetName(shopName); //sets shop name

    do {
        playerSelection = MainMenu();
        switch (playerSelection) {
        
        case 1:
            DisplayIngredients();
            break;
        case 2:
            SearchIngredients();
            break;
        case 3:

            break;
        case 4:
            
            break;
        
        case 5:
            cout << "Thanks for playing UMBC Potion Craft" << endl;
            condition = false;
        
        }
    } while (condition);
}

void Game::DisplayIngredients() {
    int numIngredients = m_myShop.IngredientCount();
    bool notFound;
    //loops for the lotal number of ingredients in the shop
    for (int i = 0; i < PROJ2_SIZE; i++) {
        notFound = true; // false when the ingredient in question is found
        
        cout << i + 1 << "." << " " << m_ingredients[i].m_name << " "; // format (1. Firebell )
        // loops for number of ingredients known to the shop
        for (int j = 0; j < numIngredients + 1; j++) { 
            Ingredient tempIngredient = m_myShop.GetIngredient(j);

           if (tempIngredient.m_name == m_ingredients[i].m_name) {
               cout << tempIngredient.m_quantity << endl;
               notFound = false;
           }
           else if ((j == numIngredients) and (notFound)){
               cout << '0' << endl;
           }
        }
    }
}

int Game::MainMenu() {
    int userInput;

    if (m_myShop.GetRank() == 'S') {
        cout << "S rank has been reached!" << endl;
        return 5;
    }

    cout << "What would you like to do in " << m_myShop.GetName() << "'s shop?" << endl;
    cout << "1. Display your Shop's Ingredients" << endl;
    cout << "2. Search for Natural Ingredients" << endl;
    cout << "3. Attempt to Merge Ingredients" << endl;
    cout << "4. See Score" << endl;
    cout << "5. Quit" << endl;
    cin >> userInput;

    return userInput;
}

void Game::SearchIngredients() {
    int numNaturals = 0;
    int randomNatural = 0;

    for (int i = 0; i < PROJ2_SIZE; i++) {
       Ingredient temp = m_ingredients[i];
       if (temp.m_type == "natural") {
           numNaturals++;
       }
    }

    randomNatural = rand() % (0 + numNaturals);
    cout << m_ingredients[randomNatural].m_name << " found!" << endl;
    m_myShop.AddIngredient(m_ingredients[randomNatural]);

}

void Game::CombineIngredients() {


}

void Game::RequestIngredient(int& choice) {

}

int Game::SearchRecipes(string ingredient1, string ingredient2) {
    //loops for the total number of ingredients times
    for (int i = 0; i < PROJ2_SIZE; i++) {
        if ((m_ingredients[i].m_ingredient1 == ingredient1) and (m_ingredients[i].m_ingredient2 == ingredient2)) {
            return i;
        }
    }

    cout << "No ingredient was found" << endl; // makes sure user knows that not ingredient was found
    return 0;
}

void GameTitle() {
    cout << "PPPP  OO  TTTTT III  OO  N   N CCCC RRR   AA  FFFF TTTTT" << endl;
    cout << "P  P O  O   T    I  O  O NN  N C    R  R A  A F      T  " << endl;
    cout << "PPPP O  O   T    I  O  O N N N C    RRR  AAAA FFFF   T  " << endl;
    cout << "P    O  O   T    I  O  O N  NN C    R R  A  A F      T  " << endl;
    cout << "P     OO    T   III  OO  N   N CCCC R  R A  A F      T  " << endl;
}