#include "AmoObject.h"

AmoObject::AmoObject()
{
	rect_.x = 0;
	rect_.y = 0;
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
	amo_type_ = NONE;
}

AmoObject::~AmoObject()
{
	;
}

void AmoObject::HandleInputAction(SDL_Event events)
{
}

void AmoObject::HandleMove(const int& x_border, const int& y_border)
{
	rect_.x += 5;
	if (rect_.x > x_border)
	{
		is_move_ = false;
	}
}

void AmoObject::HandleMoveRtoL()
{
	is_move_ = true;
	rect_.x -= 5;
	if (rect_.x < 0)
	{
		is_move_ = false;
	}
}
