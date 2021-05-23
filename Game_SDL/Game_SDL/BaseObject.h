#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "Common_Function.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* file_name);

	void SetRect(const int& _x, const int& _y) { rect_.x = _x, rect_.y = _y; }
	SDL_Rect GetRect() const { return rect_; }

private:

protected:
	SDL_Rect  rect_;
	SDL_Surface* p_object_;
};

#endif // !BASE_OBJECT_H



