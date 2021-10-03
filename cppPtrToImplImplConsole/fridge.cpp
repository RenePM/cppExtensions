//**#include "Engine.h"
#include "fridge.h"

class Fridge :: FridgeImpl
{
public:
	void coolDown()
	{
		/* ... */
	}
private:
	int engine_; // the hidden object
};

Fridge::Fridge() : impl_(new FridgeImpl) {}

Fridge::~Fridge()
{
}

void Fridge::coolDown()
{
	impl_->coolDown();
}
