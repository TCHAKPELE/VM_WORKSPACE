#ifndef DEF_MYCHAINEDSTACK
#define DEF_MYCHAINEDSTACK
#include "mystack.h"

class Mychainedstack : public Mystack{

	public:
		struct list {
			
			int element ;
			list *suivant;
		

		};

	list *base = nullptr;
	void push(int number)override;
	int pop(void)override;
	int operator%(int mod) const override;
	void clear() override;



};

#endif




