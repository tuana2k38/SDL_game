#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include <vector>

#define WIDTH_MAIN_OBJECT 77
#define HEIGHT_MAIN_OBJECT 52

class MainObject:public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleMove();
	void HandleInputAction(SDL_Event events);
	void SetAmoList(std::vector<AmoObject*> amo_list) { p_amo_list = amo_list; }
	std::vector<AmoObject*> GetAmoList() const { return p_amo_list; }
	void ProcessAmo(SDL_Surface* des);
private:
	int x_val_;
	int y_val_;
	std::vector<AmoObject*> p_amo_list;
};

#endif // MAIN_OBJECT_H_


