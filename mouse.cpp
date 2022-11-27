#include <fstream>

//Button constants
const int BUTTON_WIDTH = 128;
const int BUTTON_HEIGHT = 120;
const int TOTAL_BUTTONS = 16;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

//The mouse button
class LButton
{
	public:
		//Initializes internal variables
		LButton();

		//Sets top left position
		void setPosition( int x, int y );

		//Handles mouse event
		void handleEvent( SDL_Event* e );

		//get The chosen Letters
		void setletters(char t2[5][5]);

		char getletters(int i, int j);
	
	private:
		//Top left position
		SDL_Point mPosition;

		//Currently used global sprite
		LButtonSprite mCurrentSprite;

		//Chosen letters
		char t2[5][5];
};

//Buttons objects
	LButton gButtons[ TOTAL_BUTTONS ]; 

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//Mouse button sprites
	SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];

LButton::LButton()
{
	mPosition.x = 0;
	mPosition.y = 0;

	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition( int x, int y )
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::setletters(char t[5][5]){
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			this->t2[i][j]=t[i][j];
		}
	}
}

char LButton::getletters(int i, int j){
	return (this->t2)[i][j];
}


void LButton::handleEvent( SDL_Event* e )
{
	//If mouse event happened
	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e->type )
			{
				case SDL_MOUSEMOTION:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
					break;
			
				case SDL_MOUSEBUTTONDOWN:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					if (x<128 && y<120){
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 0 << ' ' << 0 << endl;
						f.close(); 
					}
					//return this->t2[0][0];
					else if (x<256 && y<120)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 0 << ' '<< 1 << endl;
						f.close(); 
					}
					else if (x<384 && y<120)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 0<< ' '<< 2 << endl;
						f.close(); 
					}
					else if (x<480 && y<120)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 0<< ' ' << 3 << endl;
						f.close(); 
					}
					else if (x<128 && y<240)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 1<< ' ' <<0 << endl;
						f.close(); 
					}
					else if (x<256 && y<240)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 1<< ' ' << 1 << endl;
						f.close(); 
					}
					else if (x<384 && y<240)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 1<< ' ' <<2 << endl;
						f.close(); 
					}
					else if (x<480 && y<240)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 1<< ' ' << 3 << endl;
						f.close(); 
					}
					else if (x<128 && y<384)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 2<< ' ' << 0 << endl;
						f.close(); 
					}
					else if (x<256 && y<384)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 2<< ' ' <<1 << endl;
						f.close(); 
					}
					else if (x<384 && y<384)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 2<< ' ' <<2 << endl;
						f.close(); 
					}
					else if (x<480 && y<384)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 2 << ' ' <<3 << endl;
						f.close(); 
					}
					else if (x<128 && y<512)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 3 << ' ' << 0 << endl;
						f.close(); 
					}
					else if (x<256 && y<512)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 3<< ' ' << 1 << endl;
						f.close(); 
					}
					else if (x<384 && y<512)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 3<< ' ' << 2 << endl;
						f.close(); 
					}
					else if (x<480 && y<512)
					{
						std::fstream f;
						f.open("shareLetter", std::ios::out);
						f << 3 << ' ' << 3 << endl;
						f.close(); 
					}
					break;
				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
}
