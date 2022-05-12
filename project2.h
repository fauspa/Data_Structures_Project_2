//Name= Faus Palting
//Lab501

#ifndef  PROJECT2
#define PROJECT2

#include <string>
#include <vector>
#include <iostream>
#include <set>
//#include<algorithm>
#include <iterator>//apparently when I tried to run this on visual studio, I needed this header.

using namespace std;
typedef vector<string> row;
typedef vector<row> position;
typedef string square;
typedef char color;
typedef string str_rnk_file;
string puzzle_string_whole(string);
#include<algorithm>// for doing set subtraction //

typedef char rnk;
typedef char file;

struct mov {
	square src;
	square dst;
	// compare for order.
	bool operator <(const mov& mv) const
	{

		return (src < mv.src) || ((!(mv.src < src)) && (dst < mv.dst));
	}
};


//_________________________________________________________________________
// Function declaration
position readPosition(string s);


//_________________________________________________________________________


set<mov> legalMoves(position , color );
set<mov> legal_moves(rnk, file, position, color);

set<mov> pawnmovs(rnk,file,position,color);
set<mov> bishmovs(rnk,file,position,color);
set<mov> kingmovs(rnk,file,position,color);
set<mov> rookmovs(rnk,file,position,color);
set<mov> knightmovs(rnk,file,position,color);
set<mov> queenmovs(rnk,file,position,color);

set<mov> m;
set<mov> m_check;

set<string> pawn_attack_king_movs(rnk ,file ,position ,color );
set<string> pawn_attack_movs(rnk,file,position,color);
set<string> bishop_attack_movs(rnk,file,position,color);
set<string> rook_attack_movs(rnk,file,position,color);
set<string> knight_attack_movs(rnk,file,position,color);
set<string> queen_attack_movs(rnk,file,position,color);
set<string> king_attack_movs(rnk,file,position,color);
//THESE NEXT ARE FOR PROJECT2_new
set<mov> opposite_color_attacks_king(position , color );

set<string> all_attack_moves(position,color);
set<string> all_danger_moves(position,color);


set<string>pawn_capture_movs(rnk,file,position,color);
set<string> king_attack_movs_opposite(rnk , file , position, color );

set<string>danger_moves_str_set(rnk,file,position,color);
set<string>attack_moves_str_set(rnk,file,position,color);
int checker(rnk, file, position, color);










#endif

#pragma once
