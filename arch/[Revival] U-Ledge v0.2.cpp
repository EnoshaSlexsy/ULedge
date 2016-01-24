//-----------------------------------------------------------------------------------------------------------------------------------------
//Libraries list v2.0 - 11.07 (0.08-)
//-----------------------------------------------------------------------------------------------------------------------------------------
#include <cstdio>
#include <ctime>
#include <fstream>
#include <io.h>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <windows.h>
//-----------------------------------------------------------------------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------
//Const list v2.3 - 22.07 (0.12)
//-----------------------------------------------------------------------------------------------------------------------------------------
int const ABILITY_COUNT =			15;
int const ABILITY_LEVEL_MAX =		10;
int const LETTER_SIZE_X =			4;
int const LOG_SIZE_Y =				22;
int const LOG_SIZE_X =				30;
int const LOG_POSITION_X =			40;
int const LOG_POSITION_Y =			1;
int const MENU_POSITION_X =			20;
int const MENU_POSITION_Y =			3;
int const MENU_SIZE_X =				40;
int const MENU_SIZE_Y =				8;
int const MENU_MODE_COUNT =			4;
int const SELECTER_POSITION_X = 	40;
int const SELECTER_POSITION_Y = 	0;
int const PARAMETER_COUNT_MAX = 	3;
int const PLAYER_HEADER_LENGTH =	5;
int const TRASH_POSITION_X =		60;
int const TRASH_POSITION_Y =		20;
//-----------------------------------------------------------------------------------------------------------------------------------------
//Drigger Id defining v1.0 - 22.07 (0.12)
//-----------------------------------------------------------------------------------------------------------------------------------------
int const TRIGGER_ID_CRIT =			1;
//-----------------------------------------------------------------------------------------------------------------------------------------
//Buff Id defining v1.0 - 22.07 (0.12)
//-----------------------------------------------------------------------------------------------------------------------------------------
int const BUFF_ID_DAMAGE =			1;
//-----------------------------------------------------------------------------------------------------------------------------------------
//Global variable initialization v2.0 - 11.07 (0.08-)
//-----------------------------------------------------------------------------------------------------------------------------------------
string 				emptyString;
char 				emptyChar;
int 				emptyInt;
vector<string> 		log;
//-----------------------------------------------------------------------------------------------------------------------------------------
//Struct Initialization v3.0 - 23.07 (0.12)
//-----------------------------------------------------------------------------------------------------------------------------------------
typedef struct{
	string 			actionType;
	string 			description;
	string 			name;
	string 			triggerType[ PARAMETER_COUNT_MAX + 1 ];
	int 			levelMax;
	int 			parameterCount;
	int 			power[ ABILITY_LEVEL_MAX + 1 ][ PARAMETER_COUNT_MAX + 1 ];
	int 			countdownMax;
} STR_ability;
/*typedef struct{
	int 			hitpoint = 0;
	int				actionpoint = 0;
	int 			attackPower = 0;
	int 			block = 0;
	int 			criticalChance = 0;
	int 			criticalPower = 0;
} STR_buff;*/
/*typedef struct{
	
} ;*/				//struct ability, hero and etc.
typedef struct{
	int				learn;
	int				id[ ABILITY_COUNT ];
	int				levelUp[ ABILITY_COUNT ];
	int 			level[ ABILITY_COUNT ];
	int				countdown[ ABILITY_COUNT ];
} STR_player_ability;
typedef struct{
	string 			name;
	int 			level;
	int 			hitpointMax, hitpointCurrent;
	int				actionpoint = 0, actionpointIncrease = 800;
	int 			attackPower;
	int 			block;
	int 			criticalChance;
	int 			criticalPower;	
} STR_player_hero;
typedef struct{
	STR_player_hero hero;
	STR_player_ability ability;
} STR_player;
typedef struct{
	int name;
	int attackPower;
	int actionpoint = 0, actionpointIncrease = 300;
	int block;
	int hitpointMax, hitpointCurrent;
} STR_summon;
//-----------------------------------------------------------------------------------------------------------------------------------------
//System function v2.1 - 11.07 (0.08-)
//openImage ( indev ) - readig img
//-----------------------------------------------------------------------------------------------------------------------------------------
void randomInitialization(){
	srand( time( NULL ) );
}
int chanceCount( int buffLuck ){
	return 1 + rand() % 100 * buffLuck / 100;
}
int chanceCount(){
	return 1 + rand() % 100;
}
void bugFinder(){
	/*system("pause");*/
	cout << "!BF"; cin >> emptyChar;
}
void bugFinder(string S){
	cout << S; cin >> emptyChar;
}
bool FileExists(const char *fname){
  return access(fname, 0) != -1;
}
void openImage(string name){
	bugFinder("In openImage");
	name = "//image" + name + ".jpg";
	ShellExecute(0,"open", name.c_str(),"",0,SW_SHOW);
	bugFinder("See?");
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Classes initialization 	v2.4	13.07 (0.11)
//Console - 				v1.5	13.07 (0.11)
//Ability - 				v2.4	11.07 (0.08-)
//	timepassed ( indev ) - autodec of countdown
//Player - 					v2.5	13.07 (0.11)
//Output - 					v2.4	15.07 (0.12)
//-----------------------------------------------------------------------------------------------------------------------------------------
class Console{
	private:
		size_t c_i, c_j;
	public: 
		void PositionSet( int PositionX, int PositionY ){
			COORD Screen;
			HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
			Screen.X = PositionX; Screen.Y = PositionY;
			SetConsoleCursorPosition( hOuput , Screen );
		}
		void CleanString( int PositionY ){
			PositionSet( 0, PositionY );
			for( c_i = 1; c_i <= 80; c_i++ ){
				cout << " ";
			}
		}
		void CleanLogString(int PositionY){
			PositionSet( LOG_POSITION_X, PositionY);
			for( c_i = 1; c_i <= LOG_SIZE_X; c_i++ ){
				cout << " ";
			}
		}
		void StringRewrite( int PositionY, int PositionX, string output ){				//Rewrite to for( c_i = LOG_POSITIONX + output.size)
			CleanLogString( PositionY );
			PositionSet( PositionX, PositionY );
			cout << output;
		}
		int Cursor(int PositionX, int PositionY, int selectCount){
			char actionChar = ' ';
			int position = 0;
			PositionX--;																//Hm...
			while(!GetAsyncKeyState(VK_RIGHT)){
				PositionSet(PositionX, PositionY + position);
				cout << " ";
				if(GetAsyncKeyState(VK_UP)){
					position = max(position - 1, 0);
				}
				else if(GetAsyncKeyState(VK_DOWN)){
					position = min(position + 1, selectCount - 1);
				}
				PositionSet(PositionX, PositionY + position);
				cout << ">";
				Sleep(100);
			}
			return position + 1;
		}
		int Cursor(int PositionX, int PositionY, int selectCount, char CHAR){	//Rename!
			char actionChar = ' ';
			int position = 0;
			PositionX--;																//Hm...
			while(!GetAsyncKeyState(VK_RIGHT)){
				PositionSet(PositionX, PositionY + position);
				cout << CHAR;
				if(GetAsyncKeyState(VK_UP)){
					position = max(position - 1, 0);
				}
				else if(GetAsyncKeyState(VK_DOWN)){
					position = min(position + 1, selectCount - 1);
				}
				PositionSet(PositionX, PositionY + position);
				cout << ">";
				Sleep(100);
			}
			return position + 1;
		}
} console;
//--------------------------------------------------------------------------------------------------
class Ability{
private:
	int c_parameter, c_level;
	string fileName;
	string idString;
	string folder = "abilities//";
public:
	STR_ability stats;
	void readStats(int id){
		ostringstream idString;
		idString << id;
		fileName  = folder + idString.str() + ".ua";
		ifstream fin(fileName.c_str());
		fin >> emptyString >> stats.name;
		fin >> emptyString >> stats.description;
		fin >> emptyString >> stats.actionType;
		fin >> emptyString >> stats.countdownMax;
		fin >> emptyString >> stats.parameterCount;
		fin >> emptyString >> stats.levelMax;
		for( c_parameter = 1; c_parameter <= stats.parameterCount; c_parameter++ ){
			fin >> stats.triggerType[ c_parameter ];
			stats.power[ 0 ][ c_parameter ] = 0;
			for( c_level = 1; c_level <= stats.levelMax; c_level++ ){
				fin >> stats.power[ c_level ][ c_parameter ];
			}
			ifstream close();
		}
	}
} abilityMassive[ ABILITY_COUNT ];
//--------------------------------------------------------------------------------------------------
class Player{
private:
	string fileName, fileNameDefault;
	string folder = "players//";
	int c_i, abilityCount, abilityId;
public:
	STR_player stats;
	void abilityClean(){
		for( c_i = 1; c_i <= ABILITY_COUNT; c_i++ ){
			stats.ability.level[ c_i ] = 0;
			stats.ability.countdown[ c_i ] = 0;
		}
	}
	void abilityClean(int abilityCount){
		for( c_i = 1; c_i <= abilityCount; c_i++ ){
			stats.ability.level[ c_i ] = 0;
			stats.ability.countdown[ c_i ] = 0;
		}
	}
	/*void abilityGetInfo(Ability Massive[], int abilityCount){
		for( c_i = 1; c_i <= min( abilityCount, ABILITY_COUNT - 1); c_i++ ){
			stats.ability[ c_i ] = Massive[ c_i ].stats;
		}
	}*/
	void readStats(){
		cout << "Input player name - ";
		cin >> stats.hero.name;
		fileName = folder + stats.hero.name + ".up";
		fileNameDefault = folder + "EXAMPLE.up";
		if( FileExists( fileName.c_str() )) 
		{
			CopyFile( fileNameDefault.c_str(), fileName.c_str(), true );
			/*playerCreate*/
		}
		ifstream fin( fileName.c_str() );
		fin >> emptyString >> stats.hero.level;
		fin >> emptyString >> stats.hero.hitpointMax;
		fin >> emptyString >> stats.hero.attackPower;
		fin >> emptyString >> stats.hero.block;
		fin >> emptyString >> stats.hero.criticalChance;
		fin >> emptyString >> stats.hero.criticalPower;
		fin >> emptyString >> stats.ability.learn;
		for(c_i = 1; c_i <= stats.ability.learn; c_i++){
			fin >> stats.ability.id[ c_i ] >> stats.ability.levelUp[ c_i ];
		}
		stats.hero.hitpointCurrent = stats.hero.hitpointMax;
		ifstream close();
	}
	/*void initialization(){
		abilityClean();
		readStats();
		abilityGetInfo(abilityMassive, abilityCount);
	}*/
} emptyPlayer;
//--------------------------------------------------------------------------------------------------
class Output{
private:
	int c_logPosition, c_string, c_ability, c_parameter, c_level;	
public:
	void PutPixel( int PositionX, int PositionY ){		//One color only!
		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute( hConsoleHandle, 15 | BACKGROUND_BLUE );
    	console.PositionSet( PositionX, PositionY );
    	cout << " ";
    	SetConsoleTextAttribute( hConsoleHandle, 15 | BACKGROUND_INTENSITY );
	}
	void PutLineX( int PositionX, int PositionY, int Size){
		int c_i;
		for( c_i = 0; c_i < Size; c_i++ ){
			PutPixel( PositionX + c_i, PositionY );
		}
	}
	void PutLineY( int PositionX, int PositionY, int Size){
		int c_i;
		for( c_i = 0; c_i < Size; c_i++ ){
			PutPixel( PositionX, PositionY + c_i );
		}
	}
	void StringInConsole( int PositionX, int PositionY, string String ){
		size_t c_i;
		int letterSizeX = -1;
		for( c_i = 0; c_i <= int(String.size()); c_i++ ){
			PositionX += letterSizeX + 1;
			Sleep(1000);
			switch( String[ c_i ] ){
				case 'A':
					PutLineX( PositionX, PositionY, 3 );
					PutLineX( PositionX, PositionY + 2, 3 );
					PutLineY( PositionX, PositionY, 5 );
					PutLineY( PositionX + 2, PositionY, 5 );
					letterSizeX = 3;
					break;
				case 'D':
					PutLineX( PositionX, PositionY, 3 );
					PutLineY( PositionX, PositionY, 5 );
					PutLineX( PositionX, PositionY + 4, 3 );
					PutPixel( PositionX + 3, PositionY + 1 );
					PutPixel( PositionX + 4, PositionY + 2 );
					PutPixel( PositionX + 3, PositionY + 3 );
					letterSizeX = 5;
					break;
				case 'G':
					PutLineX( PositionX, PositionY, 4 );
					PutLineY( PositionX, PositionY, 5 );
					PutLineX( PositionX, PositionY + 4, 4 );
					PutLineY( PositionX + 4, PositionY + 2, 3 );
					PutLineX( PositionX + 2, PositionY + 2, 3);
					letterSizeX = 5;
					break;
				case 'E':
					PutLineY( PositionX, PositionY, 5 );
					PutLineX( PositionX, PositionY, 3 );
					PutLineX( PositionX, PositionY + 2, 3 );
					PutLineX( PositionX, PositionY + 4, 3 );
					letterSizeX = 3;
					
				case 'L':
					PutLineY( PositionX, PositionY, 5 );
					PutLineX( PositionX, PositionY + 4, 3 );
					letterSizeX = 3;
					break;
				case 'U':
					PutLineY( PositionX, PositionY, 5 );
					PutLineY( PositionX + 2, PositionY, 5 );
					PutLineX( PositionX, PositionY + 4, 3 );
					letterSizeX = 3;
					break;
				case '-':
					PutLineX( PositionX, PositionY + 2, 2);
					letterSizeX = 2;
					break;
			}
		}
	}
	void logRewrite(){
		if( log.size() > 0 ){
			for(c_logPosition = max( 0, (int)(log.size() - LOG_SIZE_Y / 2) ), c_string = 0;
				c_logPosition <= (int)(log.size()) - 1 && c_string <= LOG_SIZE_Y;
				c_logPosition++, c_string++ ){
				console.StringRewrite( c_string * 2 + LOG_POSITION_Y, LOG_POSITION_X, log.at(c_logPosition) );
				}	
		}
	}
	void abilityTest( Ability Massive[], int abilityCount ){
		for( c_ability = 1; c_ability <= abilityCount; c_ability++ ){
			cout << Massive[ c_ability ].stats.name
				 << " - "
				 << Massive[ c_ability ].stats.description
				 << endl;
			cout << "Max level "
				 << Massive[ c_ability ].stats.levelMax
				 << ":"
				 << endl;
			for( c_parameter = 1; c_parameter <= Massive[ c_ability ].stats.parameterCount; c_parameter++ ){
				cout << Massive[ c_ability ].stats.triggerType[ c_parameter ];
				for( c_level = 1; c_level <= Massive[ c_ability ].stats.levelMax; c_level++ ){
					cout << " " << Massive[ c_ability ].stats.power[ c_level ][ c_parameter ];
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	void abilityList( Ability Massive[], int abilityCount, Player player, int PositionX, int PositionY){
		int c_i;
		for( c_i = 1; c_i <= abilityCount; c_i++){
			console.PositionSet(PositionX, PositionY + c_i - 1);
			cout << c_i << ". ";
			if(player.stats.ability.level > 0 && Massive[ c_i ].stats.actionType == "Active"){
				cout << Massive[ c_i ].stats.name << " ( " << player.stats.ability.countdown[ c_i ] << " )";
			}
			else{
				cout << " - ";
			}
		}
	}
	void hit( Player* self, Player* target, int damage ){
		stringstream output;
		output << damage;
		log.push_back(self->stats.hero.name + " hit " + target->stats.hero.name + " on " + output.str() + " damage");
	}
	void abilityActive( Player* self, Player* target, int abilityId ){
		stringstream output;
		output << self->stats.ability.level[ abilityId ];
		log.push_back( self->stats.hero.name
						+ " use "
						+ abilityMassive[ abilityId ].stats.name
						+ "(level " + output.str() + ")" );
	}
	void triggerActive( Player* self, Player* target, int triggerId ){
		switch(triggerId){
			case TRIGGER_ID_CRIT:
			log.push_back( self->stats.hero.name + " made critical hit" );				
		}
	}
	void playerInfo(Player* player, int PositionX, int playerId){
		int PositionY = ( playerId - 1 ) * PLAYER_HEADER_LENGTH;
		console.PositionSet( PositionX + 5, PositionY );
		cout << player->stats.hero.name << "(" << player->stats.hero.level << ")";
		console.PositionSet( PositionX , PositionY + 1 );
		cout << "HitPoint:" << player->stats.hero.hitpointCurrent << "/" << player->stats.hero.hitpointMax << "   ";
		console.PositionSet( PositionX , PositionY + 2 );
		cout << "Attack Power:" << player->stats.hero.attackPower;
		console.PositionSet( PositionX , PositionY + 3 );
		cout << "Critical Attack:" << player->stats.hero.criticalChance << "%/" << player->stats.hero.criticalPower;
	}
	void Frame(int SizeX, int SizeY, int PositionX, int PositionY ){
		int c_i;
		PositionX--;
		PositionY--;
		SizeX++;
		SizeY++;
		console.PositionSet( PositionX, PositionY );
		cout << "+";
		console.PositionSet( PositionX + SizeX, PositionY );
		cout << "+";
		console.PositionSet( PositionX, PositionY + SizeY );
		cout << "+";
		console.PositionSet( PositionX + SizeX, PositionY + SizeY );
		cout << "+";
		for( c_i = 1; c_i < SizeX; c_i++ ){
			console.PositionSet( PositionX + c_i, PositionY );
			cout << "=";
			console.PositionSet( PositionX + c_i, PositionY + SizeY );
			cout << "=";
		}
		for( c_i = 1; c_i < SizeY; c_i++){
			console.PositionSet( PositionX, PositionY + c_i);
			cout << "|";
			console.PositionSet( PositionX + SizeX, PositionY + c_i);
			cout << "|";
		}
	}
	void all(Player* playerFirst, Player* playerSecond){
		playerInfo(playerFirst, 0, 1);
		playerInfo(playerSecond, 0, 2);
		logRewrite();
		Frame( LOG_SIZE_X, LOG_SIZE_Y, LOG_POSITION_X, LOG_POSITION_Y);
	}
	void targetList(Player *Players[], int playerAlive, Player *self){
		int c_i, position = 0;
		for( c_i = 1; c_i <= playerAlive; c_i++){
			if(Players[ c_i ] != self){
				position++;
				console.PositionSet(SELECTER_POSITION_X, SELECTER_POSITION_Y + position);
				cout << position << ". " << Players[ c_i ]->stats.hero.name;
			}
		}
		console.PositionSet(SELECTER_POSITION_X, SELECTER_POSITION_Y + playerAlive);
		cout << "Select target: ";
	}
	void playerList(Player *Players[], int playerCount){
		int c_i;
		for( c_i = 1; c_i <= playerCount; c_i++ ){
			playerInfo( Players[ c_i ], 0, c_i);
		}
	}
	void MainMenu( int PositionX, int PositionY ){
		console.PositionSet( PositionX + 5, PositionY );
		cout << " Choose mode: ";
		console.PositionSet( PositionX, PositionY + 1 );
		cout << "1. PvP";
		console.PositionSet( PositionX, PositionY + 2 );
		cout << "2. Deathmatch (in dev!)";
		console.PositionSet( PositionX, PositionY + 3 );
		cout << "3. Debug mod";
		console.PositionSet( PositionX, PositionY + 4 );
		cout << "4. Character loading (in dev!)";
	}
} output;
//--------------------------------------------------------------------------------------------------
//Global Function 		v2.0 	13.07 (0.11)
//trigger - 			v2.0	13.07 (0.11)
//	add description!
//abilityUse - 			v2.0	13.07 (0.11)
//hitSimple - 			v2.0	13.07 (0.11)
//damageDet - 			v2.1	13.07 (0.11)
//abilityUp - 			v2.0	13.07 (0.11)
//abilityUpAll -		v1.0	13.07 (0.11)
//timePassed -			inDev
//getAbilityCount -		v1.0	13.07 (0.11)
//-----DO-NOT-USE-----------------------------------------------------------------------------------
int trigger( string type, Player* self, Player* target, int abilityStat ){
	stringstream output;
	string Desc;
	if( type == "heal" ){
		output << abilityStat;
		Desc = type + " for " + output.str();
		log.push_back(Desc);
		self->stats.hero.hitpointCurrent += abilityStat;
	}
	if( type == "damage" ){
		output << abilityStat;
		Desc = type + " for " + output.str();
		log.push_back(Desc);
		target->stats.hero.hitpointCurrent -= abilityStat;
	}
	if( type == "criticalPower" ){
		self->stats.hero.criticalPower += abilityStat;
	}
	if( type == "criticalChance" ){
		self->stats.hero.criticalChance += abilityStat;
	}
	if( type == "hitpointSet" ){
		self->stats.hero.hitpointCurrent = abilityStat;
	}
}
//--------------------------------------------------------------------------------------------------
int abilityUse( Player* self, Player* target, int abilityId ){
	int c_parameter, abilityStat;
	switch( abilityId ){
		case 1:	//FromGrave type:Active
			if( self->stats.ability.countdown[ abilityId ] == 0 && self->stats.ability.level[ abilityId ] > 0 ){
				if( self->stats.hero.hitpointCurrent <= 0 ){
					output.abilityActive(self, target, abilityId);
					for( c_parameter = 1; c_parameter <= abilityMassive[abilityId].stats.parameterCount; c_parameter++ ){
						trigger(abilityMassive[abilityId].stats.triggerType[ c_parameter ],
								self, target,
								abilityMassive[abilityId].stats.power[ self->stats.ability.level[ abilityId ] ][ c_parameter ]);
					}
					self->stats.ability.countdown[ abilityId ] =abilityMassive[abilityId].stats.countdownMax;
					openImage(abilityMassive[abilityId].stats.name);
					Sleep(1000);	//Temp
					return 1;
				}
				else{
					return 0;
				}
			}
			return 0;
		case 2:	//Critical type:Passive
			for( c_parameter = 1; c_parameter <= abilityMassive[ abilityId ].stats.parameterCount; c_parameter++ ){
				abilityStat = abilityMassive[ abilityId ].stats.power[ self->stats.ability.level[ abilityId ] ][ c_parameter ];
				abilityStat -= abilityMassive[ abilityId ].stats.power[ self->stats.ability.level[ abilityId ] - 1 ][ c_parameter ];
				trigger(abilityMassive[ abilityId ].stats.triggerType[ c_parameter ],
						self,
						target,
						abilityStat);
			}
			return 1;
		case 3:	//LifeDraine type:Active
			if( self->stats.ability.countdown[ abilityId ] == 0 && self->stats.ability.level[ abilityId ] > 0 ){
				output.abilityActive( self, target, abilityId );
				for( c_parameter = 1; c_parameter <= abilityMassive[ abilityId ].stats.parameterCount; c_parameter++ ){
					trigger(abilityMassive[ abilityId ].stats.triggerType[ c_parameter ],
							self,
							target,
							abilityMassive[ abilityId ].stats.power[ self->stats.ability.level[ abilityId ]][ c_parameter ]);
				}
				self->stats.ability.countdown[ abilityId ] = abilityMassive[abilityId].stats.countdownMax;
				/*openImage(self->ability[abilityId].name);*/
				Sleep(500);	//Temp
				return 1;
			}
			else{
				return 0;
			}
	}
}
//--------------------------------------------------------------------------------------------------
int hitSimple( Player* self, Player* target ){
	if( chanceCount() <= self->stats.hero.criticalChance ){
		output.triggerActive( self, target, TRIGGER_ID_CRIT );
		return self->stats.hero.attackPower * ( 100 + self->stats.hero.criticalPower ) / 100;
	}
	return self->stats.hero.attackPower;
}
//--------------------------------------------------------------------------------------------------
void damageGet( Player* self, Player* target, int damage ){
	/*if(blockBuffTime){
		blockBuffTime--;
		damage = damage * (100 - block - blockBuff) / 100;
	}
	else{*/
		damage = damage * ( 100 - target->stats.hero.block ) / 100;
	/*}*/
	output.hit(self, target, damage);
	target->stats.hero.hitpointCurrent -= damage;
}
//--------------------------------------------------------------------------------------------------
void abilityUp( Player* self, Player* target, int abilityId ){
	if(self->stats.ability.level[ abilityId ] < abilityMassive[ abilityId ].stats.levelMax){
		self->stats.ability.level[ abilityId ]++;
		if(abilityMassive[abilityId].stats.actionType == "Passive"){
			abilityUse(self, target, abilityId);
		}
		/*return 1;*/
	}
	/*return 0;*/
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void abilityUpAll(Player* self, Player* target ){
	int c_i, c_j;
	for( c_i = 1; c_i <= self->stats.ability.learn; c_i++ ){
		for(c_j = 1; c_j <= self->stats.ability.levelUp[ c_i ]; c_j++){
			abilityUp( self, target, self->stats.ability.id[ c_i ] );
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void timePassed(int time, Player* player){
	int c_ability;
	/*bugFinder("In TP");*/
	for(c_ability = 1; c_ability < ABILITY_COUNT; c_ability++){
		player->stats.ability.countdown[ c_ability ] = max(player->stats.ability.countdown[ c_ability ] - time, 0);	
	}	
}
void timePassed(int time, Player* Players[], int playerCount){
	int c_ability, c_player;
	for(c_player = 1; c_player <= playerCount; c_player++){
		for(c_ability = 1; c_ability < ABILITY_COUNT; c_ability++){
			Players[ c_player ]->stats.ability.countdown[ c_ability ] =
				max(Players[ c_player ]->stats.ability.countdown[ c_ability ] - time, 0);	
		}	
	}	
}
//-----------------------------------------------------------------------------------------------------------------------------------------
int getAbilityCount(){
	string fileName = "abilities//AbInfo.us";
	int abilityCount;
	if(FileExists( fileName.c_str() )){
		ifstream fin( fileName.c_str() );
		fin >> abilityCount;
	}
	else{
		cout << "Already Writed Abilities:";
		cin >> abilityCount;
	}
	return abilityCount;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
int actionpointCount(Player *Alive[], int playerAlive){
	int actionpointMax;
	int Attack, c_i;
	actionpointMax = Alive[1]->stats.hero.actionpoint;
	Attack = 1;
	for( c_i = 2; c_i <= playerAlive; c_i++ ){
		if(Alive[ c_i ]->stats.hero.actionpoint > actionpointMax){
			actionpointMax = Alive[ c_i ]->stats.hero.actionpoint;
			Attack = c_i;
		}
	}
	bugFinder("Ready for AP up");
	if(actionpointMax < 1000){
		do{
			bugFinder("Loop/");
			Sleep(1000);
			Alive[1]->stats.hero.actionpoint += Alive[1]->stats.hero.actionpointIncrease;
			actionpointMax = Alive[1]->stats.hero.actionpoint;
			Attack = 1;
			for( c_i = 2; c_i <= playerAlive; c_i++ ){
				Alive[ c_i ]->stats.hero.actionpoint += Alive[ c_i ]->stats.hero.actionpointIncrease;
				if(Alive[ c_i ]->stats.hero.actionpoint > actionpointMax){
					actionpointMax = Alive[ c_i ]->stats.hero.actionpoint;
					Attack = c_i;
				}
			}
		} while(actionpointMax < 1000);
	}
	return c_i;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
void defAction(Player *self, Player *target){
	if(!abilityUse(self, target, 3)){
		damageGet(self, target, hitSimple(self, target));
	}
	abilityUse(target, self, 1);
	self->stats.hero.actionpoint -= 1000;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//Main function - 		v0.10	13.07 (0.11)
//PvP -					v2.0	13.07 (0.11)
//Deathmatch -			inDev
//-----------------------------------------------------------------------------------------------------------------------------------------
void PvP(Player* playerFirst, Player* playerSecond){
	Player *Attack, *Def;
	
	system("cls");
	output.all(playerFirst, playerSecond);
	
	while(playerFirst->stats.hero.hitpointCurrent > 0 && playerSecond->stats.hero.hitpointCurrent > 0){
		if(playerFirst->stats.hero.actionpoint < 1000 && playerSecond->stats.hero.actionpoint < 1000){
			playerFirst->stats.hero.actionpoint += playerFirst->stats.hero.actionpointIncrease;
			playerSecond->stats.hero.actionpoint += playerSecond->stats.hero.actionpointIncrease;
			/*bugFinder("Passed");*/
		}
		if(playerFirst->stats.hero.actionpoint >= playerSecond->stats.hero.actionpoint){
			Attack = playerFirst;
			Def = playerSecond;
		}
		else{
			Attack = playerSecond;
			Def = playerFirst;
		}
		if(!abilityUse(Attack, Def, 3)){
			damageGet(Attack, Def, hitSimple(Attack, Def));
		}
		Sleep(1000);				//WTF? GABE FIX IT!
		timePassed(1000, Attack);
		timePassed(1000, Def);
		abilityUse(Def, Attack, 1);
		Attack->stats.hero.actionpoint -= 1000;
		output.all(playerFirst, playerSecond);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------
/*void chooseEnemy(Player[] Players, Player )
*/
void Deathmatch(Player Players[], int playerCount){
	int c_i, attackId, targetId;
	int playerAlive = 0;
	Player *attack, *target, *Alive[10], *PlayersList[10];
	
	system("cls");
	output.playerList(PlayersList, playerCount);
	bugFinder("Ready for loop");
	for( c_i = 1; c_i <= playerCount; c_i++){
		if( Players[ c_i ].stats.hero.hitpointCurrent > 0){
			playerAlive++;
			Alive[ playerAlive ] = &Players[ c_i ];
		}
		PlayersList[ c_i ] = &Players[ c_i ];
	}
	bugFinder("Out of loop");
	if(playerAlive > 0) do{
		attackId = actionpointCount(Alive, playerAlive);
		attack = Alive[ attackId ];
		bugFinder("Attack - " + attack->stats.hero.name);
		output.targetList(Alive, playerAlive, attack);
		cin >> targetId;
		if(targetId <= attackId){
			targetId++;
		}
		target = Alive[ targetId ];
		bugFinder("target - " + target->stats.hero.name);
		defAction(attack, target);
		timePassed(1000, Alive, playerAlive);
		output.playerList(PlayersList, playerCount);
	} while(playerAlive > 1);
}
//--------------------------------------------------------------------------------------------------
int main(/*int argc, char* argv[]*/){
	
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( hConsoleHandle, 15 | BACKGROUND_INTENSITY );
	system("cls");
	
	int abilityCount = getAbilityCount(), mode, playerCount, c_i;
	
	for(c_i = 1; c_i <= abilityCount; c_i++){
		abilityMassive[c_i].readStats(c_i);
	}
	if( true ){
		output.MainMenu( MENU_POSITION_X, MENU_POSITION_Y );
		output.Frame( MENU_SIZE_X, MENU_SIZE_Y, MENU_POSITION_X, MENU_POSITION_Y );
		mode = console.Cursor( MENU_POSITION_X, MENU_POSITION_Y + 1, MENU_MODE_COUNT, '|' );
		
	}
	else{
	console.PositionSet( 30, 0 );
	cout << "Choose game mode*:";
	console.PositionSet( 10, 1 );
	cout << "1 - PvP (1x1)";
	console.PositionSet( 10, 2 );
	cout << "2 - DeathMatch (2+)**";
	console.PositionSet( 10, 3 );
	cout << "3 - Debug!";
	console.PositionSet( 0, 5 );
	cout << "*else (default) - Debug" << endl;
	cout << "**Currently in develop!" << endl;
	mode = console.Cursor( 10 - 1, 1, 3 );
	console.PositionSet(30, 10);	
	}

	if(mode == 1){
		Player Player1, Player2;
		Player *P1 = &Player1, *P2 = &Player2;
		system("cls");
		cout << "Load your heroes:" << endl << endl;
		Player1.readStats();
		Player1.abilityClean();
		Player2.readStats();
		Player2.abilityClean();
		/*Player1.abilityGetInfo(abilityMassive, abilityCount);
		Player2.abilityGetInfo(abilityMassive, abilityCount);*/
		abilityUpAll(P1, P2);
		abilityUpAll(P2, P1);
		output.all(P1, P2);
		PvP(P1, P2);
		system("cls");
		if(P1->stats.hero.hitpointCurrent > P2->stats.hero.hitpointCurrent){
			cout << P1->stats.hero.name << " win!";
		}
		else{
			cout << P2->stats.hero.name << " win!";
		}
	}
	else if(mode == 2){
		Player Players[10], playerReading;
		
		cout << "Players - ";
		cin >> playerCount;
		if(playerCount < 2 || playerCount > 6){
			cout << "reize to 3";
			playerCount = 3;
		}
		for(c_i = 1; c_i <= playerCount; c_i++){
			Players[ c_i ].readStats();
			Players[ c_i ].abilityClean();
			/*Players[ c_i ].abilityGetInfo(abilityMassive, abilityCount);*/
			abilityUpAll( &Players[ c_i ], &Players[ 0 ]);
		}
		Player* PA[ 10 ];
		/*PA = &Players;*/
		output.playerList(PA, playerCount);
		Deathmatch(Players, playerCount);
	}
	else{	//DEBUG ||~-~-~-~-~-~-~-~( =-= )~-~-~-~-~-~-~-~||
		Player Player1;
		int id;
		
		system("cls");
		/*for(c_i = 1; c_i <= abilityCount; c_i++){
			abilityMassive[c_i].readStats(c_i);
		}
		Player1.readStats();
		Player1.abilityClean();
		abilityUpAll(&Player1, &Player1);
		output.abilityList(abilityMassive, abilityCount, Player1, 31, 2);
		id = console.Cursor( 30, 2, abilityCount );
		cout << id;*/
		output.Frame( LOG_SIZE_X, LOG_SIZE_Y, LOG_POSITION_X, LOG_POSITION_Y );
		system("cls");
		output.Frame( MENU_SIZE_X, MENU_SIZE_Y, MENU_POSITION_X, MENU_POSITION_Y);
		output.StringInConsole( MENU_POSITION_X, MENU_POSITION_Y, "U-LEDGE");
		/*bugFinder("abilityClean");
		Player1.abilityClean();
		system("pause");
		bugFinder("abilityGetInfo");
		Player1.abilityGetInfo(abilityMassive, abilityCount);
		system("pause");
		bugFinder("readStats");
		Player1.readStats();
		system("pause");
		bugFinder("AbilityList");
		output.abilityList(abilityMassive, abilityCount);
		system("pause");
		bugFinder("PlayerInfo");
		/*output.playerInfo(Player1, 0, 0);*/
	}
	console.PositionSet( TRASH_POSITION_X, TRASH_POSITION_Y );
	return 0;
}
