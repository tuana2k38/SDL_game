#ifndef AMO_OBJECT_H
#define AMO_OBJECT_H
#include "BaseObject.h"

#define WIDTH_AMO_LASER 35
#define HEIGHT_AMO_LASER 5
#define WIDTH_AMO_SPHERE 10
#define HEIGHT_AMO_SPHERE 10

class AmoObject : public BaseObject
{
public:
	AmoObject();
	~AmoObject();

	enum AmoType
	{
		NONE,
		LASER,
		SPHERE
	};
	void HandleInputAction(SDL_Event events);
	void HandleMove(const int& x_border, const int& y_border);
	void HandleMoveRtoL();

	int get_type() const { return amo_type_; }
	void set_type(const AmoType& type) { amo_type_ = type; }

	bool get_is_move() const { return is_move_; }
	void set_is_move(bool is_move) { is_move_ = is_move; }
	void SetWidthHeight(const int& width, const int& height) { rect_.w = width; rect_.h = height; }
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	AmoType amo_type_;
};

#endif // !AMO_OBJECT_H


