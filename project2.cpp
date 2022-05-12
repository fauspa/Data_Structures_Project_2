//Faus Palting
//Lab 501




#include"project2.h"



/*
int main()
{
    string s = "Wb1a    Wk6h  WK7e   Bp7g  Bp7h    BK8h";
    position P = readPosition(s);
    color c = 'W';



    set<mov> something = legalMoves(P,c); // seems to work, opposite colors
    cout<<"legal moves end"<<endl;
    for (set<mov>::iterator it = something.begin(); it != something.end(); ++it)
    {
        mov something = *it;
        string s = something.src;
        string d = something.dst;
        cout<<"("<<s<<","<<d<<")";
    }

    s = " BK1d      WK8c    Wr1h    Wr2h";
     P = readPosition(s);
     c = 'B';


    something = legalMoves(P,c); // seems to work, opposite colors
    cout<<"legal moves end"<<endl;
    for (set<mov>::iterator it = something.begin(); it != something.end(); ++it)
    {
        mov something = *it;
        string s = something.src;
        string d = something.dst;
        cout<<"("<<s<<","<<d<<")";
    }





    return 0;
}
*/



position readPosition(string s) // readPosition, builds a vector<vector<string>> called position based on given values (the positions of each piece on board)
{
    string piece;
    position::iterator it_row;
    vector<string>::iterator it_col;
    char rnk;
    char rnk2; // to copy rank into rank 2 without modifying the input of rank.
    char file;
    string puzzle_string= puzzle_string_whole(s);
    vector<string> row(8, "e");
    position pos(8, row);
    position pos2(8,row);
    //pos.resize(8);
    // puts empty"e"in postions
   // for (int i =0; i <pos.size(); i++)
   // {
    //    for (int j=0; j<pos[i].size(); j++)
     //       pos[i][j]="e";
    //}
// prints out positions so we can verify. also use this to put values into board.
/*
for (int i =0; i <pos.size(); i++)
    {
        for (int j=0; j<pos[i].size(); j++)
            cout<<" "<<pos[i][j];
        cout<<endl;
    }

*/ // this would've printed out an 8 X 8 board of empty e's.
    for(int i = 0; i <puzzle_string.length();i+=4)
    {

        cout<<'\n';
        piece = puzzle_string.substr(i,2);  // gets piece from substring.
        rnk = puzzle_string[i+2];//gets the rnk from substring
        file = puzzle_string[i+3];  //gets file from substring
        if (file == 'a')
            file = '1';
        else if (file == 'b' )
            file = '2';
        else if (file == 'c')
            file = '3';
        else if (file =='d')
            file = '4';
        else if (file == 'e' )
            file = '5';
        else if (file == 'f')
            file = '6';
        else if (file =='g')
            file = '7';
        else if (file =='h')
            file = '8';         //converts files into values corresponding with position.
             if (rnk == '1')
            rnk2 = '8';
        else if (rnk == '2' )
            rnk2= '7';
        else if (rnk == '3')
            rnk2 = '6';
        else if (rnk =='4')
            rnk2 = '5';
        else if (rnk == '5')
            rnk2 = '4';
        else if (rnk == '6')
            rnk2 = '3';
        else if (rnk =='7')
            rnk2 = '2';
        else if (rnk =='8')
            rnk2 = '1';              // converts rank into values corresponding with position.

    for (int i =0; i <pos.size(); i++)
    {   int x = rnk -'1';
        int w = rnk2 -'1';
        if(i == x)
        {
        int y = file-'1';

        for (int j=0; j<pos[i].size(); j++)
            if( j == y)
                pos[i][j]= piece;
                 // assigns the piece to the position determined from its rank and file.
        }
        else if (i ==w)
         {
        int y = file-'1';
        for (int j=0; j<pos[i].size(); j++)
            if( j == y)
                pos2[i][j]= piece;
                 // assigns the piece to the position determined from its rank and file.
        }

    }




        //
//cout<<'\n'<<piece<<rnk<<file;// check to see if variables are assigned to correct values.


    }

//cout<<'\n';
//prints out the position board.
/*///////////////////////////////////////////////////////////////this would've printed the board, but since position should be bottom to top and left to right then this wouldn't work since it would show a reversed board (black on bottom, white on top)
for (int i = 0; i < pos.size(); i++)
    {
        for (int j=0; j< pos[i].size(); j++)
            cout<<"  "<<pos[i][j];
        cout<<endl;
    }
*///////////////////////////////////This new one uses a different position that is flipped so it presents black on top.

for(int i =0; i< pos.size(); i++)
{

    for(int j=0; j< pos[i].size(); j++)
        cout<<"  "<<pos2[i][j];
        cout<<endl;
    cout<<endl;
}
return(pos);
}

string puzzle_string_whole(string s)// "sorts" the string by getting rid of spaces, so it can be divided into substrings.
{

    char color;
	char piece_type;
	char rnk;//character rank
	char file;
	string piece_string;

    string puzzle_string = s;
    int puzzle_string_size = puzzle_string.length();

    //goes through string and determines what the information is.
    for (int i = 0; i < puzzle_string_size + 1; i++)
    { char piece_type;
        //checks to see if piece string is white
        if (puzzle_string[i] == 'W')
            {//cout<<"White";
             color = 'W';

            if (puzzle_string[i+1]=='p')
                {/*cout<< "pawn"; can use this to check for correct assignment.
                    */ piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='r')
                {/*cout<< "rook";*/piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='k')
                {
                    //cout<< "knight";
                piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='b')
                {//cout<< "bishop";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='Q')
                {//cout<< "Queen";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='K')
                {//cout<< "King";
                    piece_type= puzzle_string[i+1];}

            if (puzzle_string[i+2]=='1')
                {//cout<< "rank1";
                    rnk= puzzle_string[i+2];}

            else if (puzzle_string[i+2]=='2')
                {//cout<< "rank2";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='3')
                {//cout<< "rank3";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='4')
                {//cout<< "rank4";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='5')
                {//cout<< "rank5";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='6')
                {//cout<< "rank6";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='7')
                {//cout<< "rank7";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='8')
                {//cout<< "rank8";
                    rnk= puzzle_string[i+2];}
            if (puzzle_string[i+3]=='a')
                {//cout<< "file1";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='b')
                {//cout<< "file2";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='c')
                {//cout<< "file3";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='d')
                {//cout<< "file4";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='e')
                {//cout<< "file5";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='f')
                {//cout<< "file6";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='g')
                {//cout<< "file7";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='h')
                {//cout<< "file8";
                    file= puzzle_string[i+3];}

             //cout<<'\n';
             piece_string += color;
             piece_string += piece_type;
             piece_string += rnk;
             piece_string += file;
            //cout<< piece_string;
            //cout<<'\n';
}

        //checks to see if piece string is black affiliated
        if (puzzle_string[i]=='B')
        { color = 'B';
           // cout<<"Black";
            if (puzzle_string[i+1]=='p')
                {//cout<< "pawn";
                     piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='r')
                {//cout<< "rook";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='k')
                {//cout<< "knight";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='b')
                {//cout<< "bishop";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='Q')
                {//cout<< "Queen";
                    piece_type= puzzle_string[i+1];}

            else if (puzzle_string[i+1]=='K')
                {//cout<< "King";
                    piece_type= puzzle_string[i+1];}

            if (puzzle_string[i+2]=='1')
                {//cout<< "rank1";
                    rnk= puzzle_string[i+2];}

            else if (puzzle_string[i+2]=='2')
                {//cout<< "rank2";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='3')
                {//cout<< "rank3";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='4')
                {//cout<< "rank4";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='5')
                {//cout<< "rank5";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='6')
                {//cout<< "rank6";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='7')
                {//cout<< "rank7";
                    rnk= puzzle_string[i+2];}
            else if (puzzle_string[i+2]=='8')
                {//cout<< "rank8";
                    rnk= puzzle_string[i+2];}
            if (puzzle_string[i+3]=='a')
                {//cout<< "file1";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='b')
                {//cout<< "file2";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='c')
                {//cout<< "file3";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='d')
                {//cout<< "file4";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='e')
                {//cout<< "file5";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='f')
                {//cout<< "file6";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='g')
                {//cout<< "file7";
                    file= puzzle_string[i+3];}
            else if (puzzle_string[i+3]=='h')
                {//cout<< "file8";
                    file= puzzle_string[i+3];}
           // cout<<'\n';
             piece_string += color;
             piece_string += piece_type;
             piece_string += rnk;
             piece_string += file;
          //  cout<< piece_string;
           // cout<<'\n';
                }

    }
    string piece_string_whole = piece_string;
    cout<<'\n'<<'\n'<<'\n'<<endl;
    cout<<"Puzzle string given:"<<piece_string_whole<<'\n';
    return(piece_string_whole);
}
// used by readPosition function

//this is what is the "main function for this file, this is the function another file would call)

set<mov> legalMoves(position P, color c)
{


    set<mov> all_movs = {};
    vector<string> row(8,"e");
    position P_enemy(8,row);

    color c_enemy;

    int i;
    int j;
    rnk r;
    file f;
    string file2, rnk2,src;
    set<mov> opposite_attacks_king = {};
    mov king_mov;
    set<mov> king_moves = {};
    set<string> king_attack = {};
    set<string> king_attack_2 = {};
        set<string> king_attack_final = {};

    set<mov> king_final = {};



    if (c == 'B')
    {
        c_enemy = 'W';
    }
    else if(c=='W')
    {
        c_enemy = 'B';
    }

    for(i = 0; i <8; i++)
    {
        for(j = 0; j<8; j++)
            if ((P[i][j][0] == c) && (P[i][j][1] == 'K'))
        {
             r = to_string(i)[0];
             f = to_string(j)[0];
        }
    }

    int check_num_times = checker( r, f, P,  c);

    if(check_num_times>1)
    {

            opposite_attacks_king = opposite_color_attacks_king(P,c);

            if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        king_mov.src = src;

       king_attack= king_attack_movs(r,f,P,c);


       for(set<string>::iterator it = king_attack.begin(); it!= king_attack.end(); it++)
       {
           king_mov.dst = *it;
           king_moves.insert(king_mov);
       }

       set_difference(king_moves.begin(), king_moves.end(),opposite_attacks_king.begin(),opposite_attacks_king.end(),inserter(king_final,king_final.end()));

        return king_final;
    }
    else if (check_num_times == 1)
    {
        // return the possible moves after the three conditions
        // move the king
        // capture the checking piece,
        // block the checking piece.
        // also check for pinning.
    }


    for (int i = 0; i < P.size(); i++)
    {
        for (int j=0; j < 8; j++)
            {
                if (P[i][j][0] != 'e') // checks if occupied, calls if not
                {
                //  ******************************************************************  rnk and file are in 0->7 format, thus functions should convert appropriately.
                // recall starts from zero so we don't have to subtract by one
                rnk r = to_string(i)[0];// converts values of rank and file to string, so we can convert them into the right values (for rank, a char integer, so it doesn't change.
                                                                                                                                //for file a char letter, so we convert it from int
                file f = to_string(j)[0]; // slicing a string value to get a char value // note this makes f a numerical char, so convert to letter char later



////////////////finds when the color matches the desired color // also passes color as a parameter since some of my functions (e.g. pawn) need it to move./////////////////////

              if (P[i][j].substr(0,1)[0] == c ){ // might need to make it so that the parameters passed are for the specific position only.

                //assigns values of legal moves to the set legal_moves_set which then is inserted into the set all_movs which is returned.

                set<mov> legal_moves_set = legal_moves(r, f, P,c);
                all_movs.insert(legal_moves_set.begin(),legal_moves_set.end());



                    }
                }
    }



    }



cout<<"legal moves end in func";

return all_movs;

}


set<mov>legal_moves(rnk r,file f, position P, color c)// this only needs to return the positions, not the ("as","as") set up i think
{
    color c_enemy;
     if (c == 'B')
    {
        c_enemy = 'W';
    }
    else if(c=='W')
    {
        c_enemy = 'B';
    }



    row row2(8,"e");
    position P_enemy(8,row2);
          rnk r_enemy;
             file f_enemy;

    set<string> king_attack_2 = {};
        set<string> king_attack_final = {};

    set<mov> bishop_moves = {};
    set<string> bishop_attack = {};
    mov bish_mov;
    set<mov> rook_moves = {};
        set<string> rook_attack = {};

    mov rook_mov;
    set<mov> knight_moves = {};
        set<string> knight_attack = {};

    mov knight_mov;
    set<mov> queen_moves = {};
        set<string> queen_attack = {};

    mov queen_mov;

    set<mov> pawn_moves = {};
    set<string> pawn_attack = {};
    set<string> pawn_capture = {};
    mov pawn_mov;

    mov king_mov;
    set<mov> king_moves = {};
    set<string> king_attack = {};
    set<mov> opposite_attacks_king = {};
    set<mov> king_final={};
    string src,file2,rnk2;




    char pT = P[r-'0'][f-'0'][1]; //P[i][j] is a string "color piece rnk file" so P[i][j][1] is that string at position 1 which returns a piece type

    if ((pT == 'b')||(pT=='B')) // piece is a bishop
      {bishop_attack = bishop_attack_movs(r,f,P,c);
        if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        bish_mov.src = src;
    for(set<string>::iterator it = bishop_attack.begin(); it!= bishop_attack.end(); it++)
    {
        bish_mov.dst =(*it);
        bishop_moves.insert(bish_mov);
    }

    return bishop_moves;

           }
    else if ((pT == 'k')) // piece is a knight
      {knight_attack = knight_attack_movs(r,f,P,c);
        if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        knight_mov.src = src;
    for(set<string>::iterator it = knight_attack.begin(); it!= knight_attack.end(); it++)
    {
        knight_mov.dst =(*it);
        knight_moves.insert(knight_mov);
    }

        return(knight_moves);
           }
    else if ((pT == 'r')||(pT=='R')) // piece is a rook
    {rook_attack = rook_attack_movs(r,f,P,c);
        if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        rook_mov.src = src;
    for(set<string>::iterator it = rook_attack.begin(); it!= rook_attack.end(); it++)
    {
        rook_mov.dst =(*it);
        rook_moves.insert(rook_mov);
    }

    return (rook_moves);
           }
    else if (pT == 'Q') // piece is a queen
      {queen_attack = queen_attack_movs(r,f,P,c);
        if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        queen_mov.src = src;
    for(set<string>::iterator it = queen_attack.begin(); it!= queen_attack.end(); it++)
    {
        queen_mov.dst =*it;
        queen_moves.insert(queen_mov);

    }

        return(queen_moves);
           }
    else if (pT == 'K') // piece is a king//
        {
             for(int i = 0; i <8; i++)
            {
        for(int j = 0; j<8; j++)
            if ((P[i][j][0] == c_enemy) && (P[i][j][1] == 'K'))
                {
            P_enemy[i][j]=P[i][j];
             r_enemy = to_string(i)[0];
              f_enemy = to_string(j)[0];
                }
                }


            opposite_attacks_king = opposite_color_attacks_king(P,c);
            if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        king_mov.src = src;

       king_attack= king_attack_movs(r,f,P,c);
       king_attack_2 = king_attack_movs_opposite(r_enemy, f_enemy, P_enemy, c_enemy);
        set_difference(king_attack.begin(),king_attack.end(),king_attack_2.begin(),king_attack_2.end(), inserter(king_attack_final,king_attack_final.end()));
       for(set<string>::iterator it = king_attack_final.begin(); it!= king_attack_final.end(); it++)
       {
           king_mov.dst = *it;
           king_moves.insert(king_mov);
       }
       set_difference(king_moves.begin(), king_moves.end(),opposite_attacks_king.begin(),opposite_attacks_king.end(),inserter(king_final,king_final.end()));

        return king_final;

        }
    else if (pT == 'p')
    {
        if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
        src = rnk2+file2;
        pawn_mov.src = src;
//Error is here



       pawn_capture = pawn_capture_movs(r,f,P,c);
       set<string> pawn_final = {};

       pawn_attack= pawn_attack_movs(r,f,P,c);
       pawn_final.insert(pawn_attack.begin(),pawn_attack.end());
       pawn_final.insert(pawn_capture.begin(), pawn_capture.end());
       for(set<string>::iterator it = pawn_final.end(); it!= pawn_final.end(); ++it)
       {
        string s = *it;
       }



       for(set<string>::iterator it = pawn_final.begin(); it!= pawn_final.end(); ++it)
       {
           pawn_mov.dst = *it;
           pawn_moves.insert(pawn_mov);
       }

       return(pawn_moves);

    }

}


set<mov> opposite_color_attacks_king(position P, color c)
{
    char r;
    char f;

    row enemy_row(8,"e");
    mov king_moves_subtract_attacks;
    mov king_movs_subtract_danger;
    set<mov> king_moves_subtract_attacks_danger;
    color c_enemy;
    position P_enemy(8,enemy_row);

    if (c == 'B')
    {
        c_enemy = 'W';
    }
    else if(c=='W')
    {
        c_enemy = 'B';
    }




    //For normal attacks, we can use P, but just pass c_enemy as parameter, attacks are

    //Generates legal moves of other, but make the src of every mov here the src of the king of our original color, this way we can delete the moves that match using set_difference
    //can keep original legal_moves functions, but must modify so it includes any position
    //P_enemy is used to determine the enemy position for sliders (rooks, queens, bishops) since they can move wherever
    // attacks include the source of the piece (the attacks can take), BUT STOPS THERE
    for (int i = 0; i < P.size(); i++)
    {
        for(int j = 0; j< 8; j++)
        {
            if (P[i][j][0] == c_enemy)
            {

                P_enemy[i][j] = P[i][j];

            }
            if(P[i][j][0]==c)
            {
                if(P[i][j][1]=='K')
                {
                   r = to_string(i)[0];
                   f = to_string(j)[0];
                }
            }
        }
    }



    string rnk2,file2;

    if (f == '0')
            file2 = "a";
        else if (f == '1' )
            file2 = "b";
        else if (f == '2')
            file2 = "c";
        else if (f == '3')
            file2 = "d";
        else if (f == '4' )
            file2 = "e";
        else if (f == '5')
            file2 = "f";
        else if (f =='6')
            file2 = "g";
        else if (f =='7')
            file2 = "h";

        if (r == '0')
            rnk2 = "1";
        else if (r == '1' )
            rnk2 = "2";
        else if (r== '2')
            rnk2 = "3";
        else if (r =='3')
            rnk2 = "4";
        else if (r == '4' )
            rnk2 = "5";
        else if (r == '5')
            rnk2 = "6";
        else if (r =='6')
            rnk2 = "7";
        else if (r =='7')
            rnk2 = "8";
    string king_src = rnk2+file2;

    king_moves_subtract_attacks.src = king_src;
    king_movs_subtract_danger.src = king_src;

    // this string set includes the char integers that all the opposite color's pieces can move to.
    //acts as if king is invisible so we can see if the attack goes behind the king if slider enemy

    set<string> enemy_attacks_dst = all_attack_moves(P_enemy,c_enemy);

    //enemy_src, MUST BE equal to the src of the king otherwise, we can't do set subtraction later
    for (set<string>::iterator it = enemy_attacks_dst.begin(); it != enemy_attacks_dst.end(); ++it)
    {
        // assign value of king's source moves here to the enemy's dst moves
        // then insert into a set<mov> I think. so we can subtract later, or do it after
        string dst = *it;
        king_moves_subtract_attacks.dst = dst;
        king_moves_subtract_attacks_danger.insert(king_moves_subtract_attacks);
    }

    set<string> enemy_danger_dst = all_danger_moves(P_enemy,c_enemy);
    for (set<string>::iterator it = enemy_danger_dst.begin(); it != enemy_danger_dst.end(); ++it)
     {
         string dst = *it;
         king_movs_subtract_danger.dst = dst;
         king_moves_subtract_attacks_danger.insert(king_movs_subtract_danger);
     }
for (set<mov>::iterator it = king_moves_subtract_attacks_danger.begin(); it != king_moves_subtract_attacks_danger.end(); ++it) {
		mov mymov = *it;
		string s = mymov.src;
		string d = mymov.dst;


	}





return king_moves_subtract_attacks_danger;

}

set<string> all_attack_moves(position P,color c)
{
    set<string> attack_moves = {};

    for(int i = 0; i< P.size(); i++)
    {
        // iterates through to get the rank and file of each matching enemy piece, then calls the function that
        // calls the functions which yield the possible destinations for the enemy piece (where they can attack)
     for(int j = 0; j < 8; j++)
        {
            rnk r = to_string(i)[0];
            rnk f = to_string(j)[0];
            if(P[i][j][0] == c)
            {
                set<string>set_attack_moves = attack_moves_str_set(r,f, P,c);
                attack_moves.insert(set_attack_moves.begin(),set_attack_moves.end());
            }


        }

    }



return attack_moves;

}


set<string> all_danger_moves(position P_enemy, color c_enemy)
{
    set<string> danger_moves={};


    for(int i = 0; i < 8; i ++)
    {
        //iterates through to get rank and file and calls the danger piece attacks functions.
        //because there are no opposite color pieces, every possible enemy move can be made here.
        // this is only really useful for king pieces.
        for(int j = 0; j < 8; j++)
        {
            rnk r = to_string(i)[0];
            rnk f = to_string(j)[0];
            if(P_enemy[i][j][0] == c_enemy)
            {   // only one color, so function should just pass all possible moves for each of those pieces
                danger_moves = attack_moves_str_set(r,f,P_enemy,c_enemy);
            }
        }
    }





return danger_moves;
}

set<string> attack_moves_str_set(rnk r, file f, position P, color c)
{
    char pT = P[r-'0'][f-'0'][1]; //P[i][j] is a string "color piece rnk file" so P[i][j][1] is that string at position 1 which returns a piece type

    if ((pT == 'b')) // piece is a bishop
        return bishop_attack_movs(r,f,P,c);

    else if ((pT == 'k')) // piece is a knight
        return knight_attack_movs(r,f,P,c);

    else if ((pT == 'r')||(pT=='R')) // piece is a rook
        return rook_attack_movs(r,f,P,c);

    else if (pT == 'Q') // piece is a queen
        return queen_attack_movs(r,f,P,c);

    else if (pT == 'K') // piece is a king//
        return king_attack_movs(r,f,P,c);

    else if ((pT =='p')||(pT=='P'))  // piece is a pawn // need color since pawn direction determined by it.
        return pawn_attack_king_movs(r,f,P,c);

}
//bishop returns all legal moves if empty
set<string> bishop_attack_movs(rnk r,file f,position P,color c)
{


    string bishop_attack_move_dst;
    set<string> bishop_attack_moves_set= {};
    int j = (f-'0')+1;

    string rnk2;
    string file2;

    for( int i = (r-'0')+1 ; i >= 0 && i<8 && j<8 && j>=0 ; i++) // movment of bishop southeast// we want to insert the struct with src and dst which we can get from rnk_n_file//need to convert it to the standard 1->8 and a->h
{

                if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                bishop_attack_move_dst = rnk2+file2;

                cout<<bishop_attack_move_dst;
                if(P[i][j][0] == c)
                    {
                    break;
                        }

                bishop_attack_moves_set.insert(bishop_attack_move_dst);

               if(P[i][j][0]!='e')
                {
                    break;

                }



            j++;

            }


         j = ( f-'0')+1;


        for( int i = (r-'0')-1; i >= 0 && i<8 && j<8 && j>=0; i-- ) // movment of bishop to right/up (northeast
            {


                 if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                bishop_attack_move_dst = rnk2+file2;

                if(P[i][j][0] == c)
                    break;
                bishop_attack_moves_set.insert(bishop_attack_move_dst);
                if(P[i][j][0]!='e')
                    break;

            j++ ;
            }

        j = (f-'0')-1;

        for(int i = (r-'0')+1; i >= 0 && i<8 && j<8 && j>=0; i++ ) //movs southwest
            {


                 if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                bishop_attack_move_dst = rnk2+file2;


                if(P[i][j][0] == c)
                    break;
                bishop_attack_moves_set.insert(bishop_attack_move_dst);
                if(P[i][j][0]!='e')
                    break;
            j--;
            }

        j = (f-'0')-1;

        for(int i = (r-'0')-1; i >= 0 && i<8 && j<8 && j>=0; i-- ) //movs northwest
            {


                  if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                bishop_attack_move_dst = rnk2+file2;

                if(P[i][j][0] == c)
                    break;
                bishop_attack_moves_set.insert(bishop_attack_move_dst);
                if(P[i][j][0]!='e')
                    break;
            j--;



            }

            return bishop_attack_moves_set;
}

set<string> pawn_attack_movs(rnk r,file f,position P,color c) //working, i think
{
    set<string> pawn_attack_moves_set = {};
    string pawn_attack_move_dst;
    int i = (r-'0');
    int j = (f-'0');
    string rnk2, file2;

    int counter = 0;

    if(c=='W')
{
    for( i = (r-'0') ; i >= 0 && i<8 && j<8 && j>=0 && counter < 1; counter++  ){
                if ((i +1) == 0)
                    rnk2 = "1";
                else if ((i+1) == 1 )
                    rnk2 = "2";
                else if ((i+1)== 2)
                    rnk2 = "3";
                else if ((i +1) ==3)
                    rnk2 = "4";
                else if ((i +1) == 4 )
                    rnk2 = "5";
                else if ((i +1) == 5)
                    rnk2 = "6";
                else if ((i +1) ==6)
                    rnk2 = "7";
                else if ((i +1) ==7)
                    rnk2 = "8";

                    if ((j +1) == 0)
                     file2 = "a";
                else if ((j +1) == 1 )
                    file2 = "b";
                else if ((j +1) == 2)
                    file2 = "c";
                else if ((j +1) == 3)
                    file2 = "d";
                else if ((j +1) == 4 )
                    file2 = "e";
                else if ((j +1) == 5)
                    file2 = "f";
                else if ((j +1) ==6)
                    file2 = "g";
                else if ((j +1) ==7)
                    file2 = "h";


                  pawn_attack_move_dst = rnk2+file2;
                if((i+1)>=0&&(i+1)<8&&(j+1)>=0&&(j+1)<8)
                    {
                        if((P[i+1][j+1][0]!='e')&& P[i+1][j+1][0]!=c){
                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                        }
                    }

                }

            if ((i >= 0) && (i<8) && (j<8) && (j>=0))
                {


                if ((i +1) == 0)
                    rnk2 = "1";
                else if ((i +1) == 1 )
                    rnk2 = "2";
                else if ((i+1)== 2)
                    rnk2 = "3";
                else if ((i +1) ==3)
                    rnk2 = "4";
                else if ((i +1) == 4 )
                    rnk2 = "5";
                else if ((i +1) == 5)
                    rnk2 = "6";
                else if ((i +1) ==6)
                    rnk2 = "7";
                else if ((i +1) ==7)
                    rnk2 = "8";

                    if ((j -1) == 0)
                     file2 = "a";
                else if ((j -1) == 1 )
                    file2 = "b";
                else if ((j -1) == 2)
                    file2 = "c";
                else if ((j -1) == 3)
                    file2 = "d";
                else if ((j -1) == 4 )
                    file2 = "e";
                else if ((j -1) == 5)
                    file2 = "f";
                else if ((j -1) ==6)
                    file2 = "g";
                else if ((j -1) ==7)
                    file2 = "h";


                   pawn_attack_move_dst = rnk2+file2;

                 if((i+1)>=0&&(i+1)<8&&(j-1)>=0&&(j-1)<8)
                    {
                        if((P[i+1][j-1][0]!='e'&& P[i+1][j-1][0]!=c)){
                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                        }
                    }
                }



}
 counter = 0;

    if(c=='B')
{
    for( i = (r-'0') ; i >= 0 && i<8 && j<8 && j>=0 && counter < 1; counter++  ){

                if ((i -1) == 0)
                    rnk2 = "1";
                else if ((i -1) == 1 )
                    rnk2 = "2";
                else if ((i-1)== 2)
                    rnk2 = "3";
                else if ((i -1) ==3)
                    rnk2 = "4";
                else if ((i -1) == 4 )
                    rnk2 = "5";
                else if ((i -1) == 5)
                    rnk2 = "6";
                else if ((i -1) ==6)
                    rnk2 = "7";
                else if ((i -1) ==7)
                    rnk2 = "8";

                    if ((j -1) == 0)
                     file2 = "a";
                else if ((j -1) == 1 )
                    file2 = "b";
                else if ((j -1) == 2)
                    file2 = "c";
                else if ((j -1) == 3)
                    file2 = "d";
                else if ((j -1) == 4 )
                    file2 = "e";
                else if ((j -1) == 5)
                    file2 = "f";
                else if ((j -1) ==6)
                    file2 = "g";
                else if ((j -1) ==7)
                    file2 = "h";


                  pawn_attack_move_dst = rnk2+file2;

                 if((i-1)>=0&&(i-1)<8&&(j-1)>=0&&(j-1)<8)
                    {
                        if((P[i-1][j-1][0]!='e'&& P[i-1][j-1][0]!=c)){
                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                        }
                    }
                }

            if ((i >= 0) && (i<8) && (j<8) && (j>=0))
                {


                if ((i -1) == 0)
                    rnk2 = "1";
                else if ((i -1) == 1 )
                    rnk2 = "2";
                else if ((i-1)== 2)
                    rnk2 = "3";
                else if ((i -1) ==3)
                    rnk2 = "4";
                else if ((i -1) == 4 )
                    rnk2 = "5";
                else if ((i -1) == 5)
                    rnk2 = "6";
                else if ((i -1) ==6)
                    rnk2 = "7";
                else if ((i -1) ==7)
                    rnk2 = "8";

                    if ((j +1) == 0)
                     file2 = "a";
                else if ((j +1) == 1 )
                    file2 = "b";
                else if ((j +1) == 2)
                    file2 = "c";
                else if ((j +1) == 3)
                    file2 = "d";
                else if ((j +1) == 4 )
                    file2 = "e";
                else if ((j +1) == 5)
                    file2 = "f";
                else if ((j +1) ==6)
                    file2 = "g";
                else if ((j +1) ==7)
                    file2 = "h";


                   pawn_attack_move_dst = rnk2+file2;

                if((i-1)>=0&&(i-1)<8&&(j+1)>=0&&(j+1)<8)
                    {
                        if((P[i-1][j+1][0]!='e'&& P[i-1][j+1][0]!=c)){
                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                        }
                    }
                }



}



return pawn_attack_moves_set;
}
//fix is in knight attacks, it's unable to realize if within the board, so in the if statement specifications.
set<string> knight_attack_movs(rnk r,file f,position P,color c) // working, i think
{


    set<string> knight_attack_movs_set = {};

    int int_file = f - '0';
    int int_rnk = r - '0';

    string knight_attack_move_dst;

    string file2;
    string rnk2;

    string rnk2_n_file2;





        //convert value of the f to a number string, see above to converting it into an int
        if (f == '0')
            file2 = "0";
        else if (f == '1' )
            file2 = "1";
        else if (f == '2')
            file2 = "2";
        else if (f =='3')
            file2 = "3";
        else if (f == '4')
            file2 = "4";
        else if (f == '5')
            file2 = "5";
        else if (f == '6')
            file2 = "6";
        else if (f == '7')
            file2 = "7";



        string string_file;
        string string_rnk;

        string rnk_n_file;

        int i = int_rnk;
        int j = int_file;


         // movement of knight [2 up right one)

            string_rnk = to_string(i+2);
            string_file= to_string(j+1);
            rnk_n_file = (string_rnk+string_file);



            if (((i)>=0) && ((i)<8) && ((j) <8) && ((j)>=0))
                    {
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";



                    knight_attack_move_dst = rnk2+file2;


                   if((i+2)< 8 &&(i+2)>= 0&&(j+1)< 8&&((j+1)>= 0))
                   {
                    if(P[i+2][j+1][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
             }
                }
                }
             i = int_rnk;
            j = int_file;



         //move  up 2 left 1


            string_rnk = to_string( i +2);
            string_file= to_string( j-1);
            rnk_n_file = (string_rnk+string_file);

  if (((i)>(0))&&((i) <8) && ((j) <8) && ((j)>=0))
                     {
                cout<<endl<<2;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";

                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                    knight_attack_move_dst = rnk2+file2;

                      if((i+2)< 8 &&(i+2)>= 0&&(j-1)< 8&&((j-1)>= 0))
                   {
                    if(P[i+2][j-1][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                   }
                }

                    }

            //move  down 2 left 1
             i = int_rnk;
             j = int_file;


            string_rnk = to_string( i -2);
            string_file= to_string( j-1);
            rnk_n_file = (string_rnk+string_file);

           if (((i-2) >=0) && ((i-2) <8) && ((j-1) <8) && ((j-1)>=0))
                      {
                cout<<endl<<3;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                    knight_attack_move_dst = rnk2+file2;
                    if((i-2)< 8 &&(i-2)>= 0&&(j-1)< 8&&((j-1)>= 0))
                   {
                    if(P[i-2][j-1][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }
                    }

             i = int_rnk;
            j = int_file;

            //move  down 2 right 1


            string_rnk = to_string(i-2);
            string_file= to_string(j+1);
            rnk_n_file = (string_rnk+string_file);

            if (((i-2) >=0) && ((i-2) <8) && ((j+1) <8) && ((j+1)>=0)&&(P[i-2][j+1][0] != c))
                     {
                cout<<endl<<4;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                    knight_attack_move_dst = rnk2+file2;

                      if((i-2)< 8 &&(i-2)>= 0&&(j+1)< 8&&((j+1)>= 0))
                   {
                    if(P[i-2][j+1][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }

                    }

        //move  left 2 up one

             i = int_rnk;
            j = int_file;

            string_rnk = to_string( i +1);
            string_file= to_string( j-2);
            rnk_n_file = (string_rnk+string_file);

              if (((i+1) >=0) && ((i+1) <8) && ((j-2) <8) && ((j-2)>=0))
                    {
                cout<<endl<<5;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                    knight_attack_move_dst = rnk2+file2;

                      if((i+1)< 8 &&(i+1)>= 0&&(j-2)< 8&&((j-2)>= 0))
                   {
                    if(P[i+1][j-2][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }

                    }



         //move  left 2 down one
            i = int_rnk;
            j = int_file;


            string_rnk = to_string( i -1);
            string_file= to_string( j-2);
            rnk_n_file = (string_rnk+string_file);

             if(((i-1)>=0)&&((i-1) <8)&&((j-2)<8) && ((j-2)>=0))
                    {
                cout<<endl<<6;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                    knight_attack_move_dst = rnk2+file2;

                      if((i-1)< 8 &&(i-1)>= 0&&(j-2)< 8&&((j-2)>= 0))
                   {
                    if(P[i-1][j-2][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }
                    }


             i = int_rnk;
            j = int_file;


        //  right 2 down one


            string_rnk = to_string(i -1);
            string_file= to_string( j+2);
            rnk_n_file = (string_rnk+string_file);
                  if (((i-1) >=0) && ((i-1) <8) && ((j+2) <8 )&& ((j+2)>=0))
                   {
                cout<<endl<<7;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";


                     knight_attack_move_dst = rnk2+file2;

                      if((i-1)< 8 &&(i-1)>= 0&&(j+2)< 8&&((j+2)>= 0))
                   {
                    if(P[i-1][j+2][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }
                    }


            i = int_rnk;
            j = int_file;
        //move  right 2 up one


            string_rnk = to_string( i +1);
            string_file= to_string( j+2);
            rnk_n_file = (string_rnk+string_file);
                 if (((i+1)>=0 )&& ((i+1) <8) && ((j+2) <8) && ((j+2)>=0))
                   {
                cout<<endl<<8;
                if (string_rnk == "0")
                    rnk2 = "1";
                else if (string_rnk == "1" )
                    rnk2 = "2";
                else if (string_rnk== "2")
                    rnk2 = "3";
                else if (string_rnk =="3")
                    rnk2 = "4";
                else if (string_rnk == "4" )
                    rnk2 = "5";
                else if (string_rnk == "5")
                    rnk2 = "6";
                else if (string_rnk =="6")
                    rnk2 = "7";
                else if (string_rnk =="7")
                    rnk2 = "8";
                    if (string_file == "0")
                     file2 = "a";
                else if (string_file == "1" )
                    file2 = "b";
                else if (string_file == "2")
                    file2 = "c";
                else if (string_file == "3")
                    file2 = "d";
                else if (string_file == "4" )
                    file2 = "e";
                else if (string_file == "5")
                    file2 = "f";
                else if (string_file =="6")
                    file2 = "g";
                else if (string_file =="7")
                    file2 = "h";

                    knight_attack_move_dst = rnk2+file2;

                      if((i+1)< 8 &&(i+1)>= 0&&(j+2)< 8&&((j+2)>= 0))
                   {
                    if(P[i+1][j+2][0] != c)
                    {knight_attack_movs_set.insert(knight_attack_move_dst);
                    }
                }
                    }

            cout<<endl<<"went through knight"<<endl;
            return knight_attack_movs_set;

}

set<string> rook_attack_movs(rnk r, file f, position P, color c) // working i think
{cout<<endl<<"rook_attack_movs";

    set<string>rook_attack_movs_set = {};
    int int_rnk = r-'0';
    int int_file = f-'0';

    string rook_attack_move_dst;

    string file2;
    string rnk2;

    string rnk2_n_file2;
    char r2;
    char f2;
        if(f == '0')
                { f2 = 'a';}
                if(f == '1')
                { f2 = 'b';}
                if(f == '2')
                { f2 = 'c';}
                if(f == '3')
                { f2 = 'd';}
                if(f == '4')
                { f2 = 'e';}
                if(f == '5')
                { f2 = 'f';}
                if(f == '6')
                { f2 = 'g';}
                if(f == '7')
                { f2 = 'h';}

                if(r == '0')
                { r2 = '1';}
                if(r == '1')
                { r2 = '2';}
                if(r == '2')
                { r2 = '3';}
                if(r == '3')
                { r2 = '4';}
                if(r == '4')
                { r2 = '5';}
                if(r == '5')
                { r2 = '6';}
                if(r == '6')
                { r2 = '7';}
                if(r == '7')
                { r2 = '8';}

    string str_rnk(1,r2);//converts a character into a string
    string str_file(1,f2);






        //convert value of the f to a number string, see above to converting it into an int
        if (f == '0')
            file2 = "0";
        else if (f == '1' )
            file2 = "1";
        else if (f == '2')
            file2 = "2";
        else if (f =='3')
            file2 = "3";
        else if (f == '4')
            file2 = "4";
        else if (f == '5')
            file2 = "5";
        else if (f == '6')
            file2    = "7";
        else if (f == '7')
            file2 = "7";

        string string_file;
        string string_rnk;

        string rnk_n_file;



        int j = int_file;

        for( int i = int_rnk; i >= 0 && i<8 && j<8 && j>=0; i = int_rnk )
            {

            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(int_rnk))+f)
            {
                 if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";



                    if(P[i][j][0]==c)
                    break;
                    rook_attack_move_dst = rnk2+file2;
                    rook_attack_movs_set.insert(rook_attack_move_dst);
                    if(P[i][j][0]!= 'e')
                    break;
            }
            j++;
            }

             j = int_file;
        for( int i = int_rnk; i >= 0 && i<8 && j<8 && j>=0; i = int_rnk ) // movement of bishop southeast
            { string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(int_rnk))+f)
            {


               if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if(P[i][j][0]==c)
                    break;
                    rook_attack_move_dst = rnk2+file2;
                    rook_attack_movs_set.insert(rook_attack_move_dst);

                    if(P[i][j][0]!= 'e')
                    break;

                    }
            j--;
            }

             j = int_file;

            for( int i = int_rnk; i >= 0 && i<8 && j<8 && j>=0; i++ ) // movement of bishop southeast
            { string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(int_rnk))+f)
            {


                if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";


                    if(P[i][j][0]==c)
                    break;
                    rook_attack_move_dst = rnk2+file2;
                    rook_attack_movs_set.insert(rook_attack_move_dst);
                    if(P[i][j][0]!= 'e')
                    break;
                    }

            }

            j = int_file;
            for( int i = int_rnk; i >= 0 && i<8 && j<8 && j>=0; i-- ) // movement of bishop southeast
            {

            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(int_rnk))+f)
            {
                if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";



                    if(P[i][j][0]==c)
                    break;
                    rook_attack_move_dst = rnk2+file2;
                    rook_attack_movs_set.insert(rook_attack_move_dst);
                    if(P[i][j][0]!= 'e')
                    break;
                    }

            }

    cout<<endl<<"went through rook"<<endl;// correct, it did go through
    return rook_attack_movs_set;


}

set<string> queen_attack_movs(rnk r, file f, position P, color c)
{cout<<endl<<"queen_attack_movs";
    set<string> queen_attack_movs_set;
    set<string> queen_attack_movs_set_2;


    queen_attack_movs_set=rook_attack_movs(r,f,P,c);
    queen_attack_movs_set_2=bishop_attack_movs(r,f,P,c);

    queen_attack_movs_set.insert(queen_attack_movs_set_2.begin(),queen_attack_movs_set_2.end());

    return queen_attack_movs_set;
}

set<string> king_attack_movs(rnk r, file f, position P, color c)
{cout<<endl<<"king_attack_movs";


    set<string> king_attack_movs_set = {};
    string king_attack_move_dst;
    char r2 = r;
    char f2 = f;
    string file2;
    string file3;//for the src string
    string rnk2;
    string rnk2_n_file2;
    string str_rnk(1,r2);//converts a character into a string
    string str_file(1,f2);
    string rnk_file_src = str_rnk+str_file;

            // has to subtract zero char in order to work else we get ascii character values.
        int num = r - '0'; //converts "1" string to int of value 1, so i can modify it for moving the piece
        //int rnk1 = num - 1; // might need to change this if it's already been subtracted by 1
        int rnk1 = num;
        string str_rnk_int = to_string(rnk1);
        string file1 = rnk_file_src.substr(1,2);
         int rnk_int = num;
        //string str_rnk_int = to_string(rnk_int);



        //convert value of the file to a number string, see above to converting it into an int
         if (f == '0'){
            file1 = "0";
            file3 = "a";}
        else if (f == '1' )
            {file1 = "1";
             file3 = "b";}
        else if (f == '2')
            {file1 = "2";
             file3 = "c";}
        else if (f =='3')
            {file1 = "3";
            file3 = "d";}
        else if (f == '4' )
            {file1 = "4";
            file3 = "e";}
        else if (f == '5')
            {file1 = "5";
            file3 = "f";}
        else if (f == '6')
            {file1 = "6";
            file3 = "g";}
        else if (f == '7')
           {file1 = "7";
            file3 = "h";}


          if (r == '0')
                    rnk2 = "1";
                else if (r == '1' )
                    rnk2 = "2";
                else if (r== '2')
                    rnk2 = "3";
                else if (r =='3')
                    rnk2 = "4";
                else if (r == '4' )
                    rnk2 = "5";
                else if (r == '5')
                    rnk2 = "6";
                else if (r =='6')
                    rnk2 = "7";
                else if (r =='7')
                    rnk2 = "8";

        int file_int = stoi(file1);

        string string_file;
        string string_rnk;

        string rnk_n_file;


        int i = rnk1;
        int j = file_int;
        // issue is the for loop statement and how r + '1' doesn't work, it has to be char value number - '0' otherwise we get ascii
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0 &&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);

            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                    king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j++;

            }

            i = rnk1;
            j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                    king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j--;

            }

            i = rnk1;
            j = file_int;

            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            i++;
            }
            i = rnk1;
            j = file_int;
            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            i--;
            }
            i = rnk1;
            j = file_int;

            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j++;
            i++;
            }

        i = rnk1;
        j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king to right/up (northeast
            {
            string_rnk = to_string(i);
            string_file= to_string(j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }


            }
            j++ ;
            i--;
            }
        i = rnk1;
        j = file_int;

        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) //movs southwest
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }



            }

            j--;
            i++;
            }

        i = rnk1;
        j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&& king_lim <= 1; king_lim++ ) //movs northwest
            {
            string_rnk = to_string(i);
            string_file= to_string(j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]!=c)
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }

            j--;
            i--;
            }
//THIS IS FOR CASTLING THE KING FOR BLACK  (WHICH IS ON BOTTOM)
//
/*
        int castle_rnk = r-'0';
        int castle_file = f-'0';

        if(c == 'B')
        {cout<<P[castle_rnk][castle_file].substr(0,2);
            if(P[castle_rnk][castle_file].substr(0,2) == "BK")
            {
                if((P[castle_rnk][castle_file-1][0]=='e')&&(P[castle_rnk][castle_file-2][0]=='e')&&(P[castle_rnk][castle_file-3][1]== ('r')))
                {
                    cout<<"can castle king side";
                }
                if((P[castle_rnk][castle_file+1][0]=='e')&&(P[castle_rnk][castle_file+2][0]=='e')&&(P[castle_rnk][castle_file+3][0]=='e')&&(P[castle_rnk][castle_file+4][1]== ('r')))
                {
                    cout<<"can castle queen side";
                }
            }

        }
         if(c == 'W')
        {
            if(P[castle_rnk][castle_file].substr(0,2) == "WK")
            {
                if((P[castle_rnk][castle_file+1][0]=='e')&&(P[castle_rnk][castle_file+2][0]=='e')&&(P[castle_rnk][castle_file+3][1]== 'r'))
                {
                    cout<<"can castle king side";
                }
                if((P[castle_rnk][castle_file-1][0]=='e')&&(P[castle_rnk][castle_file-2][0]=='e')&&(P[castle_rnk][castle_file-3][0]=='e')&&(P[castle_rnk][castle_file-4][1]== ('r')))
                {
                    cout<<"can castle queen side";
                }
            }

        }  */

            cout<<endl<<"went through king"<<endl;
            return king_attack_movs_set;
}

int checker(rnk r, file f, position P, color c)
{ cout<<"int_checker";
    set<string> pawn_set;
    set<string> rook_set;
    set<string> queen_set;
    set<string> knight_set;
    set<string> bishop_set;

    set<string> pawn_set2;
    set<string> rook_set2;
    set<string> queen_set2;
    set<string> knight_set2;
    set<string> bishop_set2;
    string temp;
    int rnk2 = 0;
    int file3 = 0;




    int check_times = 0;
    // if king in check > 1, only king can move.
    //else if king in check < 1 one of three moves can happen.
    //look at the king's position and treat it as if it can move as any piece, if a corresponding piece is on where it moves and is the opposite color, it is in check.


    for(int i = 0; i <8; i++)
    {
        for(int j = 0; j< 8; j++)
        {
            if((P[i][j][0]==c)&&(P[i][j][1]=='K'))
            {
                rnk r = to_string(i)[0];
                file f = to_string(j)[0];

            }
        }
    }
// rnk r and  f are the value of the king.
color c_enemy;
if(c == 'B')
    c_enemy = 'W';
else if(c == 'W')
    c_enemy = 'B';
    // change values of elements in each set to numerical 0=> 7 , this way we can use it to compare


// then king acts as all pieces to see if it moves, need to make it so that it checks if there are the right pieces in those places after calling.
// so convert the returned set of dst's to int rnk and file and check if there is a piece matching at that location
    pawn_set=pawn_attack_movs(r,f,P,c);

    queen_set=queen_attack_movs(r,f,P,c);
    rook_set=rook_attack_movs(r,f,P,c);
    knight_set=knight_attack_movs(r,f,P,c);
    bishop_set=bishop_attack_movs(r,f,P,c);




    // takes the set of destinations for the piece type,but from the pos
    //of the king. if the destinations have a matching piece type to the move it made,
    //the king is in check by that piece.


        for(set<string>::iterator it = pawn_set.begin(); it!= pawn_set.end(); it++)
    {
        temp = (*it);

         if (temp.substr(0,2)[0] == '1')
                     rnk2 = 0;
                else if (temp.substr(0,2)[0]== '2' )
                    rnk2 = 1;
                else if (temp.substr(0,2)[0] =='3')
                    rnk2 =  2;
                else if (temp.substr(0,2)[0] =='4')
                    rnk2 = 3;
                else if (temp.substr(0,2)[0] =='5' )
                    rnk2 = 4;
                else if (temp.substr(0,2)[0] =='6')
                    rnk2 = 5;
                else if (temp.substr(0,2)[0] =='7')
                    rnk2 = 6;
                else if (temp.substr(0,2)[0] == '8')
                    rnk2 = 7;

                if (temp.substr(0,2)[1] == 'a')
                    file3 = 0;
                else if (temp.substr(0,2)[1] == 'b' )
                    file3 = 1;
                else if (temp.substr(0,2)[1] == 'c')
                    file3 = 2;
                else if (temp.substr(0,2)[1] =='d')
                    file3 = 3;
                else if (temp.substr(0,2)[1] == 'e' )
                    file3 = 4;
                else if (temp.substr(0,2)[1] == 'f')
                    file3 = 5;
                else if (temp.substr(0,2)[1] =='g')
                    file3 = 6;
                else if (temp.substr(0,2)[1] =='h')
                    file3 = 7;

                if((P[rnk2][file3][0]==c_enemy)&&(P[rnk2][file3][1] == 'p'))
                {
                    check_times +=1;
                }


    }


for(set<string>::iterator it = bishop_set.begin(); it!= bishop_set.end(); it++)
    {
        temp = (*it);

         if (temp.substr(0,2)[0] == '1')
                     rnk2 = 0;
                else if (temp.substr(0,2)[0]== '2' )
                    rnk2 = 1;
                else if (temp.substr(0,2)[0] =='3')
                    rnk2 =  2;
                else if (temp.substr(0,2)[0] =='4')
                    rnk2 = 3;
                else if (temp.substr(0,2)[0] =='5' )
                    rnk2 = 4;
                else if (temp.substr(0,2)[0] =='6')
                    rnk2 = 5;
                else if (temp.substr(0,2)[0] =='7')
                    rnk2 = 6;
                else if (temp.substr(0,2)[0] == '8')
                    rnk2 = 7;

                if (temp.substr(0,2)[1] == 'a')
                    file3 = 0;
                else if (temp.substr(0,2)[1] == 'b' )
                    file3 = 1;
                else if (temp.substr(0,2)[1] == 'c')
                    file3 = 2;
                else if (temp.substr(0,2)[1] =='d')
                    file3 = 3;
                else if (temp.substr(0,2)[1] == 'e' )
                    file3 = 4;
                else if (temp.substr(0,2)[1] == 'f')
                    file3 = 5;
                else if (temp.substr(0,2)[1] =='g')
                    file3 = 6;
                else if (temp.substr(0,2)[1] =='h')
                    file3 = 7;

                if((P[rnk2][file3][0]==c_enemy)&&(P[rnk2][file3][1] == 'b'))
                {
                    check_times +=1;
                }


    }
for(set<string>::iterator it = queen_set.begin(); it!= queen_set.end(); it++)
    {
        temp = (*it);

         if (temp.substr(0,2)[0] == '1')
                     rnk2 = 0;
                else if (temp.substr(0,2)[0]== '2' )
                    rnk2 = 1;
                else if (temp.substr(0,2)[0] =='3')
                    rnk2 =  2;
                else if (temp.substr(0,2)[0] =='4')
                    rnk2 = 3;
                else if (temp.substr(0,2)[0] =='5' )
                    rnk2 = 4;
                else if (temp.substr(0,2)[0] =='6')
                    rnk2 = 5;
                else if (temp.substr(0,2)[0] =='7')
                    rnk2 = 6;
                else if (temp.substr(0,2)[0] == '8')
                    rnk2 = 7;

                if (temp.substr(0,2)[1] == 'a')
                    file3 = 0;
                else if (temp.substr(0,2)[1] == 'b' )
                    file3 = 1;
                else if (temp.substr(0,2)[1] == 'c')
                    file3 = 2;
                else if (temp.substr(0,2)[1] =='d')
                    file3 = 3;
                else if (temp.substr(0,2)[1] == 'e' )
                    file3 = 4;
                else if (temp.substr(0,2)[1] == 'f')
                    file3 = 5;
                else if (temp.substr(0,2)[1] =='g')
                    file3 = 6;
                else if (temp.substr(0,2)[1] =='h')
                    file3 = 7;

                if((P[rnk2][file3][0]==c_enemy)&&(P[rnk2][file3][1] == 'Q'))
                {
                    check_times +=1;
                }


    }

for(set<string>::iterator it = rook_set.begin(); it!= rook_set.end(); it++)
    {
        temp = (*it);

         if (temp.substr(0,2)[0] == '1')
                     rnk2 = 0;
                else if (temp.substr(0,2)[0]== '2' )
                    rnk2 = 1;
                else if (temp.substr(0,2)[0] =='3')
                    rnk2 =  2;
                else if (temp.substr(0,2)[0] =='4')
                    rnk2 = 3;
                else if (temp.substr(0,2)[0] =='5' )
                    rnk2 = 4;
                else if (temp.substr(0,2)[0] =='6')
                    rnk2 = 5;
                else if (temp.substr(0,2)[0] =='7')
                    rnk2 = 6;
                else if (temp.substr(0,2)[0] == '8')
                    rnk2 = 7;

                if (temp.substr(0,2)[1] == 'a')
                    file3 = 0;
                else if (temp.substr(0,2)[1] == 'b' )
                    file3 = 1;
                else if (temp.substr(0,2)[1] == 'c')
                    file3 = 2;
                else if (temp.substr(0,2)[1] =='d')
                    file3 = 3;
                else if (temp.substr(0,2)[1] == 'e' )
                    file3 = 4;
                else if (temp.substr(0,2)[1] == 'f')
                    file3 = 5;
                else if (temp.substr(0,2)[1] =='g')
                    file3 = 6;
                else if (temp.substr(0,2)[1] =='h')
                    file3 = 7;

                if((P[rnk2][file3][0]==c_enemy)&&(P[rnk2][file3][1] == 'r'))
                {
                    check_times +=1;
                }


    }


for(set<string>::iterator it = knight_set.begin(); it!= knight_set.end(); it++)
    {
        temp = (*it);

         if (temp.substr(0,2)[0] == '1')
                     rnk2 = 0;
                else if (temp.substr(0,2)[0]== '2' )
                    rnk2 = 1;
                else if (temp.substr(0,2)[0] =='3')
                    rnk2 =  2;
                else if (temp.substr(0,2)[0] =='4')
                    rnk2 = 3;
                else if (temp.substr(0,2)[0] =='5' )
                    rnk2 = 4;
                else if (temp.substr(0,2)[0] =='6')
                    rnk2 = 5;
                else if (temp.substr(0,2)[0] =='7')
                    rnk2 = 6;
                else if (temp.substr(0,2)[0] == '8')
                    rnk2 = 7;

                if (temp.substr(0,2)[1] == 'a')
                    file3 = 0;
                else if (temp.substr(0,2)[1] == 'b' )
                    file3 = 1;
                else if (temp.substr(0,2)[1] == 'c')
                    file3 = 2;
                else if (temp.substr(0,2)[1] =='d')
                    file3 = 3;
                else if (temp.substr(0,2)[1] == 'e' )
                    file3 = 4;
                else if (temp.substr(0,2)[1] == 'f')
                    file3 = 5;
                else if (temp.substr(0,2)[1] =='g')
                    file3 = 6;
                else if (temp.substr(0,2)[1] =='h')
                    file3 = 7;

                if((P[rnk2][file3][0]==c_enemy)&&(P[rnk2][file3][1] == 'k'))
                {
                    check_times +=1;
                }


    }

    cout<<endl<<endl<<endl<<"check times is equal to   "<<endl<<check_times<<endl<<endl;
    return check_times;

}
// just need to make the moving two spaces up at begin work
set<string> pawn_capture_movs(rnk r, file f, position P, color c)
{
cout<<endl<<"pawn_capture";
string file2, rnk2, dst;
char r2,f2;
set<string> pawn_capture_set;

    if(c== 'W')
    { int i = r-'0';
      int j = f-'0';

        if((i+1) >= 0 && (i+1)<8 && (j<8) && (j>=0))
        {
             r2 = to_string(i+1)[0];
             f2 = to_string(j)[0];

            if (f2 == '0')
            file2 = "a";
        else if (f2 == '1' )
            file2 = "b";
        else if (f2 == '2')
            file2 = "c";
        else if (f2 == '3')
            file2 = "d";
        else if (f2 == '4' )
            file2 = "e";
        else if (f2 == '5')
            file2 = "f";
        else if (f2 =='6')
            file2 = "g";
        else if (f2 =='7')
            file2 = "h";

        if (r2 == '0')
            rnk2 = "1";
        else if (r2 == '1' )
            rnk2 = "2";
        else if (r2== '2')
            rnk2 = "3";
        else if (r2 =='3')
            rnk2 = "4";
        else if (r2 == '4' )
            rnk2 = "5";
        else if (r2 == '5')
            rnk2 = "6";
        else if (r2 =='6')
            rnk2 = "7";
        else if (r2 =='7')
            rnk2 = "8";

        dst = rnk2 +file2;
        if((P[i+1][j][0]=='e')){
        pawn_capture_set.insert(dst);
        }
        cout<<endl<<"the value of rnk is : "<<r<<" for color : "<< c;

        if(r == '1')
        { r2 = to_string(i+2)[0];
          f2 = to_string(j)[0];
            if (f2 == '0')
            file2 = "a";
        else if (f2 == '1' )
            file2 = "b";
        else if (f2 == '2')
            file2 = "c";
        else if (f2 == '3')
            file2 = "d";
        else if (f2 == '4' )
            file2 = "e";
        else if (f2 == '5')
            file2 = "f";
        else if (f2 =='6')
            file2 = "g";
        else if (f2 =='7')
            file2 = "h";

        if (r2 == '0')
            rnk2 = "1";
        else if (r2 == '1' )
            rnk2 = "2";
        else if (r2== '2')
            rnk2 = "3";
        else if (r2 =='3')
            rnk2 = "4";
        else if (r2 == '4' )
            rnk2 = "5";
        else if (r2 == '5')
            rnk2 = "6";
        else if (r2 =='6')
            rnk2 = "7";
        else if (r2 =='7')
            rnk2 = "8";
        cout<<endl<<"the value of r2 is : "<<r2<<" for color : "<< c;

        dst = rnk2 +file2;
        if((P[i+2][j][0] == 'e')&&(P[i][j][1]='p'))
        {
                    pawn_capture_set.insert(dst);
                    cout<<endl<<"the value of dst is : "<<dst<<" for color : "<< c;

        }

        }
    }

    }




    if(c== 'B')
    { int i = r-'0';
      int j = f-'0';
        if((i-1) >= 0 && (i-1)<8 && (j<8) && (j>=0))
                {
            char r2 = to_string(i-1)[0];
            char f2 = to_string(j)[0];

            if (f2 == '0')
            file2 = "a";
        else if (f2 == '1' )
            file2 = "b";
        else if (f2 == '2')
            file2 = "c";
        else if (f2 == '3')
            file2 = "d";
        else if (f2 == '4' )
            file2 = "e";
        else if (f2 == '5')
            file2 = "f";
        else if (f2 =='6')
            file2 = "g";
        else if (f2 =='7')
            file2 = "h";

        if (r2 == '0')
            rnk2 = "1";
        else if (r2 == '1' )
            rnk2 = "2";
        else if (r2== '2')
            rnk2 = "3";
        else if (r2 =='3')
            rnk2 = "4";
        else if (r2 == '4' )
            rnk2 = "5";
        else if (r2 == '5')
            rnk2 = "6";
        else if (r2 =='6')
            rnk2 = "7";
        else if (r2 =='7')
            rnk2 = "8";

        dst = rnk2 +file2;
         if((P[i-1][j][0]=='e')){
        pawn_capture_set.insert(dst);
        }
                }
        cout<<endl<<"the value of rnk is : "<<r<<" for color : "<< c;
        if(r == '6')
        { r2 = to_string(i-2)[0];
          f2 = to_string(j)[0];
            if (f2 == '0')
            file2 = "a";
        else if (f2 == '1' )
            file2 = "b";
        else if (f2 == '2')
            file2 = "c";
        else if (f2 == '3')
            file2 = "d";
        else if (f2 == '4' )
            file2 = "e";
        else if (f2 == '5')
            file2 = "f";
        else if (f2 =='6')
            file2 = "g";
        else if (f2 =='7')
            file2 = "h";

        if (r2 == '0')
            rnk2 = "1";
        else if (r2 == '1' )
            rnk2 = "2";
        else if (r2== '2')
            rnk2 = "3";
        else if (r2 =='3')
            rnk2 = "4";
        else if (r2 == '4' )
            rnk2 = "5";
        else if (r2 == '5')
            rnk2 = "6";
        else if (r2 =='6')
            rnk2 = "7";
        else if (r2 =='7')
            rnk2 = "8";

        dst = rnk2 +file2;
        if(((P[i-2][j][0]=='e'))&&(P[i][j][1]=='p')){
        pawn_capture_set.insert(dst);
        }


    }
    }

for(set<string>::iterator it = pawn_capture_set.begin(); it!= pawn_capture_set.end(); ++it)
{
    string s = *it;
    cout<<endl<<"this is in pawn_capture set"<<s<<endl;
}

return(pawn_capture_set);



}




set<string> pawn_attack_king_movs(rnk r,file f,position P,color c) //working, i think
{cout<<endl<<"pawn_attack_movs";
    set<string> pawn_attack_moves_set = {};
    string pawn_attack_move_dst;
    int i = (r-'0');
    int j = (f-'0');
    string rnk2, file2;

    int counter = 0;

    if(c=='W')
{
    for( i = (r-'0') ; i >= 0 && i<8 && j<8 && j>=0 && counter < 1; counter++  ){
                if ((i +1) == 0)
                    rnk2 = "1";
                else if ((i+1) == 1 )
                    rnk2 = "2";
                else if ((i+1)== 2)
                    rnk2 = "3";
                else if ((i +1) ==3)
                    rnk2 = "4";
                else if ((i +1) == 4 )
                    rnk2 = "5";
                else if ((i +1) == 5)
                    rnk2 = "6";
                else if ((i +1) ==6)
                    rnk2 = "7";
                else if ((i +1) ==7)
                    rnk2 = "8";

                    if ((j +1) == 0)
                     file2 = "a";
                else if ((j +1) == 1 )
                    file2 = "b";
                else if ((j +1) == 2)
                    file2 = "c";
                else if ((j +1) == 3)
                    file2 = "d";
                else if ((j +1) == 4 )
                    file2 = "e";
                else if ((j +1) == 5)
                    file2 = "f";
                else if ((j +1) ==6)
                    file2 = "g";
                else if ((j +1) ==7)
                    file2 = "h";


                  pawn_attack_move_dst = rnk2+file2;

                pawn_attack_moves_set.insert(pawn_attack_move_dst);

                }

            if ((i >= 0) && (i<8) && (j<8) && (j>=0))
                {


                if ((i +1) == 0)
                    rnk2 = "1";
                else if ((i +1) == 1 )
                    rnk2 = "2";
                else if ((i+1)== 2)
                    rnk2 = "3";
                else if ((i +1) ==3)
                    rnk2 = "4";
                else if ((i +1) == 4 )
                    rnk2 = "5";
                else if ((i +1) == 5)
                    rnk2 = "6";
                else if ((i +1) ==6)
                    rnk2 = "7";
                else if ((i +1) ==7)
                    rnk2 = "8";

                    if ((j -1) == 0)
                     file2 = "a";
                else if ((j -1) == 1 )
                    file2 = "b";
                else if ((j -1) == 2)
                    file2 = "c";
                else if ((j -1) == 3)
                    file2 = "d";
                else if ((j -1) == 4 )
                    file2 = "e";
                else if ((j -1) == 5)
                    file2 = "f";
                else if ((j -1) ==6)
                    file2 = "g";
                else if ((j -1) ==7)
                    file2 = "h";


                   pawn_attack_move_dst = rnk2+file2;

                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                }



}

 counter = 0;

    if(c=='B')
{
    for( i = (r-'0') ; i >= 0 && i<8 && j<8 && j>=0 && counter < 1; counter++  ){

                if ((i -1) == 0)
                    rnk2 = "1";
                else if ((i -1) == 1 )
                    rnk2 = "2";
                else if ((i-1)== 2)
                    rnk2 = "3";
                else if ((i -1) ==3)
                    rnk2 = "4";
                else if ((i -1) == 4 )
                    rnk2 = "5";
                else if ((i -1) == 5)
                    rnk2 = "6";
                else if ((i -1) ==6)
                    rnk2 = "7";
                else if ((i -1) ==7)
                    rnk2 = "8";

                    if ((j -1) == 0)
                     file2 = "a";
                else if ((j -1) == 1 )
                    file2 = "b";
                else if ((j -1) == 2)
                    file2 = "c";
                else if ((j -1) == 3)
                    file2 = "d";
                else if ((j -1) == 4 )
                    file2 = "e";
                else if ((j -1) == 5)
                    file2 = "f";
                else if ((j -1) ==6)
                    file2 = "g";
                else if ((j -1) ==7)
                    file2 = "h";


                  pawn_attack_move_dst = rnk2+file2;

                pawn_attack_moves_set.insert(pawn_attack_move_dst);

                }

            if ((i >= 0) && (i<8) && (j<8) && (j>=0))
                {


                if ((i -1) == 0)
                    rnk2 = "1";
                else if ((i -1) == 1 )
                    rnk2 = "2";
                else if ((i-1)== 2)
                    rnk2 = "3";
                else if ((i -1) ==3)
                    rnk2 = "4";
                else if ((i -1) == 4 )
                    rnk2 = "5";
                else if ((i -1) == 5)
                    rnk2 = "6";
                else if ((i -1) ==6)
                    rnk2 = "7";
                else if ((i -1) ==7)
                    rnk2 = "8";

                    if ((j +1) == 0)
                     file2 = "a";
                else if ((j +1) == 1 )
                    file2 = "b";
                else if ((j +1) == 2)
                    file2 = "c";
                else if ((j +1) == 3)
                    file2 = "d";
                else if ((j +1) == 4 )
                    file2 = "e";
                else if ((j +1) == 5)
                    file2 = "f";
                else if ((j +1) ==6)
                    file2 = "g";
                else if ((j +1) ==7)
                    file2 = "h";


                   pawn_attack_move_dst = rnk2+file2;

                pawn_attack_moves_set.insert(pawn_attack_move_dst);
                }



}


return pawn_attack_moves_set;
}



set<string> king_attack_movs_opposite(rnk r, file f, position P, color c)
{cout<<endl<<"king_attack_movs";


    set<string> king_attack_movs_set = {};
    string king_attack_move_dst;
    char r2 = r;
    char f2 = f;
    string file2;
    string file3;//for the src string
    string rnk2;
    string rnk2_n_file2;
    string str_rnk(1,r2);//converts a character into a string
    string str_file(1,f2);
    string rnk_file_src = str_rnk+str_file;

            // has to subtract zero char in order to work else we get ascii character values.
        int num = r - '0'; //converts "1" string to int of value 1, so i can modify it for moving the piece
        //int rnk1 = num - 1; // might need to change this if it's already been subtracted by 1
        int rnk1 = num;
        string str_rnk_int = to_string(rnk1);
        string file1 = rnk_file_src.substr(1,2);
         int rnk_int = num;
        //string str_rnk_int = to_string(rnk_int);



        //convert value of the file to a number string, see above to converting it into an int
         if (f == '0'){
            file1 = "0";
            file3 = "a";}
        else if (f == '1' )
            {file1 = "1";
             file3 = "b";}
        else if (f == '2')
            {file1 = "2";
             file3 = "c";}
        else if (f =='3')
            {file1 = "3";
            file3 = "d";}
        else if (f == '4' )
            {file1 = "4";
            file3 = "e";}
        else if (f == '5')
            {file1 = "5";
            file3 = "f";}
        else if (f == '6')
            {file1 = "6";
            file3 = "g";}
        else if (f == '7')
           {file1 = "7";
            file3 = "h";}


          if (r == '0')
                    rnk2 = "1";
                else if (r == '1' )
                    rnk2 = "2";
                else if (r== '2')
                    rnk2 = "3";
                else if (r =='3')
                    rnk2 = "4";
                else if (r == '4' )
                    rnk2 = "5";
                else if (r == '5')
                    rnk2 = "6";
                else if (r =='6')
                    rnk2 = "7";
                else if (r =='7')
                    rnk2 = "8";

        int file_int = stoi(file1);

        string string_file;
        string string_rnk;

        string rnk_n_file;


        int i = rnk1;
        int j = file_int;
        // issue is the for loop statement and how r + '1' doesn't work, it has to be char value number - '0' otherwise we get ascii
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0 &&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);

            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                    king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j++;

            }

            i = rnk1;
            j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";

                    king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j--;

            }

            i = rnk1;
            j = file_int;

            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            i++;
            }
            i = rnk1;
            j = file_int;
            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            i--;
            }
            i = rnk1;
            j = file_int;

            for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king southeast
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }
            j++;
            i++;
            }

        i = rnk1;
        j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) // movment of king to right/up (northeast
            {
            string_rnk = to_string(i);
            string_file= to_string(j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                      if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }


            }
            j++ ;
            i--;
            }
        i = rnk1;
        j = file_int;

        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&&king_lim <= 1; king_lim++ ) //movs southwest
            {
            string_rnk = to_string( i);
            string_file= to_string( j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }



            }

            j--;
            i++;
            }

        i = rnk1;
        j = file_int;
        for( int king_lim = 0; i >= 0 && i<8 && j<8 && j>=0&& king_lim <= 1; king_lim++ ) //movs northwest
            {
            string_rnk = to_string(i);
            string_file= to_string(j);
            rnk_n_file = (string_rnk+string_file);
            if(rnk_n_file != (to_string(r))+f)
            {
                if (i == 0)
                    rnk2 = "1";
                else if (i == 1 )
                    rnk2 = "2";
                else if (i== 2)
                    rnk2 = "3";
                else if (i ==3)
                    rnk2 = "4";
                else if (i == 4 )
                    rnk2 = "5";
                else if (i == 5)
                    rnk2 = "6";
                else if (i ==6)
                    rnk2 = "7";
                else if (i ==7)
                    rnk2 = "8";

                    if (j == 0)
                     file2 = "a";
                else if (j == 1 )
                    file2 = "b";
                else if (j == 2)
                    file2 = "c";
                else if (j == 3)
                    file2 = "d";
                else if (j == 4 )
                    file2 = "e";
                else if (j == 5)
                    file2 = "f";
                else if (j ==6)
                    file2 = "g";
                else if (j ==7)
                    file2 = "h";
                     king_attack_move_dst = rnk2+file2;
                    if (P[i][j][0]=='e')
                    {

                    king_attack_movs_set.insert(king_attack_move_dst);

                    }
            }

            j--;
            i--;
            }
//THIS IS FOR CASTLING THE KING FOR BLACK  (WHICH IS ON BOTTOM)
//
/*
        int castle_rnk = r-'0';
        int castle_file = f-'0';

        if(c == 'B')
        {cout<<P[castle_rnk][castle_file].substr(0,2);
            if(P[castle_rnk][castle_file].substr(0,2) == "BK")
            {
                if((P[castle_rnk][castle_file-1][0]=='e')&&(P[castle_rnk][castle_file-2][0]=='e')&&(P[castle_rnk][castle_file-3][1]== ('r')))
                {
                    cout<<"can castle king side";
                }
                if((P[castle_rnk][castle_file+1][0]=='e')&&(P[castle_rnk][castle_file+2][0]=='e')&&(P[castle_rnk][castle_file+3][0]=='e')&&(P[castle_rnk][castle_file+4][1]== ('r')))
                {
                    cout<<"can castle queen side";
                }
            }

        }
         if(c == 'W')
        {
            if(P[castle_rnk][castle_file].substr(0,2) == "WK")
            {
                if((P[castle_rnk][castle_file+1][0]=='e')&&(P[castle_rnk][castle_file+2][0]=='e')&&(P[castle_rnk][castle_file+3][1]== 'r'))
                {
                    cout<<"can castle king side";
                }
                if((P[castle_rnk][castle_file-1][0]=='e')&&(P[castle_rnk][castle_file-2][0]=='e')&&(P[castle_rnk][castle_file-3][0]=='e')&&(P[castle_rnk][castle_file-4][1]== ('r')))
                {
                    cout<<"can castle queen side";
                }
            }

        }  */


        for(set<string>::iterator it = king_attack_movs_set.begin(); it!= king_attack_movs_set.end(); ++it)
        {
            string s = *it;
            cout<<endl<<"value of king opp entered is "<< s;
        }
            cout<<endl<<"went through king_opp"<<endl;
            return king_attack_movs_set;
}

