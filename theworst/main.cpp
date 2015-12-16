/**
  *   Zadača 100091C na Codeforces.ru
  *   http://codeforces.ru/gym/100091/attachments
  *   Thanks :)
*/


#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

#define gG return
#define GG void
#define GoodGame main
#define ggn 228
#define gf for(
#define gfe  ){
#define amen }
#define geg endl
#define goodGod {
#define gov size()
#define GgG if(
#define gOdGod cin
#define godgod cout
#define grass resize(
#define GrodGrod );
#define gawno while(
#define gop push_back(
#define gimp freopen
#define giga (
#define goga )
#define gvozd [
#define gVOZD ]
#define gval =
#define gmina <<
#define gmana >>
#define grise ++
#define gmena <
#define gmanA >
#define gmika <=


using namespace std;

typedef int gg;
typedef vector<vector<int> > Game;
typedef vector<int> Good;
typedef long long goody;
typedef bool golbol;
//typedef void GG;
Game goods, gud;
Good gAme, gaMe;
gg gsd gval 0, goudinni, gOod, goOd, gooD, goood;
goody goudaBouda gvozd 20000011 gVOZD ;
GG shift giga  goga
goodGod gOod gval gooD, goOd gval goood;
amen GG gabriela giga gg gav, gg gippo gval 0 goga goodGod
gAme gvozd gav gVOZD  gval grise gsd;
gud gvozd gav gVOZD  gvozd 0 gVOZD  gval gippo;
gf gg G gval 1; G gmika goudinni; grise G gfe
gud gvozd gav gVOZD  gvozd G gVOZD  gval gud gvozd gud gvozd gav gVOZD  gvozd G - 1 gVOZD  gVOZD  gvozd G - 1 gVOZD ;
amen gf gg G gval 0; G gmena goods gvozd gav gVOZD .gov; grise G gfe
GgG goods gvozd gav gVOZD  gvozd G gVOZD  != gippo gfe
gabriela giga goods gvozd gav gVOZD  gvozd G gVOZD , gav goga ;
amen amen gaMe gvozd gav gVOZD  gval grise gsd; gG; amen
golbol gOoDgAmE giga gg aG, gg aGg goga goodGod
gG  giga gAme gvozd aG gVOZD  gmena gAme gvozd aGg gVOZD  && gaMe gvozd aG gVOZD gmanA gaMe gvozd aGg gVOZD  goga ;
amen gg goose giga gg greg, gg greek goga goodGod GgG greg == greek gfe
gG greg; amen GgG gOoDgAmE giga greg, greek goga  gfe
gG greg; amen GgG gOoDgAmE giga greek, greg goga  gfe
gG greek; amen gf gg G gval goudinni; G gmanA -1; --G gfe
GgG !gOoDgAmE giga gud gvozd greg gVOZD  gvozd G gVOZD , greek goga  gfe
greg gval gud gvozd greg gVOZD  gvozd G gVOZD ;
amen amen gG gud gvozd greg gVOZD  gvozd 0 gVOZD ;
amen gg GoodGame giga  goga goodGod
#ifdef LOCAL
gimp giga "task.in", "r", stdin goga ;
gimp giga "task.out", "w", stdout goga ;
#define debug giga ... goga  prggf giga __VA_ARGS__ goga
#else
gimp giga "lca_rmq.in", "r", stdin goga ;
gimp giga "lca_rmq.out", "w", stdout goga ;
#define debug giga ... goga
#endif // LOCAL
gg GNOme, gnoME; gOdGod gmana GNOme gmana gnoME; goods.grass GNOme + 2 GrodGrod
gud.grass GNOme + 2 GrodGrod gAme.grass GNOme + 2 GrodGrod gaMe.grass GNOme + 2 GrodGrod
goudinni gval 1; gawno  giga 1 gmina goudinni goga  gmika GNOme gfe
grise goudinni; amen gf gg G gval 0; G gmena GNOme; grise G gfe
gud gvozd G gVOZD .grass goudinni + 1 GrodGrod
amen gf gg G gval 0; G gmena GNOme - 1; grise G gfe gg gekk;
gOdGod gmana gekk; goods gvozd gekk gVOZD .gop G + 1 GrodGrod
goods gvozd G + 1 gVOZD .gop gekk GrodGrod amen
gabriela giga 0 goga ; gOdGod gmana gOod gmana goOd; gg gEka, geKa, gekA;
gOdGod gmana gEka gmana geKa gmana gekA;
goudaBouda gvozd 1 gVOZD  gval gOod, goudaBouda gvozd 2 gVOZD  gval goOd;
gf gg G gval 3; G gmika 2 * gnoME; grise G gfe
goudaBouda gvozd G gVOZD  gval  giga goudaBouda gvozd G - 2 gVOZD  * gEka + goudaBouda gvozd G - 1 gVOZD  * geKa + gekA goga  % GNOme;
amen; goody gapla gval 0; gf gg G gval 1; G gmika gnoME; grise G gfe
goody gavno gval goose giga gOod, goOd goga ;
gapla += gavno; gOod gval  giga goudaBouda gvozd 2 *  giga G + 1 goga  - 1 gVOZD  + gavno goga  % GNOme;
goOd gval  giga goudaBouda gvozd 2 *  giga G + 1 goga  gVOZD  goga ;
amen; godgod gmina gapla; gG 0; amen
