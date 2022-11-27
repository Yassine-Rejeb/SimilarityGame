//Including dependencies
	#include<SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
	#include <iostream>
	#include <string>
	#include <cstring>
	#include <time.h>
	#include <fstream>
	#include <vector>

//Using std functions to not use 
//	the whole namespace (since this
//  will cause an issue where the 
//  rend functions is definied in both
//  namespaces std and sdl)
	//using namespace std;
	using std::cout ;
	using std::cin ;
	using std::endl ;
	using std::string ;

//Defining constants
	const int width  =640;
	const int height =480;


/************************ GRAPHICAL INTERFACE OF THE GAME *************************/
		//Code relevant to the mouse events 
		#include "mouse.cpp"

		//Defining functions
			//Initializing SDL
			bool init();

			//Loading Media
			bool Loadmedia();

			//Closing SDL
			void close();

			//LOADING AN IMAGE IN A TEXTURE
			SDL_Texture* LoadTexture(string);


		//Defining GLOBAL VARIABLES
			//SDL Window
			SDL_Window* gWin=NULL;

			//SDL SURFACE
			SDL_Surface* SURF=NULL,*S[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

			//SDL Renderer
			SDL_Renderer* rend=NULL;

			//SDL Texture
			SDL_Texture* text[26]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
				*textQ,
				*T[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
				*text_sc[9]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},*p1=NULL,*p2=NULL,*p1a=NULL,*p2a=NULL,*twin1=NULL,*twin2=NULL,
				*win=NULL,*player1=NULL,*player2=NULL,*sc1=NULL,*sc2=NULL;


		//Initialize SDL2, and creating the window and the renderer
		bool init(){
			bool success = false;
			if (SDL_Init(SDL_INIT_EVERYTHING)<0)
			{
				cout << "PROBLEM INITIALIZING EVERYTHING" << SDL_GetError() <<endl;
			}else{
				//SET TEXTURE RENDERING TO LINEAR
				if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY , "1")){
					cout << "POBLEM SETTING TEXTURE RENDERING TO LINEAR" << SDL_GetError() << endl;
				}else{
					gWin = SDL_CreateWindow("C Project: Remember ME!",SDL_WINDOWPOS_UNDEFINED ,SDL_WINDOWPOS_UNDEFINED ,width ,height ,SDL_WINDOW_SHOWN);
					if (gWin==NULL){
						cout << "PROBLEM CREATING WINDOW" << SDL_GetError() << endl;
					}
					//CREATE RENDERER
					else{
						SURF=SDL_GetWindowSurface(gWin);
						rend = SDL_CreateRenderer( gWin, -1, SDL_RENDERER_ACCELERATED );
						
						//INITIALIZE RENDERER COLOR
						SDL_SetRenderDrawColor(rend , 0xFF , 0xFF , 0xFF , 0xFF);
						
						//INITIALIZE PNG LOADING
						int imgFlags = IMG_INIT_PNG;
						if( !( IMG_Init( imgFlags ) & imgFlags ) )
						{	cout << "PROBLEM INITALIZING PNG LOADING  " << IMG_GetError() << endl	;}
						else success=true;
					}
				}
			}
			return success;}

		//Load the images needed in the whole process of the game
		bool Loadmedia(){
			
			//Set buttons in corners
				gButtons[ 0 ].setPosition( 0, 0 );
				gButtons[ 1 ].setPosition( width - 4*BUTTON_WIDTH, 0 );
				gButtons[ 2 ].setPosition( width - 3*BUTTON_WIDTH, 0 );
				gButtons[ 3 ].setPosition( width - 2*BUTTON_WIDTH, 0 );
				gButtons[ 4 ].setPosition( 0 , height/4 );
				gButtons[ 5 ].setPosition( width - 4*BUTTON_WIDTH , height/4 );
				gButtons[ 6 ].setPosition( width - 3*BUTTON_WIDTH , height/4 );
				gButtons[ 7 ].setPosition( width - 2*BUTTON_WIDTH , height/4 );
				gButtons[ 8 ].setPosition( 0 , 2*height/4 );
				gButtons[ 9 ].setPosition( width - 4*BUTTON_WIDTH , 2*height/4 );
				gButtons[ 10 ].setPosition( width - 3*BUTTON_WIDTH , 2*height/4 );
				gButtons[ 11 ].setPosition( width - 2*BUTTON_WIDTH , 2*height/4 );
				gButtons[ 12 ].setPosition( 0 , 3*height/4 );
				gButtons[ 13 ].setPosition( width - 4*BUTTON_WIDTH , 3*height/4 );
				gButtons[ 14 ].setPosition( width - 3*BUTTON_WIDTH , 3*height/4 );
				gButtons[ 15 ].setPosition( width - 2*BUTTON_WIDTH , 3*height/4 );

			//INITIALIZING MAIN FLAG
			bool success =true;

			//A VIEWPORT
				text[0] = LoadTexture("alpha/A.png");
				if ( text[0] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE 1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//B VIEWPORT
				text[1] = LoadTexture("alpha/B.png");
				if ( text[1] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//C VIEWPORT
				text[2] = LoadTexture("alpha/C.png");
				if ( text[2] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//D VIEWPORT
				text[3] = LoadTexture("alpha/D.png");
				if ( text[3] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//E VIEWPORT
				text[4] = LoadTexture("alpha/E.png");
				if ( text[4] == NULL ){
					cout 
					<< "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//F VIEWPORT
				text[5] = LoadTexture("alpha/F.png");
				if ( text[5] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE 1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//G VIEWPORT
				text[6] = LoadTexture("alpha/G.png");
				if ( text[6] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//H VIEWPORT
				text[7] = LoadTexture("alpha/H.png");
				if ( text[7] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//I VIEWPORT
				text[8] = LoadTexture("alpha/I.png");
				if ( text[8] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//J VIEWPORT
				text[9] = LoadTexture("alpha/J.png");
				if ( text[9] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}
			
			//K VIEWPORT
				text[10] = LoadTexture("alpha/K.png");
				if ( text[10] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE 1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//L VIEWPORT
				text[11] = LoadTexture("alpha/L.png");
				if ( text[11] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//M VIEWPORT
				text[12] = LoadTexture("alpha/M.png");
				if ( text[12] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//N VIEWPORT
				text[13] = LoadTexture("alpha/N.png");
				if ( text[13] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//O VIEWPORT
				text[14] = LoadTexture("alpha/O.png");
				if ( text[14] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}
			
			//P VIEWPORT
				text[15] = LoadTexture("alpha/P.png");
				if ( text[15] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE 1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//Q VIEWPORT
				text[16] = LoadTexture("alpha/Q.png");
				if ( text[16] == NULL  ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//R VIEWPORT
				text[17] = LoadTexture("alpha/R.png");
				if ( text[17] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//S VIEWPORT
				text[18] = LoadTexture("alpha/S.png");
				if ( text[18] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//T VIEWPORT
				text[19] = LoadTexture("alpha/T.png");
				if ( text[19] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}
			
			//U VIEWPORT
				text[20] = LoadTexture("alpha/U.png");
				if ( text[20] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE 1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//V VIEWPORT
				text[21] = LoadTexture("alpha/V.png");
				if ( text[21] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//W VIEWPORT
				text[22] = LoadTexture("alpha/W.png");
				if ( text[22] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//X VIEWPORT
				text[23] = LoadTexture("alpha/X.png");
				if ( text[23] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//Y VIEWPORT
				text[24] = LoadTexture("alpha/Y.png");
				if ( text[24] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//Z VIEWPORT
				text[25] = LoadTexture("alpha/Z.png");
				if ( text[25] == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE " << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//UNKNOWN VIEWPORT
				textQ = LoadTexture("alpha/quest.png");
				if ( textQ == NULL ){
					cout << "PROBLEM LOADING TEXTURE/SURFACE Q" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//0-9 score VIEWPORT
			
			string scoresPaths[]={"alpha/sc0.png","alpha/sc1.png","alpha/sc2.png","alpha/sc3.png","alpha/sc4.png","alpha/sc5.png","alpha/sc6.png","alpha/sc7.png","alpha/sc8.png"};
			for (int i = 0; i < 9; ++i)
			{
				text_sc[i] = LoadTexture(scoresPaths[i]);
				if ( textQ == NULL){
					cout << "PROBLEM LOADING TEXTURE " << scoresPaths[i] << endl << SDL_GetError() << endl;
					success = false;
					return success;
				}		
			}

			//p1 VIEWPORT
				p1 = LoadTexture("alpha/p1.png");
				if ( p1 == NULL ){
					cout << "PROBLEM LOADING TEXTURE p1" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//p1a VIEWPORT
				p1a = LoadTexture("alpha/p1a.png");
				if ( p1a == NULL ){
					cout << "PROBLEM LOADING TEXTURE p1a" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//p2 VIEWPORT
				p2 = LoadTexture("alpha/p2.png");
				if ( p2 == NULL ){
					cout << "PROBLEM LOADING TEXTURE p2" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//p2a VIEWPORT
				p2a = LoadTexture("alpha/p2a.png");
				if ( p2a == NULL ){
					cout << "PROBLEM LOADING TEXTURE p2a" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			//win VIEWPORT
				win = LoadTexture("alpha/pwin.png");
				if ( win == NULL ){
					cout << "PROBLEM LOADING TEXTURE win" << SDL_GetError() << endl;
					success = false;
					return success;
				}

			return success;}

		//Release memory and close SDL2 Objects
		void close(){
			//FREEING SURFACES
			for (int i = 0; i < 26; ++i)
			{
				SDL_FreeSurface(S[i]);
			}

			//DESTROYING THE IMAGE IN THE TEXTURE 
			SDL_DestroyTexture(text[0]);
			text[0]=NULL;

			SDL_DestroyTexture(text[1]);
			text[1]=NULL;

			SDL_DestroyTexture(text[2]);
			text[2]=NULL;

			SDL_DestroyTexture(text[3]);
			text[3]=NULL;

			SDL_DestroyTexture(text[4]);
			text[4]=NULL;

			SDL_DestroyTexture(text[5]);
			text[5]=NULL;

			SDL_DestroyTexture(text[6]);
			text[6]=NULL;

			SDL_DestroyTexture(text[7]);
			text[7]=NULL;

			SDL_DestroyTexture(text[8]);
			text[8]=NULL;

			SDL_DestroyTexture(text[9]);
			text[9]=NULL;
			
			SDL_DestroyTexture(text[10]);
			text[10]=NULL;

			SDL_DestroyTexture(text[11]);
			text[11]=NULL;

			SDL_DestroyTexture(text[12]);
			text[12]=NULL;

			SDL_DestroyTexture(text[13]);
			text[13]=NULL;

			SDL_DestroyTexture(text[14]);
			text[14]=NULL;

			SDL_DestroyTexture(text[15]);
			text[15]=NULL;

			SDL_DestroyTexture(text[16]);
			text[16]=NULL;

			SDL_DestroyTexture(text[17]);
			text[17]=NULL;

			SDL_DestroyTexture(text[18]);
			text[18]=NULL;

			SDL_DestroyTexture(text[19]);
			text[19]=NULL;

			SDL_DestroyTexture(text[20]);
			text[20]=NULL;

			SDL_DestroyTexture(text[21]);
			text[21]=NULL;

			SDL_DestroyTexture(text[22]);
			text[22]=NULL;

			SDL_DestroyTexture(text[23]);
			text[23]=NULL;

			SDL_DestroyTexture(text[24]);
			text[24]=NULL;

			SDL_DestroyTexture(text[25]);
			text[25]=NULL;

			SDL_DestroyRenderer(rend);
			rend=NULL;

			SDL_DestroyWindow(gWin);
			gWin = NULL;

			IMG_Quit();
			SDL_Quit();}

		SDL_Texture* LoadTexture(const string path){
			//RETURNING THIS TEXTURE
			SDL_Texture* texture;
			//LOADING IMAGE
			SDL_Surface* surf = IMG_Load(path.c_str());
			if (surf == NULL){
				cout << "PROBLEM LOADING IMAGE " << SDL_GetError();
			}else//CREATE TEXTURE FROM SURFACE PIXELS
			{
				texture = SDL_CreateTextureFromSurface( rend , surf );
				if(texture == NULL){
					cout << "PROBLEM CREATING TEXTURE FROM SURFACE " << SDL_GetError() << endl;
				}
			}  
			//SDL_FreeSurface(surf);
			return(texture);}


/************************ 		  CORE OF THE GAME 		  *************************/
	//Initializing the matrix holding the letters
	void generateT2inFile(int t0[8],int pt[16])
	{
		FILE *fic=NULL;
		fic=fopen("db.txt","rw+");
		int i,j,k,l,repet,alea,indalea;
		for(i=0;i<=8;i++)	// boucles de remplisage
	   {
			repet=0;				//Initializing the repetition number to 0
	    	alea=65+rand() % 26;	//Getting the ord of random uppercase letters
			for(k=0;k<=8;k++)
			{
		 		if(t0[k]==alea)		//If the character exists in the table, increment the number of repetition
		 			repet++;
			}
			if(repet<1)
			{
		  	t0[i]=alea;				//Only appending character that did not exist in the table
			}
		  	else
			{
		  		i--;				//If the character exists already then get another random character by repeating the iteration
			}
		}
		
		i=0;
		while(i<16)
		{
			repet=0;
			alea=rand()%8;
			for(j=0;j<16;j++)
			{
				if(pt[j]==t0[alea])
				{
					repet++;
				}
			}
			if(repet<2)
			{
				pt[i]=t0[alea];
				fputc(pt[i],fic);
				i++;
			}
		}
		fclose(fic);}

	void getT2fromFile(char t[5][5])
	{
		int i,j;
		FILE *fic=NULL;
		fic=fopen("db.txt","r+");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				fscanf(fic,"%c",&t[i][j]);
			}
		}
		fclose(fic);}

/************************ Functions related to interconnecting
 *** 			the CORE and the Grapgical Interface *****************************/
	//Global Variables related to the core
		//Variable to limit showing images
		int twoOfaKind = 0;

		//Record the indexes of choices
		int choice1_x=0,choice2_x=0,choice1_y=0,choice2_y=0,curr_x=-1,curr_y=-1;

		//Record the solved couples
		std::vector<int> solved_x;
		std::vector<int> solved_y;

		//Checks to limit processing to once inside a while loop
		int check1=1,check2=1;

		//Clicked viewport (Letter) indices
		int z/*usually x but let's change*/,y;

		//Scores of players
		int scp1=0,scp2=0;

	void showLetters(char t,int  x);

	bool isItSolved(int a,int b){
		if (solved_x.empty())
		{
			return false;
		}
		for (int i = 0; i < solved_x.size(); i++)
		{
			if (solved_x[i]==a && solved_y[i]==b)
			{
				return true;
			}else
				continue;
		return false;
		}
	}

	void hideAll(){
		showLetters('5',0);
		showLetters('5',1);
		showLetters('5',2);
		showLetters('5',3);
		showLetters('5',4);
		showLetters('5',5);
		showLetters('5',6);
		showLetters('5',7);
		showLetters('5',8);
		showLetters('5',9);
		showLetters('5',10);
		showLetters('5',11);
		showLetters('5',12);
		showLetters('5',13);
		showLetters('5',14);
		showLetters('5',15);
	}

	void hideLetters(){
		for(int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				//cout << "i: " << i << "  j: " << j << " is it solved : " << isItSolved(i,j) << endl;
				if(!isItSolved(i,j)){
					if (i==0&&j==0)
					{
						showLetters('5',0);
					}if (i==0&&j==1)
					{
						showLetters('5',1);
					} if (i==0&&j==2)
					{
						showLetters('5',2);
					} if (i==0&&j==3)
					{
						showLetters('5',3);
					} if (i==1&&j==0)
					{
						showLetters('5',4);
					} if (i==1&&j==1)
					{
						showLetters('5',5);
					} if (i==1&&j==2)
					{
						showLetters('5',6);
					} if (i==1&&j==3)
					{
						showLetters('5',7);
					} if (i==2&&j==0)
					{
						showLetters('5',8);
					} if (i==2&&j==1)
					{
						showLetters('5',9);
					} if (i==2&&j==2)
					{
						showLetters('5',10);
					} if (i==2&&j==3)
					{
						showLetters('5',11);
					} if (i==3&&j==0)
					{
						showLetters('5',12);
					} if (i==3&&j==1)
					{
						showLetters('5',13);
					} if (i==3&&j==2)
					{
						showLetters('5',14);
					}if (i==3&&j==3)
					{
						showLetters('5',15);
					}
				}
			}
		}
	}

	void showLetters(char t,int  x){
		//Show letters
		switch(t){
			case 'A':T[x]=text[0];break;
			case 'B':T[x]=text[1];break;
			case 'C':T[x]=text[2];break;
			case 'D':T[x]=text[3];break;
			case 'E':T[x]=text[4];break;
			case 'F':T[x]=text[5];break;
			case 'G':T[x]=text[6];break;
			case 'H':T[x]=text[7];break;
			case 'I':T[x]=text[8];break;
			case 'J':T[x]=text[9];break;
			case 'K':T[x]=text[10];break;
			case 'L':T[x]=text[11];break;
			case 'M':T[x]=text[12];break;
			case 'N':T[x]=text[13];break;
			case 'O':T[x]=text[14];break;
			case 'P':T[x]=text[15];break;
			case 'Q':T[x]=text[16];break;
			case 'R':T[x]=text[17];break;
			case 'S':T[x]=text[18];break;
			case 'T':T[x]=text[19];break;
			case 'U':T[x]=text[20];break;
			case 'V':T[x]=text[21];break;
			case 'W':T[x]=text[22];break;
			case 'X':T[x]=text[23];break;
			case 'Y':T[x]=text[24];break;
			case 'Z':T[x]=text[25];break;
			default: T[x]=textQ;break;
		}
	}

	void showPlayers(int alternate){
		if (alternate%2==0)
		{
			//cout << "active is player1" << endl;
			player1=p1a;
			player2=p2;
		}else{
			//cout << "active is player2" << endl;
			player1=p1;
			player2=p2a;
		}
	}
	void showScores(){
		switch(scp1){
			case 0:sc1=text_sc[0];break;
			case 1:sc1=text_sc[1];break;
			case 2:sc1=text_sc[2];break;
			case 3:sc1=text_sc[3];break;
			case 4:sc1=text_sc[4];break;
			case 5:sc1=text_sc[5];break;
			case 6:sc1=text_sc[6];break;
			case 7:sc1=text_sc[7];break;
			case 8:sc1=text_sc[8];break;
		}
		switch(scp2){
			case 0:sc2=text_sc[0];break;
			case 1:sc2=text_sc[1];break;
			case 2:sc2=text_sc[2];break;
			case 3:sc2=text_sc[3];break;
			case 4:sc2=text_sc[4];break;
			case 5:sc2=text_sc[5];break;
			case 6:sc2=text_sc[6];break;
			case 7:sc2=text_sc[7];break;
			case 8:sc2=text_sc[8];break;
		}
	}

int main(int argc, char const *argv[])
{
	/**************************************************
	**************  Declaring Variables  **************
	**************************************************/
		int t0[8],t1[16];
		char t2[5][5];

		//recording the two choices
		char choice1='0',choice2='0';

		//Fill the window once
		int fillOnce=0;

		//Corresponding texture table index to letter index
		char * corr[16]={"00","01","02","03","10","11","12",
				"13","20","21","22","23","30","31","32","33"};

		//Alternator between players
		int alternate=0;

	//Initialize the shareLetter file on illogical numbers
		std::fstream my_file;
		my_file.open("shareLetter", std::ios::out);
		my_file << -1 << ' ' << -1;
		my_file.close();

	//Randomizing the buffer to make sure the function rand()
	//	does not become predicatable
	srand(time(NULL));  
	
	//Initializing the letters' table to random values
	generateT2inFile(t0,t1);
	getT2fromFile(t2);

	if (!init())
	{
		cout << "FAILING TO INITIALIZE " << endl;
	}else if (!Loadmedia())
	{
		cout << "FAILING TO LOAD MEDIA " << endl;
	}else{

	//main loop
	bool quit=false;
	//event handler
	SDL_Event e;

	while(!quit){
		while(SDL_PollEvent(&e)!=0){
			if (e.type==SDL_QUIT)
			{
				quit = true;
			}
			//Handle mouse events
				for( int i = 0; i < TOTAL_BUTTONS; ++i )
				{
					gButtons[ i ].setletters(t2);
					gButtons[ i ].handleEvent( &e );
				}
		}

		//Fill the window with all the letters only once
		if (fillOnce==0)
			{
				int x=0;
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						showLetters(t2[i][j],x);
						x++;
					}
				}
				//Show the players and the scores
				showScores();
				showPlayers(alternate);
				fillOnce=1;
			}
		
		//Wait 5 seconds then hide letters
		if (SDL_GetTicks()>=5000 && check1){
			hideAll();
			check1=0;
		}

		//Reading the file shareLetter in search for the clicked letter
		//Reading as string
		std::fstream my_file;
		std::string ch1,ch2;
		my_file.open("shareLetter", std::ios::in);
		my_file >> ch1 >> ch2 ;
		my_file.close();

		//Reading as integer
		int i,j;
		my_file.open("shareLetter", std::ios::in);
		my_file >> i >> j ;
		z=i;y=j;
		my_file.close();

		//If the coordonates of the clicked viewport are logical(not -1 -1)
		if (i>=0&&j>=0)
		{
			//Concat the read strings(coordonates)
			std::string ch=ch1+ch2;
			
			//TwoOfAKind does not increment unless the clicked 
			// viewport is different than the last clicked one
			if (curr_x!=z||curr_y!=y){
				curr_x=z;
				curr_y=y;
				twoOfaKind++;
			for (int i = 0; i < 16; ++i)
			{
				if (ch==corr[i])
				{
					showLetters(t2[z][y],i);
				}
			}

			if (twoOfaKind==0)
			{
				choice1='0';
				choice2='0';
			}
			if (twoOfaKind==1)
				{
					choice1=t2[z][y];
					choice2='0';
					choice1_x=z;
					choice1_y=y;
				}
			if (twoOfaKind==2)
			{
				choice2=t2[z][y];
				choice2_x=z;
				choice2_y=y;
				if ((choice1==choice2))
				{
					if (alternate%2==0)
					{
						scp1++;
					}else
						scp2++;
					solved_x.push_back(choice1_x);
					solved_y.push_back(choice1_y);
					solved_x.push_back(choice2_x);
					solved_y.push_back(choice2_y);
					twoOfaKind=0;
				}
				else
				{
					twoOfaKind=0;
					hideLetters();
				}
				
				//curr_x=-1;curr_y=-1;
				alternate++;
				
				//Show the players and the scores
					showScores();
					showPlayers(alternate);

				//Show winner when finished
					if (scp1+scp2==8)
					{
						if (scp1>scp2)
						{
							twin1=win;
						}else if (scp1<scp2)
							{twin2=win;}
						else{
							twin1=win;
							twin2=win;
						}
					}
			
			}
		}
	}

		SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( rend );

		//Size viewports & renderCopy the images inside them
			SDL_Rect port1;
			//FIRST VIEWPORT
			port1.x=0;
			port1.y=0;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[0] , NULL , NULL);

			//SECOND VIEWPORT
			port1.x=width/5;
			port1.y=0;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[1] , NULL , NULL);

			//THIRD VIEWPORT
			port1.x=2*width/5;
			port1.y=0;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[2] , NULL , NULL);

			//4th VIEWPORT
			port1.x=3*width/5;
			port1.y=0;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[3] , NULL , NULL);

			//5th VIEWPORT
			port1.x=0;
			port1.y=height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[4] , NULL , NULL);

			//6th VIEWPORT
			port1.x=width/5;
			port1.y=height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[5] , NULL , NULL);

			//7th VIEWPORT
			port1.x=2*width/5;
			port1.y=height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[6] , NULL , NULL);

			//8th VIEWPORT
			port1.x=3*width/5;
			port1.y=height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[7] , NULL , NULL);

			//9th VIEWPORT
			port1.x=0;
			port1.y=2*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[8] , NULL , NULL);

			//10th VIEWPORT
			port1.x=width/5;
			port1.y=2*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[9] , NULL , NULL);

			//11th VIEWPORT
			port1.x=2*width/5;
			port1.y=2*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[10] , NULL , NULL);

			//12th VIEWPORT
			port1.x=3*width/5;
			port1.y=2*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[11] , NULL , NULL);

			//13th VIEWPORT
			port1.x=0;
			port1.y=3*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[12] , NULL , NULL);

			//14th VIEWPORT
			port1.x=width/5;
			port1.y=3*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[13] , NULL , NULL);

			//15th VIEWPORT
			port1.x=2*width/5;
			port1.y=3*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[14] , NULL , NULL);

			//16th VIEWPORT
			port1.x=3*width/5;
			port1.y=3*height/4;
			port1.w=width/5;
			port1.h=height/4;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , T[15] , NULL , NULL);

			//player1 VIEWPORT
			port1.x=526;
			port1.y=96;
			port1.w=100;
			port1.h=40;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , player1 , NULL , NULL);

			//score1 VIEWPORT
			port1.x=571;
			port1.y=182;
			port1.w=10;
			port1.h=20;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , sc1 , NULL , NULL);

			//player2 VIEWPORT
			port1.x=526;
			port1.y=288;;
			port1.w=100;
			port1.h=40;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , player2 , NULL , NULL);

			//score2 VIEWPORT
			port1.x=571;
			port1.y=374;
			port1.w=10;
			port1.h=20;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , sc2 , NULL , NULL);

			//win1 VIEWPORT
			port1.x=526;
			port1.y=182;
			port1.w=100;
			port1.h=30;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , twin1 , NULL , NULL);

			//win2 VIEWPORT
			port1.x=526;
			port1.y=374;
			port1.w=100;
			port1.h=30;
			SDL_RenderSetViewport(rend,&port1);
			SDL_RenderCopy(rend , twin2 , NULL , NULL);

		SDL_UpdateWindowSurface(gWin);
		SDL_RenderPresent(rend);
	}

	}
	close();

	return 0;
}