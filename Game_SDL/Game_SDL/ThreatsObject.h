#ifndef THREATS_OBJECT_H
#define THREATS_OBJECT_H
#include "Common_Function.h"
#include "BaseObject.h"
#include "AmoObject.h"
#include <vector>

#define WIDHT_THREAT 80
#define HEIGHT_THREAT 33

class ThreatsObject : public BaseObject
{
public:
	ThreatsObject();
	~ThreatsObject();
	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }

	void HandleMove(const int& x_bordr, const int& y_bordr);
	void HandleInputAction(SDL_Event events);
	void InitAmo(AmoObject* p_amo);
	void MakeAmo(SDL_Surface* des, const int& x_limit, const int& y_limit);
	void SetAmoList(std::vector<AmoObject*> amo_list) { p_amo_list = amo_list; }
	std::vector<AmoObject*> GetAmoList() const { return p_amo_list; }
private:
	int x_val_;
	int y_val_;

	std::vector<AmoObject*> p_amo_list;

};
#endif // !THREATS_OBJECT_H
