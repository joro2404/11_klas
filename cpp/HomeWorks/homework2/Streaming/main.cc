#include "media.hh"
#include "platform.hh"
#include "user.hh"
#include "song.hh"
#include "film.hh"
#include "book.hh"
#include "game.hh"
#include "payment.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    song song1("Toss a coin to your witcher!", "Unknown", 5, 10);
    song song2("Piyan", "Preslava", 1, 100);

    film film1("The Witcher", "Netflix", 50.5, 480);
    film film2("Game of thrones", "HBO", 20.3, 64);

    book book1("Song of fire and ice", "Debeliq", 10.3);
    book book2("1984", "adasha", 100.6);

    game game1("League of Legends", "Riot", 1, 8000); //naistina imam 8k chasa ;(
    game game2("The Witcher", "Unknown", 5, 400);

    std::vector< media* > used_medias1;
    used_medias1.push_back(&song2);
    used_medias1.push_back(&film1);
    used_medias1.push_back(&book2);
    used_medias1.push_back(&game1);


    std::vector< media* > used_medias2;
    used_medias2.push_back(&song1);
    used_medias2.push_back(&film2);
    used_medias2.push_back(&book1);
    used_medias2.push_back(&game2);

    payment payment1("01.01.2020 - 01.02.2020", used_medias1, true);
    payment payment2("01.02.2020 - 01.03.2020", used_medias1, false);

    payment payment3("01.01.2020 - 01.02.2020", used_medias2, false);
    payment payment4("01.02.2020 - 01.03.2020", used_medias2, true);

    std::vector < payment > payments1;
    payments1.push_back(payment1);
    payments1.push_back(payment2);

    std::vector < payment > payments2;
    payments2.push_back(payment3);
    payments2.push_back(payment4);

    user user1("Mario", "mario.benov69@gmail.com", used_medias1, payments1);
    user user2("Georgi", "g.asparuhov420@gmail.com", used_medias2, payments2);

    std::vector < user > users;
    users.push_back(user1);
    users.push_back(user2);

    std::vector< media* > available_medias;
    for (int i = 0; i < 4; i++){
        available_medias.push_back(used_medias1[i]);
        available_medias.push_back(used_medias2[i]);
    }

    platform Finaly(users, available_medias);


    std::vector < user > test1;
    test1 = Finaly.get_all_users();
    for (int i = 0; i < test1.size(); i++){
        cout << test1[i].name << endl;
    }
    

    std::vector < payment > test2;
    test2 = Finaly.get_payments(user1);
    for (int i = 0; i < test2.size(); i++){
        cout << test2[i].date << endl;
    }


    Finaly.make_payment(user1, "01.02.2020 - 01.03.2020");
    cout << user1.payments[1].status << endl;


    std::vector < media* > test4;
    test4 = Finaly.serach_by_title("The Witcher", available_medias);
    for (int i = 0; i < test4.size(); i++){
        cout << test4[i]->title << " - " << test4[i]->author << endl;
    }
    
    return 0;
}