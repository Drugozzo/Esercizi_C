struct Item{
	int id;
	char *nome,*cognome;
	struct Item *amico;
};

struct binTree{
	struct Item utente;
	struct binTree *l, *r;
};

typedef struct Item Persona;
typedef struct binTree *binTree;

char *ReadWord();

binTree NewNode(binTree root);

binTree InsertUser(binTree root);

void TryInsert(binTree root, Persona u);

void SearchUser(binTree root, int id);
