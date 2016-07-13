typedef struct
{
	char nombre [25];
	int edad;
}ePersona;

typedef struct ArrayList
{
	int reservedSize;			
	int size;					
	void ** pElements;			
		
		int (*len)();
		int (*isEmpty)();
		void (*add)();
		int (*contains)();
		int (*indexof)();
		void (*set)();
		void* (*get)();
		void (*remove)();
		void (*push)();
		void* (*pop)();
		void (*clear)();
		void (*deleteArrayList)();
		

		
		struct ArrayList* (*clone)();
				
				int (*containsAll)();
				struct ArrayList* (*subList)();
}ArrayList;


ArrayList* al_newArrayList(void);


int al_len(ArrayList* self);
int al_isEmpty(ArrayList* self);
void al_add(ArrayList* self, void* element);
int al_contains(ArrayList* self, void* element);
int al_indexOf(ArrayList* self, void* element);
void al_set(ArrayList* self, int index, void* element);
void* al_get(ArrayList* self, int index);
void al_remove(ArrayList* self, int index);
void al_push(ArrayList* self, int index, void* element);
void* al_pop(ArrayList* self, int index);
void al_clear(ArrayList* self);
void al_deleteArrayList(ArrayList*);

void reziseup(ArrayList* self);
void expand(ArrayList* self, int index);
void contract(ArrayList* self, int index);
ArrayList* al_clone(ArrayList* self);

void printArrayListPersonas(ArrayList* lista);
void printPersona(ePersona* p);
