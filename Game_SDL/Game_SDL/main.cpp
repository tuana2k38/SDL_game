#include "Common_Function.h"
#include "MainObject.h"
#include "ThreatsObject.h"

SDL_Surface* g_human = NULL;


bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
		return false;

	return true;
}

int main(int arc, char* argv[])
{
	int bk_speed_x = 0;
	bool bk_is_move = true;
	bool is_quit = false;
	if (Init() == false)
		return 0;

	/*Load Background Image*/
	g_bkground = SDLCommonFunc::LoadImage("bg4800.png");
	if (g_bkground == NULL)
	{
		return 0;
	}


	/* process Main object */
	MainObject human_object;
	human_object.SetRect(100, 200);
	bool ret = human_object.LoadImg("plane_fly.png");
	if (!ret)
	{
		return 0;
	}

	/* Process Threats object */
	ThreatsObject* p_threats = new ThreatsObject[NUM_THREATS];
	for (int i = 0; i < NUM_THREATS; i++)
	{
		ThreatsObject* p_threat = (p_threats + i);
		ret = p_threat->LoadImg("af1.png");
		if (!ret)
		{
			return 0;
		}
		int rand_y = rand() % 400;
		if (rand_y > SCREEN_HEIGHT - 200)
		{
			rand_y = SCREEN_HEIGHT * 0.3;
		}
		else if (rand_y < SCREEN_HEIGHT)
		{
			rand_y = SCREEN_HEIGHT;
		}
		p_threat->SetRect(WIDHT_THREAT + i*400, rand_y);
		p_threat->set_x_val(3);

		AmoObject* p_amo = new AmoObject();
		p_threat->InitAmo(p_amo);
	}
	
	
	while (!is_quit)
	{

		while (SDL_PollEvent(&g_even))
		{
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_even);
		}

		/*Handle background moving*/
		if (bk_is_move)
		{
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, bk_speed_x, 0);
			bk_speed_x -= 2;
			if (bk_speed_x < -(3 * SCREEN_WIDTH))
			{
				bk_is_move = false;
			}
		}
		else
		{
			SDLCommonFunc::ApplySurface(g_bkground, g_screen, bk_speed_x, 0);
		}
		human_object.Show(g_screen);
		human_object.HandleMove();

		/* Amo process */
		human_object.ProcessAmo(g_screen);
		/* Run threats */
		for (int i = 0; i < NUM_THREATS; i++)
		{
			ThreatsObject* p_threat = (p_threats + i);
			p_threat->Show(g_screen);
			p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_threat->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
		}

		if (SDL_Flip(g_screen) == -1)
			return 0;

	
	}
	delete[] p_threats;
	SDLCommonFunc::CleanUp();
	SDL_Quit();
	return 1;
}
